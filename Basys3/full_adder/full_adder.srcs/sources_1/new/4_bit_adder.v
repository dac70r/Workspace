`timescale 1ns / 1ps

module four_bit_adder(input [3:0]A, input [3:0]B, input Carry_in, output [3:0]S, output Carry_out);
    
    wire Carry_add0_add1;
    wire Carry_add1_add2;
    wire Carry_add2_add3;
    
    one_bit_adder oba0( A[0], B[0], Carry_in,  S[0], Carry_add0_add1);
    one_bit_adder oba1( A[1], B[1], Carry_add0_add1, S[1], Carry_add1_add2);
    one_bit_adder oba2( A[2], B[2], Carry_add1_add2,  S[2], Carry_add2_add3);
    one_bit_adder oba3( A[3], B[3], Carry_add2_add3, S[3], Carry_out);

endmodule