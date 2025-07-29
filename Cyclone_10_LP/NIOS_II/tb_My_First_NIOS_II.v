`timescale 1ns/1ps

module tb_My_First_NIOS_II();

	reg 			CLOCK_50;
	wire [7:0] 	LEDG;
	wire [7:0] 	RESET_ADC;
	reg 			SPI_MISO;
	wire 			SPI_MOSI;
	wire 			SPI_CLOCK;
	wire 			SPI_SS;
	
	My_First_NIOS_II uut (
		.CLOCK_50(CLOCK_50),
		.LEDG(LEDG),
		.RESET_ADC(RESET_ADC),
		.SPI_MISO(SPI_MISO),
		.SPI_MOSI(SPI_MOSI),
		.SPI_CLOCK(SPI_CLOCK),
		.SPI_SS(SPI_SS)
	);
	
	
	// Test stimulus (testbench block)
	always begin
		#5 CLOCK_50 = ~CLOCK_50;
	end
	 
endmodule
	