
/* Description */
/* 

	This file desribes the spi-interface that will connect with ADS131A0x 
	To be used with ADC0 & ADC1

*/

module adc_interface (
	
	input system_clock,									// Direction: Internal, Purpose: System Clock of 50Mhz, 	
	input rst_n,											// Keep? 		
	
	// External Connection Pins to/from hardware ADC/ Sensor
	input  ADC_SPI_MISO,									// Direction: From ADC, Purpose: Data from ADC
	output ADC_SPI_MOSI,									// Direction: Into ADC, Purpose: Data to ADC
	output ADC_SPI_SCLK,									// Direction: Into ADC, Purpose: ADC SPI Clock
	output ADC_SPI_CS,									// Direction: Into ADC, Purpose: ADC Chip Select
	output ADC_RESET,										// Direction: Into ADC, Purpose: ADC Reset
	input SPI_WR_TRIG,
	input SPI_RD_TRIG,
	
	// Internal
	/*
	input SPI_ADDR,										// 
	output SPI_BUSY										// '1' -> SPI wr/rd operation still in progress, '0' -> SPI wr/rd completed	
	*/
	
	// DEBUG 
	output reg [7:0] presentState = 1,
	output reg [7:0] nextState = 1,
	output reg [10:0] delay_counter = 11'b0,		// keeps track of the delay between CS falling edge and rising edge of SCLK
	output reg [8:0]	tx_index	= 9'b0,				// keeps track of the number of bits transmitted
	output reg [8:0]	rx_index = 9'b0,
	output reg  posedge_4mhz = 'd0,					// keeps track of the positive edge count
	output reg  negedge_4mhz = 'd0,					// keeps track of the negative edge count
	output reg  prev_posedge_4mhz = 'd0,			// keeps track of the positive edge count
	output reg  prev_negedge_4mhz = 'd0,			// keeps track of the negative edge count
	output trigger,
	output trigger_1,
	output reg start_tx = 'd0,
	output reg start_rx = 'd0,
	output reg [15:0] rx_buffer 	 = 16'b1111_1111_1111_1111
	);

// Helper Registers
/*
	 reg [7:0] presentState = 1;
	 reg [7:0] nextState = 1;
	 reg [10:0] delay_counter = 11'b0;		// keeps track of the delay between CS falling edge and rising edge of SCLK
	 reg [8:0]	tx_index	= 9'b0;			// keeps track of the number of bits transmitted
	 reg [8:0]  rx_index = 9'b0;
	 reg  posedge_4mhz = 'd0;					// keeps track of the positive edge count
	 reg  negedge_4mhz = 'd0;					// keeps track of the negative edge count
	 reg  prev_posedge_4mhz = 'd0;					// keeps track of the positive edge count
	 reg  prev_negedge_4mhz = 'd0;					// keeps track of the negative edge count
	 //output trigger;
	 //output trigger_1;
	 reg start_tx = 'd0;
	 reg stop_tx = 'd0;
	 reg start_rx = 'd0;
	 reg stop_rx =  'd0; */
	 
// ADC Temp Registers
reg ADC_SPI_SCLK_temp 	= 'd0;							// Temp for ADC_SPI_SCLK				
reg ADC_SPI_MOSI_temp 	= 'd0;
reg ADC_SPI_CS_temp 		= 'd1;
reg SPI_BUSY_temp			= 'd0;

// SPI Command list
localparam SPI_INIT = 16'hff04;							// SPI Initialization Command
reg [15:0] tx_buffer_0 = 16'b1111_1111_0000_0100;	// 0xff04

// Other Registers
reg asserted_low = 'd0;
reg last_bit = 'd0;

  // Definition of State Machine states
  localparam RESET 						= 8'd0;
  localparam IDLE 						= 8'd1;
  localparam WAIT_FOR_RDWR 			= 8'd2;

  localparam WR_ASSERT_CS 				= 8'd3;
  localparam WR_PROCESS 				= 8'd4;
  localparam WR_WAIT_FALLING_1MHZ 	= 8'd5;
  localparam WR_WAIT_DEASSERT_CS 	= 8'd6;
  localparam WR_DEASSERT_CS 			= 8'd7;
  localparam DELAY_1 					= 8'd8;
  
  localparam RD_ASSERT_CS 				= 8'd9;
  localparam RD_PROCESS 				= 8'd10;  // 32 clock write cycles + 32 clock read cycles
  localparam RD_WAIT_FALLING_1MHZ 	= 8'd11;
  localparam RD_WAIT_DEASSERT_CS 	= 8'd12;
  localparam RD_DEASSERT_CS 			= 8'd13;
  localparam DELAY_2						= 8'd14;
 
 // SPI_CLOCK GENERATION Registers 
reg [4:0] counter_adc = 5'd0;
reg spi_clock = 'd0;

integer i, j;

// Creating the SPI Clock of 5MHz
always @ (posedge system_clock)
begin
		if(counter_adc == 4) begin 
				counter_adc <= 0;
				spi_clock <= ~spi_clock;			 
			end
		else begin counter_adc <= counter_adc + 1; end
end

always @ (posedge system_clock) begin
	prev_posedge_4mhz <= posedge_4mhz;
	prev_negedge_4mhz <= negedge_4mhz;
	
	// Detects the Rising Edge of the SPI_Clock
	if((negedge_4mhz == posedge_4mhz) && (prev_negedge_4mhz!=negedge_4mhz || prev_posedge_4mhz!=posedge_4mhz)) begin
		if (start_tx && start_rx) begin 
			// this state should not be reached!
			tx_index <= 999; //error
		end
		
		else if(start_tx)
			begin		
					if(tx_index<=15) begin
						ADC_SPI_SCLK_temp <= 'd1;
						ADC_SPI_MOSI_temp <= tx_buffer_0[15-tx_index];
						tx_index <= tx_index + 1; 
					end
			end
		
		else if(start_rx)
			begin
					if(rx_index<=15) begin
						ADC_SPI_SCLK_temp <= 'd1;
						rx_buffer[15-rx_index] <= ADC_SPI_MISO; 
						rx_index <= rx_index + 1; 
					end
			end
		
		else begin
			tx_index 			<= 'd0;
			rx_index				<= 'd0;
			ADC_SPI_SCLK_temp <= 'd0; 
			ADC_SPI_MOSI_temp <= 'd0;
			
		end
	end
	
	// Detects the Falling Edge of the SPI_Clock
	else if((negedge_4mhz != posedge_4mhz) && (prev_negedge_4mhz != negedge_4mhz || prev_posedge_4mhz != posedge_4mhz)) begin
		// Condition 1: While start_tx is TRUE, still transmitting, so during falling edge, we assert SCLK to be LOW
		// Condition 2: While tx_index is 8, completed transmission, so during falling edgem we assert SCLK to be LOW
		if(start_tx || tx_index==16) begin 
			ADC_SPI_SCLK_temp <= 'd0; 
		end
		// Condition 1: While start_tx is TRUE, still transmitting, so during falling edge, we assert SCLK to be LOW
		// Condition 2: While tx_index is 8, completed transmission, so during falling edgem we assert SCLK to be LOW
		else if (start_rx || rx_index==16) begin 
			ADC_SPI_SCLK_temp <= 'd0; 
		end
	end
end

assign trigger = ((negedge_4mhz == posedge_4mhz) && (prev_negedge_4mhz!=negedge_4mhz || prev_posedge_4mhz!=posedge_4mhz));
assign trigger_1 = ((negedge_4mhz != posedge_4mhz) && (prev_negedge_4mhz != negedge_4mhz || prev_posedge_4mhz != posedge_4mhz));
	
  // State Machine Operation - Signal Assertion 
	always @ (posedge system_clock) begin
		delay_counter <= delay_counter;
		start_tx <= start_tx;
		case (presentState)
			RESET: begin
					ADC_SPI_CS_temp 		<= 'd1; 
					SPI_BUSY_temp 			<= 'd0;
				end
			IDLE: begin
					ADC_SPI_CS_temp 		<= 'd1; 
					SPI_BUSY_temp 			<= 'd0;
				end
			WAIT_FOR_RDWR: begin 
					ADC_SPI_CS_temp 		<= 'd1; 
					SPI_BUSY_temp 			<= 'd0; 
					delay_counter 			<= 'd0;
				end
			WR_ASSERT_CS: 
				begin
					ADC_SPI_CS_temp 		<= 'd0; 			// Asserts CS
					delay_counter 			<= delay_counter + 1;
				end
			WR_PROCESS: begin  
					ADC_SPI_CS_temp 		<= 'd0; 
					start_tx 				<= 'd1;  		// Trigger SPI_SCLK Generation
					delay_counter			<= 'd0; 			// Resets counter
				end
			WR_WAIT_FALLING_1MHZ: begin
				  //spi_busy_temp <= 'd1;
				  //spi_rd_data_temp <= 'd0;
				  ADC_SPI_CS_temp 		<= 'd0; 
				  start_tx <= 'd0;  // Reset trigger
				end
			WR_WAIT_DEASSERT_CS: begin
					ADC_SPI_CS_temp 		<= 'd0; 
					delay_counter 			<= delay_counter + 1;
				end
			WR_DEASSERT_CS: begin 
					start_tx					<= 'd0;
					ADC_SPI_CS_temp 		<= 'd1; 
					delay_counter 			<= delay_counter + 1;
				end
			DELAY_1: begin
					start_tx 				<= 'd0;
					ADC_SPI_CS_temp 		<= 'd1;
					delay_counter 			<= delay_counter + 1;
				end
			RD_ASSERT_CS: begin
					ADC_SPI_CS_temp 		<= 'd0; 			// Asserts CS
					delay_counter 			<= delay_counter + 1;
				end
			RD_PROCESS: begin 
					ADC_SPI_CS_temp 		<= 'd0; 
					start_rx 				<= 'd1;  		// Trigger SPI_SCLK Generation
					delay_counter			<= 'd0; 			// Resets counter
				end
			RD_WAIT_FALLING_1MHZ: begin 
					ADC_SPI_CS_temp 		<= 'd0; 
					start_rx 				<= 'd0;  // Reset trigger
				end
			RD_WAIT_DEASSERT_CS: begin
					ADC_SPI_CS_temp 		<= 'd0; 
					delay_counter 			<= delay_counter + 1;
				end
			RD_DEASSERT_CS: begin
					ADC_SPI_CS_temp 		<= 'd1; 
					delay_counter 			<= delay_counter + 1;
				end
			DELAY_2: begin
				start_tx 					<= 'd0;
				ADC_SPI_CS_temp 			<= 'd1;
				delay_counter 				<= delay_counter + 1;
			end
			default: begin
					start_tx 				<= 'd0;
					ADC_SPI_CS_temp 		<= 'd1;
				end
		endcase	
	end
	
	// State Machine Next State Transition Logic
  always @(posedge system_clock, negedge rst_n) begin
    if (!rst_n) begin
      presentState <= RESET;
    end else begin
      presentState <= nextState;
    end
  end
  
	// State Machine Transition Logic - Dictatates the conditions of State Transition
	always @ (*) begin
		case (presentState)
			RESET: begin
					nextState = IDLE;
				end
			IDLE: begin
					nextState = WAIT_FOR_RDWR;
				end
			WAIT_FOR_RDWR: begin
					if(1/*SPI_WR_TRIG*/) begin nextState = WR_ASSERT_CS; end
					//else if(SPI_RD_TRIG) begin nextState = RD_ASSERT_CS; end
					else begin nextState = WAIT_FOR_RDWR; end
				end
			WR_ASSERT_CS: begin 
					if(delay_counter == 5) // Min 16ns delay
						nextState = WR_PROCESS;
					else
						nextState = WR_ASSERT_CS;
				end
			WR_PROCESS: begin 
					if(tx_index == 16) begin nextState = WR_WAIT_FALLING_1MHZ; end
					else nextState = WR_PROCESS;
				end
			WR_WAIT_FALLING_1MHZ: begin
					if (!ADC_SPI_SCLK_temp) nextState = WR_WAIT_DEASSERT_CS;
					else nextState = WR_WAIT_FALLING_1MHZ;
				end
			WR_WAIT_DEASSERT_CS: begin
					if (delay_counter >= 'd5)  // Min 100ns
						nextState = WR_DEASSERT_CS;
					else nextState = WR_WAIT_DEASSERT_CS;
				end
			WR_DEASSERT_CS: begin
					if (delay_counter >= 'd15)  // Min 100ns
						nextState = DELAY_1;	
					else nextState = WR_DEASSERT_CS;
				end
			DELAY_1: begin
				// Introduce delay before next operation
				if(delay_counter >= 'd25)
					nextState = RD_ASSERT_CS; 										//WAIT_FOR_RDWR; modified
				else	nextState = DELAY_1;
			end
			RD_ASSERT_CS: begin
					if(delay_counter >= 'd30) // Min 16ns delay
						nextState = RD_PROCESS;
					else
						nextState = RD_ASSERT_CS;
				end
			RD_PROCESS: begin 
					if(rx_index == 16) begin nextState = RD_WAIT_FALLING_1MHZ; end
					else nextState = RD_PROCESS;
				end
			RD_WAIT_FALLING_1MHZ: begin
					if (!ADC_SPI_SCLK_temp) nextState = RD_WAIT_DEASSERT_CS;
					else nextState = RD_WAIT_FALLING_1MHZ;
				end
			RD_WAIT_DEASSERT_CS:begin
					if (delay_counter >= 'd5)
						nextState = RD_DEASSERT_CS;
					else
						nextState = RD_WAIT_DEASSERT_CS;
				end
			RD_DEASSERT_CS:	begin
					if (delay_counter >= 'd15)  // Min 100ns
						nextState = DELAY_2;	
					else nextState = RD_DEASSERT_CS;
				end
			DELAY_2: begin
					// Introduce delay before next operation
					if(delay_counter >= 'd25) 
						nextState = WAIT_FOR_RDWR; 										
					else	nextState = DELAY_2;
				end	
			default: begin
					nextState = WAIT_FOR_RDWR;
				end
			endcase	
	end	
	

	always @(posedge spi_clock) begin
		posedge_4mhz <= ~posedge_4mhz;
	 end

	 always @(negedge spi_clock) begin
		negedge_4mhz <= ~negedge_4mhz;
	 end
  
  
	assign ADC_SPI_SCLK = ADC_SPI_SCLK_temp;
	assign ADC_SPI_MOSI = ADC_SPI_MOSI_temp;
	assign ADC_SPI_CS = ADC_SPI_CS_temp;
	assign SPI_BUSY = SPI_BUSY_temp;
	
endmodule