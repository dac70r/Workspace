// Module that configures SPI as Slave
		 
		 // Future works: 
		 // 1. Add support for different CPHA and CPOL modes
		 // 2. Rewrite as state machine
		 // 3. Add support for MISO as this is only supporting MOSI (this is slave)	
		 
	module SPI_module (
		 input clk,          								// System clock
		 input rst_n,        								// Active-low reset
		 
		 input sclk,        								 	// SPI clock
		 input ss,           								// Slave select (active-low)
		 input mosi,         								// Master Out Slave In
		 output reg miso,         							// Master In Slave Out
		 
		 output reg [2:0] bit_count=3'b000,     		// Bit counter for each byte of data
		 output reg [2:0] byte_count=3'b000,     		// Byte counter - keep track how many bytes received
		 
		 output reg [1:0] current_state=2'b00,
		 output reg [1:0] next_state=2'b00,
		 
		 output reg [7:0] rx_data, 						// Place holder for a complete byte of data
		 output reg byte_received,								// Assert when receive a complete byte of data
		 output data_transaction_complete,				// Assert when data transaction is complete (all 4 bytes of data received)
		 
		 output reg [7:0] shift_reg,    					// Shift register for MOSI data
		 output sclk_prev,
		 output sclk_rising_edge,
		 
		 output [7:0] memory
	);
	
	// Internal registers	

	reg [7:0] tx_data;       								// Data to send
	reg spi_transaction_start_flag = 0;						// Asserts during the first sclk after ss is pulled low
		 
	// State Machine Logic
	// State encoding
	localparam 	IDLE = 3'b000,
					RECEIVE_BIT = 3'b001,
					STORE_BYTE = 3'b010,
					CHECK_COMPLETE = 3'b011;
	
	 // Clock edge detection for SCLK
    assign sclk_prev = sclk;
    assign sclk_rising_edge = (sclk_prev == 0 && sclk == 1);
	
	// State machine logic
	/*
    always @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			miso <= 1'b0;
			rx_data <= 8'b0;
			tx_data <= 8'b0;	
		end
		end
		*/
	
	/* SPI Receiving Code */
	// Receives 8 bytes of data from Master, each of 8 bits.
	// Config CPOL=1, CPHA=1
	
	always @ (posedge sclk or negedge rst_n) begin
		if(!rst_n) begin
			miso <= 1'b0;
			rx_data <= 8'b0;
			tx_data <= 8'b0;	
		end
		else begin
			byte_received <= 0;
			if(!ss) 
					begin
						// first we want to increment bit_count but if bit_count ==7, we must reset to 0
						shift_reg <= {shift_reg[6:0], mosi}; bit_count <= bit_count + 1;
							if(bit_count == 3'b111) begin
								byte_received <= 1; 
								rx_data <= {shift_reg[6:0], mosi}; // when all 8 bits are received
								byte_count <= byte_count + 1;
								// we also want to increment byte_count but if byte_count ==7, we must reset to 0
								// we also need to add our data into the memory array
								// if(byte_count == 3'b111) begin ; end
							end 
					end
					else
						begin
							bit_count <= 0;
							byte_count <= 0;
						end
			end
		end
	assign memory = (byte_received==1) ? shift_reg : 8'b0000_0000;						  
	//assign byte_received = (bit_count == 3'b111) ? 1 : 0;
	assign data_transaction_complete = (byte_count == 3'b111 && byte_received == 1) ? 1 : 0;

	endmodule
	
	
	/*
				   current_state <= next_state;
				
				if (sclk_rising_edge == 1 && current_state == RECEIVE_BIT) begin
                shift_reg <= {shift_reg[6:0], mosi};
                bit_count <= bit_count + 1;
            end
				
				if (current_state == STORE_BYTE) begin
                rx_data <= shift_reg;
                memory[byte_count] <= shift_reg;
                byte_count <= byte_count + 1;
                bit_count <= 3'b000;
            end
				
				if (current_state == IDLE && ss) begin
					bit_count <= 3'b000;
					byte_count <= 3'b000;
				end 
				
			end
	end

	// Next state logic
    always @(*) 
	 begin
        case (current_state)
            IDLE: begin
                if (!ss) 
						begin next_state = RECEIVE_BIT; end
                else next_state <= IDLE;
            end

            RECEIVE_BIT: begin
                if (bit_count == 3'b111) next_state = STORE_BYTE;
                else next_state = RECEIVE_BIT;
            end

            STORE_BYTE: begin
                if (byte_count == 3'b111) next_state = CHECK_COMPLETE;
                else next_state = RECEIVE_BIT;
            end

            CHECK_COMPLETE: begin
                if (ss) next_state = IDLE;
                else next_state = RECEIVE_BIT;
            end

            default: next_state = IDLE;
        endcase
    end 
	
	
	*/