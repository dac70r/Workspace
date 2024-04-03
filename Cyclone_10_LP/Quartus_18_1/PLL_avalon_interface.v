module PLL_avalon_interface (input clock, input resetn, input read, output [7:0] readdata, output LED);

// signals for connecting to the Avalon fabric
// input clock, resetn, 
// read, readdata [7:0] ; --> not important must must have if using an avalon slave

// signal for exporting register contents outside of the embedded system
// output LED; --> must assign in this module
wire from_reg; 

PLL_Platform_Desginer U1 ( .clock(clock), .resetn(resetn), .LED(from_reg));


assign readdata = from_reg;
assign LED = from_reg;

endmodule