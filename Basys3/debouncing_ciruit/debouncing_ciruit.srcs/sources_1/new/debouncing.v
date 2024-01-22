`timescale 1ns / 1ps

module debouncing(input CLK100MHZ, input btnC, output led);
    
wire clk_out;       // output from clk divider - 4hz clock freq
//reg on_off;         // register for storing on/off status

wire output_Q1; 
wire output_Q1_bar;
wire output_Q2; 
wire output_Q2_bar;

clk_4hz clk4hz (CLK100MHZ, clk_out); // instantiate clock divider module 


dff dff1(clk_out, btnC, output_Q1, output_Q1_bar);
dff dff2(clk_out, output_Q1, output_Q2, output_Q2_bar);

assign led = output_Q1 & output_Q2_bar; 

endmodule
