// Module that configures SPI as Slave
		 
		 // Future works: 
		 // 1. Add support for different CPHA and CPOL modes
		 // 2. Rewrite as state machine
		 // 3. Add support for MISO as this is only supporting MOSI (this is slave)	
		 
	module SPI_module (
		 input clk,          								// System clock
		 input rst_n,        								// Active-low reset
		 
		 input spi_start,										// Starts the SPI Transmission
		 input sclk,        								 	// SPI clock
		 input ss,           								// Slave select (active-low)
		 input mosi,         								// Master Out Slave In
		 output reg miso,         							// Master In Slave Out
		 
		 output reg [2:0] bit_count=3'b000,     		// Bit counter for each byte of data 						-debug 
		 output reg [2:0] byte_count=3'b000,     		// Byte counter - keep track how many bytes received 	-debug 
		 
		 output reg [1:0] current_state=2'b00,			// not in use 														-debug 
		 output reg [1:0] next_state=2'b00,				// not in use 														-debug 
		 
		 output reg [7:0] rx_data, 						// Place holder for a complete byte of data 				-debug 
		 output reg byte_received,							// Assert when receive a complete byte of data 			-debug 
		 output data_transaction_complete,				// Assert when data transaction is complete (all 4 bytes of data received) -debug 
		 
		 output reg [7:0] shift_reg,    					// Shift register for MOSI data								-debug 
		 output sclk_prev,									//																		-debug 
		 output sclk_rising_edge,							//																		-debug 
		 
		 output [7:0] memory,								//																		-debug 
		 output reg lagged_clock							//																		-debug 
	);
	
	// Internal Memory for Storing the Data Received
	reg [7:0] storage [7:0]; 
	reg [7:0] data_to_transmit = 8'b1010_0011; 
	
	/* SPI Receiving Code */
	// Receives 8 bytes of data from Master, each of 8 bits.
	// Config CPOL=1, CPHA=1
	// This block of code identifies when the 
	always @ (posedge clk) begin
		lagged_clock <= sclk;
	end
	
	always @ (posedge sclk or negedge rst_n) begin
		if(!rst_n) begin
			miso <= 1'b0;
			rx_data <= 8'b0;
		end
		else begin
			byte_received <= 0;
			if(!ss) 
					begin
						// first we want to increment bit_count but if bit_count ==7, we must reset to 0
						if(sclk==1 && lagged_clock==0) begin
							shift_reg <= {shift_reg[6:0], mosi}; bit_count <= bit_count + 1;
							if(bit_count == 3'b111) begin
								byte_received <= 1; 
								rx_data <= {shift_reg[6:0], mosi}; // when all 8 bits are received
								storage[byte_count] <= {shift_reg[6:0], mosi};
								byte_count <= byte_count + 1;
								// we also want to increment byte_count but if byte_count ==7, we must reset to 0
								// we also need to add our data into the memory array
								// if(byte_count == 3'b111) begin ; end
							end
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

// Below is when SPI is configured as a slave
/*------------------------------------------------------------
if(start) begin 
// Begin transmission when 'start' is asserted
//cs <= 1'b0;           // Assert chip select (CS active low)
data_reg <= data_in;  // Store the input data
shift_reg <= data_in; // Load shift register with input data
receive_reg <= 8'b00000000;  // Clear receive register
bit_count <= 3'b000;   // Reset bit count to 0
done <= 1'b0; 
end
/*------------------------------------------------------------*/