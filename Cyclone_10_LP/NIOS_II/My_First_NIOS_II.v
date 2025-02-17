


module My_First_NIOS_II(

	input 			CLOCK_50,
	output [7:0] 	LEDG,
	output [7:0] 	RESET_ADC,
	input 			SPI_MISO,
	output 			SPI_MOSI,
	output 			SPI_CLOCK,
	output 			SPI_SS
	
);

My_First_NIOS_II_Platform_Designer u0 (
		.clk_clk (CLOCK_50),   
		.gpio_external_connection_export(LEDG),			// led
		.reset_adc_export(RESET_ADC),                	// 
		.spi_0_external_MISO(SPI_MISO),             		// spi_0_external.MISO
		.spi_0_external_MOSI(SPI_MOSI),             		// spi_0_external.MOSI
		.spi_0_external_SCLK(SPI_CLOCK),             	// spi_0_external.SCLK
		.spi_0_external_SS_n(SPI_SS)              		// spi_0_external.SS
	);

endmodule


/*2
reg [31:0] count = 0;
reg 		  LEDG_Stat = 0;

always @ (posedge CLOCK_50)
begin
	if(count >= 50_000_000)
	begin
		count <= 0;
		LEDG_Stat <= !LEDG_Stat;
	end
	else
	begin
		count <= count + 1;
	end
end

assign LEDG[3] = LEDG_Stat;
*/