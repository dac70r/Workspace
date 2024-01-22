`timescale 1ns / 1ps

module led_switch(
    input CLK100MHZ,    // Input clk of 100MHz 
    input btnC,         // btnC for toggling the led on and off
    //input btnL,         // the reset button for led
    output led          // output led for visualizing the results
);

wire led_output_btnC;       // the output pulse from debouncing module 1 - for btnC
//wire led_output_btnL;       // the output pulse from debouncing module 2 - for btnL

reg status_led = 1'b0;          // status register for led 
//reg status_btnL = 1'b0;          // status register for button left (pressed or not)

debouncing db1( CLK100MHZ, btnC, led_output_btnC); // led_output_btnL is the outcome of the debouncing module 1
//debouncing db2( CLK100MHZ, btnL, led_output_btnL); // led_output_btnC is the outcome of the debouncing module 2

// whenever btnC is pressed, the status_led is modified
always @ (posedge led_output_btnC)
begin
    if(status_led == 1)
        begin status_led <=0;end 
        else begin status_led <= status_led + 1;end 
    end

assign led = status_led;

endmodule
