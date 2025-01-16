`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 04/06/2024 11:04:46 AM
// Module Name: debounced_button
// Description: The purpose of this module is to debounce the button pressed by user. This is done by cascading
 //             regs together, acting as delays.
//////////////////////////////////////////////////////////////////////////////////


module debounced_signal(
    input clk,
    input incoming_signal,
    output outgoing_signal
    );
    
    reg a,b,c;
    
always @ (posedge clk)
begin
    a <= incoming_signal; // first clk
    b <= a;           // second clk
    c <= b;           // third clk
end
    
assign outgoing_signal = c;

endmodule