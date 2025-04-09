

module SPI_4Wire(
	input clock,
	input reset_reset_n
	
	

);

module spi_4wire_platform_designer (
		input  wire  clk_clk,             //            clk.clk
		input  wire  reset_reset_n,       //          reset.reset_n
		input  wire  spi_0_external_MISO, // spi_0_external.MISO
		output wire  spi_0_external_MOSI, //               .MOSI
		output wire  spi_0_external_SCLK, //               .SCLK
		output wire  spi_0_external_SS_n  //               .SS_n
	);

endmodule