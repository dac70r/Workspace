
module spi_4wire_platform_designer (
	clk_clk,
	reset_reset_n,
	spi_0_external_MISO,
	spi_0_external_MOSI,
	spi_0_external_SCLK,
	spi_0_external_SS_n);	

	input		clk_clk;
	input		reset_reset_n;
	input		spi_0_external_MISO;
	output		spi_0_external_MOSI;
	output		spi_0_external_SCLK;
	output		spi_0_external_SS_n;
endmodule
