	PLL_complete u0 (
		.clk_clk                        (<connected-to-clk_clk>),                        //                     clk.clk
		.reset_reset_n                  (<connected-to-reset_reset_n>),                  //                   reset.reset_n
		.to_outside_led                 (<connected-to-to_outside_led>),                 //              to_outside.led
		.to_outside_1_led               (<connected-to-to_outside_1_led>),               //            to_outside_1.led
		.to_outside_2_led               (<connected-to-to_outside_2_led>),               //            to_outside_2.led
		.altpll_0_locked_conduit_export (<connected-to-altpll_0_locked_conduit_export>)  // altpll_0_locked_conduit.export
	);

