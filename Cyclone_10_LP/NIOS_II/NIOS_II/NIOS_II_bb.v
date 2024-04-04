
module NIOS_II (
	clk_clk,
	reset_reset_n,
	pio_0_external_connection_export,
	pio_1_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	input	[1:0]	pio_0_external_connection_export;
	output	[1:0]	pio_1_external_connection_export;
endmodule
