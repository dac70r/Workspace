// Sample for Blinky Project

module PLL_Platform_Desginer (input clock, input resetn, output LED);

reg [12:0] count =0;
reg led_output =0;

always @ (posedge clock)
begin
	if(!resetn)
	begin
		count <= 0;
	end
	else
		begin
			count <= count + 1;
			if(count == 5_000)
			begin
				count <= 0;
				led_output <= ~led_output;
			end
		end
end

assign LED = led_output;

endmodule