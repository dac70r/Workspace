`timescale 1ns / 1ps 

module tb_adc_interface;

reg system_clock;
reg rst_n;

reg  ADC_SPI_MISO;									// Direction: From ADC, Purpose: Data from ADC
wire ADC_SPI_MOSI;									// Direction: Into ADC, Purpose: Data to ADC
wire ADC_SPI_SCLK;									// Direction: Into ADC, Purpose: ADC SPI Clock
wire ADC_SPI_CS;									// Direction: Into ADC, Purpose: ADC Chip Select
wire ADC_RESET;


//reg SPI_WR_TRIG;									// Direction: Internal, Purpose: 
/*
reg SPI_ADDR;										// 
reg SPI_RD_TRIG;									// Direction: Internal, Purpose: 
wire SPI_BUSY;										// '1' -> SPI wr/rd operation still in progress, '0' -> SPI wr/rd completed
*/		
			/**/
reg [7:0] presentState;
reg [7:0] nextState;		
reg [10:0] delay_counter;
reg [8:0]	tx_index	= 9'b0;
reg  posedge_4mhz = 'd0;
reg  negedge_4mhz = 'd0;
reg  prev_posedge_4mhz = 'd0;					// keeps track of the positive edge count
reg  prev_negedge_4mhz = 'd0;					// keeps track of the negative edge count
wire  trigger;
wire 	trigger_1;
reg start_tx = 'd0;
reg stop_tx = 'd0; 

adc_interface adc_int1 (.*);

initial begin
	system_clock = 0; 
    forever begin
      #10 system_clock = ~system_clock;  
	 end
end



endmodule