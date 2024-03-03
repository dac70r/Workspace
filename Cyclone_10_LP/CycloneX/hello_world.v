module  hello_world (
	
	// Reset and Clocks
	input              SYS_CLK50M,
   input              RESET_EXPN,

	// LED and Push Button
	output    [3:0]    USER_LED,
	input     [3:0]    PB
	
	 );
	 
	 assign USER_LED[1:0] = ~PB[1:0];
	 
	 nios_setup u0 (
		 .clk_clk                                (SYS_CLK50M), 
       .switch_external_connection_export      (PB[3:2]), //push button		 
		 .reset_reset_n                          (RESET_EXPN),	 
		 .led_external_connection_export         (USER_LED[3:2]) //led
	 );
	 
endmodule
