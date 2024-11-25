// Sample for Blinky Project
module blinky (input CLOCK_100Mhz, input reset, output LED);

reg [31:0] count =0;
reg led_output =0;

always @ (posedge CLOCK_100Mhz or posedge reset)
begin
	if (reset) 
		begin 
			count<=0; 
		end
		
	else
		begin 
			count <= count + 1;
			if(count == 50_000_000)
			begin
				count <= 0;
				led_output <= ~led_output;
			end
		end
end

assign LED = led_output;

endmodule