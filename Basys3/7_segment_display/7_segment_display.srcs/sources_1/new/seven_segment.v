`timescale 1ns / 1ps

module seven_segment(input [3:0]sw, output [3:0]LED, output dp, output [6:0]seg, output [3:0]an);

reg [6:0]seg_storage = 7'b0000_000; // the number 8 
reg dp_storage = 1'b1;              // dp is disabled 
reg [3:0]an_storage = 4'b0010;      // 88X8

// Method 1 - Assign the an and reg with data from a register
// assign an = an_storage; 
// assign seg = seg_storage;
// assign dp = dp_storage; 

// Method 2 - Assign the an and reg manually (1 by 1) 
// Note here that outputs such as leds can be used to assign to another output 
assign an[0] = ~LED[0];
assign an[1] = LED[0];
assign an[2] = ~LED[0];
assign an[3] = ~LED[0];
assign seg = seg_storage;
assign dp = dp_storage; 

// Assigning switches to leds
assign LED[0] = sw[0];
assign LED[1] = sw[1];
assign LED[2] = sw[2];
assign LED[3] = sw[3];


endmodule
