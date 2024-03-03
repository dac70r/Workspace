module simple_counter(
	input clock,
	output [3:0] LED
);


reg [22:0] counter_out; 
reg led_status;

always @ (posedge clock)
	begin
		counter_out <= counter_out + 1;
		if(counter_out==2_499_999)
		begin
			counter_out <= 0;
			led_status <= ~led_status;
		end
	end
	
	assign LED[0] = led_status;
	assign LED[1] = led_status;
	assign LED[2] = ~led_status;
	assign LED[3] = ~led_status;
	
endmodule