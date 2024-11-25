module simple_counter_2(
	input clock_2,
	output LED_2
);


reg [26:0] counter_out = 0; 
reg led_status = 0;

always @ (posedge clock_2)
	begin
		counter_out <= counter_out + 1;
		if(counter_out==24_999_99/2)
		begin
			counter_out <= 0;
			led_status <= ~led_status;
		end
	end
	
	assign LED_2 = led_status;
	
endmodule