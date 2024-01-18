`timescale 1ns / 1ps

module clk_1hz(input clk, input sw0, input sw1, output led0, output led1);

wire clk_out_10hz;       // 10hz clock
reg clk_out_1hz;         // 1hz clock
reg [2:0] count = 0;     // count from 0 to 5

clk_10hz clk10hz(clk,clk_out_10hz);

always @ (posedge clk_out_10hz)
begin
    count <= count + 1;
    if(count == 5)
        begin
            count <= 0;
            clk_out_1hz <= ~clk_out_1hz;
        end
end

// configure led0 to blink only when sw0 is toggled
// configure led1 to blink only when sw1 is toggled
assign led0 = sw0 & clk_out_10hz;
assign led1 = sw1 & clk_out_1hz;

endmodule
