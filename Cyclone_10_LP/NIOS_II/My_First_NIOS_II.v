
module My_First_NIOS_II(

	input 			CLOCK_50,						// System Clock
	output [7:0] 	LEDG,								// remove in the future
	
	input 			RST_N,					
	input 			ADC1_MISO,						//	ADC1 - MISO
	output			ADC1_MOSI,						// ADC1 - MOSI
	output			ADC1_CLOCK,						//	ADC1 - SCLK
	output			ADC1_SS,							//	ADC1 - Chip Select
	output 			ADC1_RESET,						// ADC1 - Reset
	
	input 			ADC0_MISO,						// ADC0 - MISO
	output			ADC0_MOSI,						// ADC0 - MOSI
	output			ADC0_CLOCK,						// ADC0 - SCLK
	output			ADC0_SS,							// ADC0 - Chip Select
	output 			ADC0_RESET,						// ADC0 - Reset
	
	input 			esc_spi_external_MISO,     // ESC_SPI - MISO      
	output        	esc_spi_external_MOSI,     // ESC_SPI - MISO           
	output        	esc_spi_external_SCLK,     // ESC_SPI - MISO           
	output        	esc_spi_external_SS_n      // ESC_SPI - MISO          	
);

		
My_First_NIOS_II_Platform_Designer u0 (
		.clk_clk (CLOCK_50),   												//			system_clock
		.gpio_external_connection_export(LEDG),						// 		led
		
		.esc_spi_external_MISO(esc_spi_external_MISO),           //			esc_spi_external.MISO
		.esc_spi_external_MOSI(esc_spi_external_MOSI),           //       esc_spi_external.MOSI
		.esc_spi_external_SCLK(esc_spi_external_SCLK),           //       esc_spi_external.SCLK
		.esc_spi_external_SS_n(esc_spi_external_SS_n),           //       esc_spi_external.SS_n       
	); 
	
// Instatiation of SPI Interface
adc_interface adc_uut1 (.system_clock(CLOCK_50),
								.rst_n(RST_N),
								.ADC_SPI_MISO(ADC1_MISO),
								.ADC_SPI_MOSI(ADC1_MOSI),
								.ADC_SPI_SCLK(ADC1_CLOCK),
								.ADC_SPI_CS(ADC1_SS),
								.ADC_RESET(ADC1_RESET)
								);
endmodule