


module My_First_NIOS_II(

	input CLOCK_50,
	input RESET,
	
	output [7:0] LEDG
);

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

My_First_NIOS_II_Platform_Designer u0 (
		.clk_clk (CLOCK_50),  									// clk.clk
		.gpio_external_connection_export(LEDG)				// led	
	);

endmodule

