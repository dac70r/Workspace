`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 04/06/2024 04:55:28 PM
// Design Name: 
// Module Name: clk_1hz
// Description: This is module for a 1hz clock

module clk_1hz(
    input clk_100Mhz,
    output reg led = 0
    );
    
    reg [31:0] counter = 0;
    always @ (posedge clk_100Mhz)
    begin
         if(counter == 49_999_999)
         begin 
            counter = 0; led <= ~led;
         end
         else
            begin
                 counter = counter + 1;
            end
    end
endmodule
