module blinkies (input clk, output [1:0]led);

reg [31:0] count;
reg led_output;

always @ (posedge clk)
begin
	if(count==24_999_999+1)
	begin
		count <= 0;
		led_output <= ~ led_output;
	end
	else
		count <= count + 1;
end 

assign led[0] = led_output;
assign led[1] = ~led_output;

endmodule