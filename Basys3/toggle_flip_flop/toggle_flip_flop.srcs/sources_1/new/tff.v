`timescale 1ns / 1ps

// Toggle Flip Flop with Synchronous Reset w/o debouncing

module tff(
    input CLK100MHZ, // clock
    input toggle,    // toggle, usually is push button
    input reset,     // reset, usaully also use push button
    output reg q    // output, usually use led to visualize
    );
    
always @ (posedge CLK100MHZ)
begin
    if (reset == 1)
    begin
        q <= 0; // checks for reset 
    end
    else
        begin
            if(toggle == 1)
                q <= ~q;
            else
                q <= q;
        end 
end
endmodule