`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/13/2024 02:35:58 PM
// Design Name: 
// Module Name: two_bit_adder
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


module two_bit_adder(input [1:0]A, input [1:0]B, input Carry_in, output [1:0]S, output Carry_out
    );
    
    wire Carry_add0_add1;
    
    one_bit_adder oba0( A[0], B[0], Carry_in,  S[0], Carry_add0_add1);
    one_bit_adder oba1( A[1], B[1], Carry_add0_add1, S[1], Carry_out);
    
endmodule
