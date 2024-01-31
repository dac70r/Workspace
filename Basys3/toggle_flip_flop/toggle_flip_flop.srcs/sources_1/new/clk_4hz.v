`timescale 1ns / 1ps

module clk_4hz(input clk, output led);
reg [23:0] counter = 0;
reg clk_out; 

always @ (posedge clk)
begin
    counter <= counter + 1;
    //if(counter == 12_500_000) //4hz
    if(counter == 6_250_000) //8hz
        begin
            counter <= 0;
            clk_out <= ~clk_out;
        end
end 

// the led blinks only when sw1 is toggled
assign led = clk_out;

endmodule
