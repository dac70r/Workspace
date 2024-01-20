`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/20/2024 06:45:43 PM
// Design Name: 
// Module Name: two_to_one_mux
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module two_to_one_mux(input CLK100MHZ, input S, output Z);
    reg A = 1'b1;
    reg B = 1'b0;
    wire C;  
    wire D;
    
    clk_10hz clk10hz (CLK100MHZ, C);
    clk_1hz clk1hz (CLK100MHZ, D);
    // Method 1
    // If S is equal toggled, led on 
    // Vice versa, if S is not toggled, led off
    // assign Z = S ? A : B;
    
    // Method 2
    // We create a clk running at 10Hz,
    // If S is toggled, then led blinks at 10Hz and if not led blinks at 1Hz 
    assign Z = S ? C : D;
    
endmodule
