`timescale 1ns / 1ps
// Create Date: 04/06/2024 08:58:26 PM
// Design Name: 
// Module Name: state_machine

module state_machine(
    input clk_in,
    input reset,
    output reg [2:0] main_str, // outputs thru the PMOD of the basys 3
    output reg [2:0] cross_str // outputs thru the PMOD of the basys 3
    );
    
    // Define states
    parameter main_green_cross_red  = 2'b00;
    parameter main_yellow_cross_red = 2'b01;
    parameter main_red_cross_green = 2'b10;
    parameter main_red_cross_yellow = 2'b11;
    
    // The state register - keeps tracks of the current state of register
    reg [1:0] state_reg = 0;
    
    // Timer for traffic light changes
    reg [4:0] count_secs = 0;
    
    // Counter for light changes - when the counter overflows it will reset itself to 0
    always @ (posedge clk_in)
    begin
        if(reset)begin count_secs <= 0; end
        else count_secs <= count_secs + 1;
    end
    
    // State Machine Handler - defines the conditions for stage transitions 
    always @ (posedge clk_in or posedge reset)
    begin
        if(reset)
        begin state_reg<= 0; end // Reverts back to state 1 and timer reset
        else
            begin
                case(state_reg)
                   main_green_cross_red  : if(count_secs == 15)     state_reg <= main_yellow_cross_red;
                    main_yellow_cross_red : if(count_secs == 18)     state_reg <= main_red_cross_green;
                    main_red_cross_green  : if(count_secs == 28)     state_reg <= main_red_cross_yellow;
                    main_red_cross_yellow : if(count_secs == 31)     state_reg <= main_green_cross_red;
                    default: state_reg <= main_green_cross_red;
                endcase
            end
    end
    
    // Output Handler - defines the signal outputs for main_str & cross_str
    // The main_str and cross_str have their msb and lsb switched because we declare main_str [2:0] instead of main_str[0:2]
    always @ (posedge clk_in)
    begin
        case (state_reg)
        main_green_cross_red:
            begin main_str <= 3'b100; cross_str <= 3'b001; end
        main_yellow_cross_red:
            begin main_str <= 3'b010; cross_str <= 3'b001; end
        main_red_cross_green:
            begin main_str <= 3'b001; cross_str <= 3'b100; end
        main_red_cross_yellow:
            begin main_str <= 3'b001; cross_str <= 3'b010; end
        endcase
    end
    
endmodule
