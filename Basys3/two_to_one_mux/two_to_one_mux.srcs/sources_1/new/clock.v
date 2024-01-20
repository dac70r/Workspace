`timescale 1ns / 1ps

module clk_10hz(input clk, output led);
reg [22:0] counter = 0;
reg clk_out; 

always @ (posedge clk)
begin
    counter <= counter + 1;
    if(counter == 5_000_000)
        begin
            counter <= 0;
            clk_out <= ~clk_out;
        end
end 

// the led blinks only when sw1 is toggled
assign led = clk_out;

endmodule