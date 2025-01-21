// MOdule that configures SPI as Slave

module SPI (
    input clk,          						// System clock
    input rst_n,        						// Active-low reset
	 
    input sclk,         						// SPI clock
    input ss,           						// Slave select (active-low)
    input mosi,         						// Master Out Slave In
    output miso,         						// Master In Slave Out
	
	 output [7:0] rx_data, 						// Received data
	 output [2:0] debug_bit_count, 
	 output [2:0] debug_byte_count,
	 output [1:0] debug_current_state,
	 output [1:0] debug_next_state,
	 
	 output byte_received, 						// Received data
	 output data_transaction_complete,
	 output led,
	 output led1,
	 output led2,
	 output led3,
	 output debug_ss,
	 
	 output [7:0] shift_reg,  
	 output sclk_prev,
	 output sclk_rising_edge,
	 output [7:0] memory
);
 
wire c0,c1,c2,c3;			// clk outputs from the clk module
	 
	// Instantiate clocks
	clock my_clock(
				.inclk0(clk),
				.c0(c0),   // 50MHz 50% Duty Cycle
				.c1(c1),   // 25MHz 50% Duty Cycle
				.c2(c2),   // 10MHz 50% Duty Cycle
				.c3(c3)    // 1MHz 50% Duty Cycle
	);
	
	// Instantiate Heartbeat LED
	Blinky uut (		
					.clk(c1),  				// 25 MHz
					.led(led), 				// 1 Hz
	);
	
	assign led1 = c1;						// led running at 25M
	assign led2 = c2;						// led running at 10M
	assign led3 = c3;						// led running at 1M
	
	/*
	debounced_signal(
    .clk(c0),
    .incoming_signal(ss),
    .outgoing_signal(led1)
    );
	 */
	
	// Instantiate SPI_Module for Comms with Microcontroller
	SPI_module my_spi_module (
    .clk(c1),          																// System clock      					25MHz
    .rst_n(rst_n),        															// Active-low reset
	 
    .sclk(sclk),         															// SPI clock							1.34375MHz 
    .ss(ss),           																// Slave select (active-low)		
    .mosi(mosi),         															// Master Out Slave In
    .miso(miso),         															// Master In Slave Out
	 .bit_count(debug_bit_count),		
	 .byte_count(debug_byte_count),
	 .current_state(debug_current_state),
	 .next_state(debug_next_state),
	 .rx_data(rx_data), 																// Received data
	 .byte_received(byte_received), 												// Received data
	 .data_transaction_complete(data_transaction_complete),				// Completed Transaction
	 .shift_reg(shift_reg),    													// Shift register for MOSI data
	 .sclk_prev(sclk_prev),
	 .sclk_rising_edge(sclk_rising_edge),
	 .memory(memory)
);

assign debug_ss = ~ss; 				// used for better visualiztion of the start and stop of SPI Transaction


endmodule
