module hello_world(
	// reset and clock
		input clock,
		input reset,
		
	// LED and push button
		output [3:0] LED,
		input [3:0] button

);

		assign LED[1:0] = ~button [1:0];
		
NIOS_II u0 (
		.clk_clk                          (clock),                          //                       clk.clk
		.reset_reset_n                    (reset),                    		  //                     reset.reset_n
		.pio_0_external_connection_export (button[3:2]), 						  // pio_0_external_connection.export
		.pio_1_external_connection_export (LED[3:2])  					   	  // pio_1_external_connection.export
	);

endmodule