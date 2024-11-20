


module Timer(

	input CLOCK_50,
	input RESET,
	output LEDG
);


my_timer u0 (
		.clk_clk    (CLOCK_50),    // clk.clk
		.reset_reset_n (RESET), 	// reset.reset_n
		.led_export (LEDG)  			// led.export
	);


endmodule

