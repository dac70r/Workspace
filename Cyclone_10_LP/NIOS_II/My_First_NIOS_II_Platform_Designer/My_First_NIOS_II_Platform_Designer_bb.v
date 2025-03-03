
module My_First_NIOS_II_Platform_Designer (
	clk_clk,
	gpio_external_connection_export,
	reset_adc_export,
	spi_0_external_MISO,
	spi_0_external_MOSI,
	spi_0_external_SCLK,
	spi_0_external_SS_n,
	adc_1_spi_external_MISO,
	adc_1_spi_external_MOSI,
	adc_1_spi_external_SCLK,
	adc_1_spi_external_SS_n,
	esc_spi_external_MISO,
	esc_spi_external_MOSI,
	esc_spi_external_SCLK,
	esc_spi_external_SS_n);	

	input		clk_clk;
	output	[7:0]	gpio_external_connection_export;
	output	[7:0]	reset_adc_export;
	input		spi_0_external_MISO;
	output		spi_0_external_MOSI;
	output		spi_0_external_SCLK;
	output		spi_0_external_SS_n;
	input		adc_1_spi_external_MISO;
	output		adc_1_spi_external_MOSI;
	output		adc_1_spi_external_SCLK;
	output		adc_1_spi_external_SS_n;
	input		esc_spi_external_MISO;
	output		esc_spi_external_MOSI;
	output		esc_spi_external_SCLK;
	output		esc_spi_external_SS_n;
endmodule
