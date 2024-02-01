`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/01/2024 07:50:33 PM
// Design Name: 
// Module Name: Top_Module
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


module Top_Module(output [6:0]seg, output [3:0]an);

parameter NULL = 7'b111_1111;
parameter ZERO = 7'b000_0001;
parameter ONE = 7'b100_1111;
parameter TWO = 7'b001_0010;
parameter THREE = 7'b000_0110;
//parameter FOUR = 7

reg [6:0] segment_initial = 7'b0111110; //lsb correspond to the top, then it goes clockwise, finally reach middle
reg [3:0] an_initial = 4'b0001;

assign an = an_initial;
assign seg = segment_initial;

endmodule
