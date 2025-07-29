
module My_First_NIOS_II(

	input 			CLOCK_50,						// System Clock
	output [7:0] 	LEDG,								// remove in the future
	
	input 			ESC_EEPDONE,
	input 			RST_N,					

	input 			ADC0_MISO,						// ADC0 - MISO
	output			ADC0_MOSI,						// ADC0 - MOSI
	output			ADC0_CLOCK,						// ADC0 - SCLK
	output			ADC0_SS,							// ADC0 - Chip Select
	output 			ADC0_RESET,						// ADC0 - Reset
	
	input 			ADC1_MISO,						//	ADC1 - MISO
	output			ADC1_MOSI,						// ADC1 - MOSI
	output			ADC1_CLOCK,						//	ADC1 - SCLK
	output			ADC1_SS,							//	ADC1 - Chip Select
	output 			ADC1_RESET,						// ADC1 - Reset
	
	input 			ADC2_MISO,						// ADC2 - MISO
	output			ADC2_MOSI,						// ADC2 - MOSI
	output			ADC2_CLOCK,						// ADC2 - SCLK
	output			ADC2_SS,							// ADC2 - Chip Select
	output 			ADC2_RESET,						// ADC2 - Reset
	
	input 			ADC3_MISO,						//	ADC3 - MISO
	output			ADC3_MOSI,						// ADC3 - MOSI
	output			ADC3_CLOCK,						//	ADC3 - SCLK
	output			ADC3_SS,							//	ADC3 - Chip Select
	output 			ADC3_RESET,						// ADC3 - Reset
	
	input 			esc_spi_external_MISO,     // ESC_SPI - MISO      
	output        	esc_spi_external_MOSI,     // ESC_SPI - MISO           
	output        	esc_spi_external_SCLK,     // ESC_SPI - MISO           
	output        	esc_spi_external_SS_n,     // ESC_SPI - MISO 
	output 			esc_spi_external_SS_n_actual, // use this to control the CS pin

	output	[15:0] rx_buffer_adc0,
	output	[15:0] rx_buffer_adc1,
	output	[15:0] rx_buffer_adc2,
	output	[15:0] rx_buffer_adc3,
	
	output 			LED_TESTER
);

wire ground; 

// Instantiation of NIOS Softcore 
My_First_NIOS_II_Platform_Designer u0 (
		.clk_clk (CLOCK_50),   												//			system_clock
		.esc_spi_cs_manual_export(esc_spi_external_SS_n_actual), 		 	//     esc_eepdone_external.export
		.gpio_external_connection_export(LEDG),						// 		led
		.esc_eepdone_external_export(ESC_EEPDONE),					//			esc_eepdone
		.esc_spi_external_MISO(esc_spi_external_MISO),           //			esc_spi_external.MISO
		.esc_spi_external_MOSI(esc_spi_external_MOSI),           //       esc_spi_external.MOSI
		.esc_spi_external_SCLK(esc_spi_external_SCLK),           //       esc_spi_external.SCLK
		.esc_spi_external_SS_n(esc_spi_external_SS_n)        		//       esc_spi_external.SS_n       
);

// Instatiation of SPI Interfaces
adc_interface adc_uut0 (.system_clock(CLOCK_50),					// ADC0
								.rst_n(RST_N),
								.ADC_SPI_MISO(ADC0_MISO),
								.ADC_SPI_MOSI(ADC0_MOSI),
								.ADC_SPI_SCLK(ADC0_CLOCK),
								.ADC_SPI_CS(ADC0_SS),
								.ADC_RESET(ADC0_RESET),
								.rx_buffer(rx_buffer_0)
								);
								
adc_interface adc_uut1 (.system_clock(CLOCK_50),					// ADC1
								.rst_n(RST_N),
								.ADC_SPI_MISO(ADC1_MISO),
								.ADC_SPI_MOSI(ADC1_MOSI),
								.ADC_SPI_SCLK(ADC1_CLOCK),
								.ADC_SPI_CS(ADC1_SS),
								.ADC_RESET(ADC1_RESET),
								.rx_buffer(rx_buffer_1)
								);
								
adc_interface adc_uut2 (.system_clock(CLOCK_50),					// ADC2
								.rst_n(RST_N),
								.ADC_SPI_MISO(ADC2_MISO),
								.ADC_SPI_MOSI(ADC2_MOSI),
								.ADC_SPI_SCLK(ADC2_CLOCK),
								.ADC_SPI_CS(ADC2_SS),
								.ADC_RESET(ADC2_RESET),
								.rx_buffer(rx_buffer_2)
								);
								
adc_interface adc_uut3 (.system_clock(CLOCK_50),					// ADC3
								.rst_n(RST_N),
								.ADC_SPI_MISO(ADC3_MISO),
								.ADC_SPI_MOSI(ADC3_MOSI),
								.ADC_SPI_SCLK(ADC3_CLOCK),
								.ADC_SPI_CS(ADC3_SS),
								.ADC_RESET(ADC3_RESET),
								.rx_buffer(rx_buffer_3)
								);
								
assign LED_TESTER = esc_spi_external_SS_n_actual;
endmodule