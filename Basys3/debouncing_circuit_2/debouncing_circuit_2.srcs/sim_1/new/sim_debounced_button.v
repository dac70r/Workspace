`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 04/06/2024 11:35:08 AM
// Design Name: 
// Module Name: sim_debounced_button
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: Simulation for debounced button

module sim_debounced_button;
reg clk;        // clock
reg button;     // button
wire led;       // led

// Unit under test
debounced_button uut (clk, button, led);

initial
begin
    clk = 0;
    button = 0;
end

always #10 clk = ~clk;

initial begin
    #29; // Wait for 20 time units
    button = 1;
    #7; // Wait for 5 time units
    button = 0;
end

endmodule
