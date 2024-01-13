`timescale 1ns / 1ps

// One bit Adder
module one_bit_adder(
    input A,B,Carry_in,
    output S, Carry_out
    );
    assign S = A ^ B ^ Carry_in; // C is equal to A XOR B
    assign Carry_out = (A & B) | ((A ^ B) & Carry_in);
endmodule

// AND GATE
//module and_gate(
//    input A,B,
//    output C
//    );
//    assign C = A & B;
//endmodule

// OR GATE
//module and_gate(
//    input A,B,
//    output C
//    );
//    assign C = A & B;
//endmodule

// XOR Gate
//module xor_gate(
//    input A,B,
//    output C
//    );
//    assign C = A ^ B;
//endmodule