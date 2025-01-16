// Sample for Blinky Project
module Blinky (input clk, output led);

reg [31:0] count =0;
reg led_output =0;

always @ (posedge clk)
begin
	if(count == 12_499_999)
		begin
			count <= 0;
			led_output <= ~led_output;
		end
	else
		begin
			count <= count + 1;
		end
end  

assign led = led_output;


endmodule