`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 04/06/2024 11:04:46 AM
// Module Name: debounced_button
// Description: The purpose of this module is to debounce the button pressed by user. This is done by cascading
 //             regs together, acting as delays.
//////////////////////////////////////////////////////////////////////////////////


module debounced_button(
    input clk,
    input push_button,
    output led
    );
    
    reg a,b,c;
    
always @ (posedge clk)
begin
    a <= push_button; // first clk
    b <= a;           // second clk
    c <= b;           // third clk
end
    
assign led = c;

endmodule