
module PLL_complete (
	clk_clk,
	reset_reset_n,
	to_outside_led,
	to_outside_1_led,
	to_outside_2_led,
	altpll_0_locked_conduit_export);	

	input		clk_clk;
	input		reset_reset_n;
	output		to_outside_led;
	output		to_outside_1_led;
	output		to_outside_2_led;
	output		altpll_0_locked_conduit_export;
endmodule
