
module My_First_NIOS_II_Platform_Designer (
	clk_clk,
	esc_spi_external_MISO,
	esc_spi_external_MOSI,
	esc_spi_external_SCLK,
	esc_spi_external_SS_n,
	gpio_external_connection_export);	

	input		clk_clk;
	input		esc_spi_external_MISO;
	output		esc_spi_external_MOSI;
	output		esc_spi_external_SCLK;
	output		esc_spi_external_SS_n;
	output	[7:0]	gpio_external_connection_export;
endmodule
