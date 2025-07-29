
module spi_platform_designer (
	clk_clk,
	esc_spi_eepdone_export_export,
	esc_spi_export_MISO,
	esc_spi_export_MOSI,
	esc_spi_export_SCLK,
	esc_spi_export_SS_n,
	esc_spi_ss_export_export,
	reset_reset_n,
	spi_adc_reset_export_export,
	spi_export_MISO,
	spi_export_MOSI,
	spi_export_SCLK,
	spi_export_SS_n);	

	input		clk_clk;
	input		esc_spi_eepdone_export_export;
	input		esc_spi_export_MISO;
	output		esc_spi_export_MOSI;
	output		esc_spi_export_SCLK;
	output		esc_spi_export_SS_n;
	output		esc_spi_ss_export_export;
	input		reset_reset_n;
	output		spi_adc_reset_export_export;
	input		spi_export_MISO;
	output		spi_export_MOSI;
	output		spi_export_SCLK;
	output		spi_export_SS_n;
endmodule
