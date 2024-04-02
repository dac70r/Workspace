/* This module takes a hex symbol and displays it using the 7-segment display */

module hex7seg(hex,display);

input [3:0]hex;
output reg [0:6] display; // the last entry in the array is the msb

/*
*
* 		– 0 –
* 	5 | 	  | 1
* 		– 6 –
*  4 |     | 2
* 		– 3 –
*
*/

always @ (hex)
begin
	case(hex)
	4'h0: display = 7'b0000_001;
	4'h1: display = 7'b1001_111;
	4'h2: display = 7'b0010_010;
	//
	4'h3: display = 7'b0000_110;
	4'h4: display = 7'b0110_011;
	4'h5: display = 7'b1011_011;
	//
	4'h6: display = 7'b0100000;
	4'h7: display = 7'b0001111;
	4'h8: display = 7'b0000000;
	4'h9: display = 7'b0001100;
	4'hA: display = 7'b0001000;
	4'hb: display = 7'b1100000;
	4'hC: display = 7'b0110001;
	4'hd: display = 7'b1000010;
	4'hE: display = 7'b0110000;
	4'hF: display = 7'b0111000;
	endcase
end
endmodule