`timescale 1ns / 1ps

// Implementing a simple debouncing circuit using 2 D Flip Flops
// D Flip Flop Implementation
module dff(
input clk,  // input clock
input btnC, // input signal (push button) 
output reg Q, // register because need to store values in always block
output reg Qbar); // register because need to store values in always block

always @ (posedge clk)
begin
    Q <= btnC;  
    Qbar <= ~Q;
end 

endmodule
