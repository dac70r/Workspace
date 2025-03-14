
module My_First_NIOS_II(

	input 			CLOCK_50,						// System Clock
	output [7:0] 	LEDG,								// remove in the future
	
	output [7:0] 	RESET_ADC,						// remove in the future
	
	input 			RST_N,
	input 			SPI_WR_TRIG, 					
	input 			ADC1_MISO,						//	ADC1 - MISO
	output			ADC1_MOSI,						// ADC1 - MOSI
	output			ADC1_CLOCK,						//	ADC1 - SCLK
	output			ADC1_SS,							//	ADC1 - Chip Select
	output 			ADC1_RESET,						// ADC1 - Reset
	
	input 			SPI_MISO,						// ADC0 - MISO
	output 			SPI_MOSI,						// ADC0 - MOSI
	output 			SPI_CLOCK,						// ADC0 - SCLK
	output 			SPI_SS,							// ADC0 - Chip Select
	output 			ADC0_RESET,						// ADC0 - Reset
	
	input 			esc_spi_external_MISO,     // ESC_SPI - MISO      
	output        	esc_spi_external_MOSI,     // ESC_SPI - MISO           
	output        	esc_spi_external_SCLK,     // ESC_SPI - MISO           
	output        	esc_spi_external_SS_n      // ESC_SPI - MISO          	
);

		/*
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
		
		.adc_1_spi_external_MISO(ADC1_MISO),         
		.adc_1_spi_external_MOSI(ADC1_MOSI),         
		.adc_1_spi_external_SCLK(ADC1_CLOCK),         
		.adc_1_spi_external_SS_n(ADC1_SS)         
	); */

// Instatiation of SPI Interface
adc_interface adc_uut1 (.system_clock(CLOCK_50),
								.rst_n(RST_N),
								.ADC_SPI_MISO(ADC1_MISO),
								.ADC_SPI_MOSI(ADC1_MOSI),
								.ADC_SPI_SCLK(ADC1_CLOCK),
								.ADC_SPI_CS(ADC1_SS),
								.ADC_RESET(ADC1_RESET),
								.SPI_WR_TRIG(SPI_WR_TRIG)
								);
endmodule