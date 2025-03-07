
module My_First_NIOS_II(

	input 			CLOCK_50,
	output [7:0] 	LEDG,
	output [7:0] 	RESET_ADC,
	input 			SPI_MISO,
	output 			SPI_MOSI,
	output 			SPI_CLOCK,
	output 			SPI_SS
);

// Placeholder signals for now
reg 			esc_spi_external_MISO;           //         esc_spi_external.MISO
reg        	esc_spi_external_MOSI;           //                         .MOSI
reg        	esc_spi_external_SCLK;           //                         .SCLK
reg        	esc_spi_external_SS_n;           //                         .SS_n
reg         adc_1_spi_external_MISO;         //       adc_1_spi_external.MISO
reg        	adc_1_spi_external_MOSI;         //                         .MOSI
reg       	adc_1_spi_external_SCLK;         //                         .SCLK
reg        	adc_1_spi_external_SS_n;         //                         .SS_n
		
My_First_NIOS_II_Platform_Designer u0 (
		.clk_clk (CLOCK_50),   
		.gpio_external_connection_export(LEDG),			// led
		.reset_adc_export(RESET_ADC),                	// 
		.spi_0_external_MISO(SPI_MISO),             		// spi_0_external.MISO
		.spi_0_external_MOSI(SPI_MOSI),             		// spi_0_external.MOSI
		.spi_0_external_SCLK(SPI_CLOCK),             	// spi_0_external.SCLK
		.spi_0_external_SS_n(SPI_SS),              		// spi_0_external.SS
		.esc_spi_external_MISO(esc_spi_external_MISO),           //         esc_spi_external.MISO
		.esc_spi_external_MOSI(esc_spi_external_MOSI),           //                         .MOSI
		.esc_spi_external_SCLK(esc_spi_external_SCLK),           //                         .SCLK
		.esc_spi_external_SS_n(esc_spi_external_SS_n),           //                         .SS_n
		.adc_1_spi_external_MISO(adc_1_spi_external_MISO),         //       adc_1_spi_external.MISO
		.adc_1_spi_external_MOSI(adc_1_spi_external_MOSI),         //                         .MOSI
		.adc_1_spi_external_SCLK(adc_1_spi_external_SCLK),         //                         .SCLK
		.adc_1_spi_external_SS_n(adc_1_spi_external_SS_n)         //                         .SS_n
	);

endmodule