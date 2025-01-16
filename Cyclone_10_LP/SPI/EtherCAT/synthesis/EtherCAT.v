// MOdule that configures SPI as Slave

module spi_slave (
    input wire clk,          // System clock
    input wire rst_n,        // Active-low reset
    input wire sclk,         // SPI clock
    input wire ss,           // Slave select (active-low)
    input wire mosi,         // Master Out Slave In
    output reg miso,         // Master In Slave Out
    output reg [7:0] rx_data // Received data
);

    reg [7:0] tx_data;       // Data to send
    reg [2:0] bit_count;     // Bit counter
    reg [7:0] shift_reg;     // Shift register for MOSI data
    reg sclk_prev;           // Previous state of SCLK
    
    always @(posedge clk or negedge rst_n) begin
			// Checks for reset
        if (!rst_n) begin
            miso <= 1'b0;
            rx_data <= 8'b0;
            tx_data <= 8'b0;
            shift_reg <= 8'b0;
            bit_count <= 3'b0;
            sclk_prev <= 1'b0;
			
				// Checks if CS has been pulled low
        end else begin
            if (!ss) begin
						// SPI active
						sclk_prev <= sclk;
						 if (sclk_prev == 0 && sclk == 1) begin
							  // Rising edge of SCLK
							  shift_reg <= {shift_reg[6:0], mosi}; // Shift in data
							  bit_count <= bit_count + 1;
							end 
							/*
						 else if (sclk_prev == 1 && sclk == 0) begin
							  // Falling edge of SCLK
							  miso <= tx_data[7];
							  tx_data <= {tx_data[6:0], 1'b0}; // Shift out data
							end */

                if (bit_count == 7 && sclk_prev == 0 && sclk == 1) begin
                    // 8 bits received
                    rx_data <= shift_reg;
                    bit_count <= 3'b0; // Reset counter
                end
            end else begin
                // SPI inactive
                miso <= 1'b0;
                bit_count <= 3'b0;
            end
        end
    end

endmodule
