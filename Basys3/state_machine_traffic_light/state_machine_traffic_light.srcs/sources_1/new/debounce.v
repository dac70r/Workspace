`timescale 1ns / 1ps
module debounce(
    input clock,
    input input_button,
    output output_button
    );

reg a,b,c;

always @ (posedge clock)
begin
    a <= input_button;
    b <= a;
    c <= b;
end

assign output_button = c;

endmodule
