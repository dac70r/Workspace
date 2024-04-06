`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 04/06/2024 05:47:46 PM
// Design Name: 
// Module Name: state_machine_top_module
//////////////////////////////////////////////////////////////////////////////////


module state_machine_top_module(
    input clk,
    input button,
    output [2:0] main_str, // outputs thru the PMOD of the basys 3
    output [2:0] cross_str // outputs thru the PMOD of the basys 3
    );
    
    // output wire from clk_1hz 
    wire clk_1hz; 
    
    // output wire from debounce button
    wire debounced; 
    
    clk_1hz uut0 (.clk_100Mhz(clk),.led(clk_1hz));
    debounce uut1 (.clock(clk),.input_button(button),.output_button(debounced));
    state_machine uut2 (.clk_in(clk_1hz),.reset(debounced),.main_str(main_str),.cross_str(cross_str));
    
endmodule
