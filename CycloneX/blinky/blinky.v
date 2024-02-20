module blinky(input clk, output [1:0]led);

reg [26:0] count;
reg led_output;

always @ (posedge clk)
begin
	if(count==49_999_999)
	begin
		count <= 0;
		led_output <= ~ led_output;
	end
	else
		count <= count + 1;
end 
assign led[0] = led_output;
assign led[1] = led_output;

endmodule