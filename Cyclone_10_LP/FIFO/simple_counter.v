module simple_counter(
	input clock,
	output LED
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
	
	assign LED = led_status;
	
endmodule