/*

The verilog code for a 32-bit reg called reg32

*/

module reg32(clock, resetn, D, byteenable, Q);

input clock, resetn;
input [3:0] byteenable;
input [31:0] D;			// input to register
output reg[31:0] Q;		// output from register

always @ (posedge clock)
if(!resetn)
	Q <= 32'b0;
else
	begin
		if(byteenable[0]) Q[7:0] <= D[7:0];
		if(byteenable[1]) Q[15:8] <= D[15:8];
		if(byteenable[2]) Q[23:16] <= D[23:16];
		if(byteenable[3]) Q[31:24] <= D[31:24];
	end

endmodule