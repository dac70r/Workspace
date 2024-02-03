
module blinky(input clock, input clk, output LED, output LED1);

reg [25:0]count =0;
reg [25:0]count_1 =0;
reg status;
reg status_1;

always @ (posedge clock)
begin
	count <= count + 1;
	
	//if (count == 24_999_999)
	if (count == 49_999_999)
	begin
		count <= 0;
		status <= ~status;
	end
	
end 

always @ (posedge clk)
begin
	count_1 <= count_1 + 1;
	if (count_1 == 24_999_999)
	begin
		count_1 <= 0;
		status_1 <= ~status_1;
	end
end

assign LED = status;
assign LED1 = status_1;
endmodule 