


module Timer(

	input CLOCK_50,
	output LEDG
);


my_timer u0 (
		.clk_clk    (CLOCK_50),    // clk.clk
		.led_export (LEDG)  // led.export
	);


endmodule

