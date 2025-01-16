`timescale 1ns/1ps

module spi_slave_tb;

    // Testbench signals
    reg clk;          // System clock
    reg rst_n;        // Active-low reset
    reg sclk;         // SPI clock
    reg ss;           // Slave select
    reg mosi;         // Master Out Slave In
    wire miso;        // Master In Slave Out
    wire [7:0] rx_data; // Received data

    // Instantiate the SPI Slave module
    SPI uut (
        .clk(clk),
        .rst_n(rst_n),
        .sclk(sclk),
        .ss(ss),
        .mosi(mosi),
        .miso(miso),
        .rx_data(rx_data)
    );

    // Clock generation for system clock
    always #5 clk = ~clk;  // System clock with 10 ns period (100 MHz)

    // Testbench logic
    initial begin
        // Initialize signals
        clk = 0;
        rst_n = 0;
        sclk = 0;
        ss = 1;  // SPI inactive
        mosi = 0;

        // Reset the DUT
        #20;
        rst_n = 1;

        // Test case 1: Transmit and receive an 8-bit value
        #20;
        ss = 0;  // Enable SPI slave (SS active low)
        
        // Send data on MOSI (0b10101010) and observe response on MISO
        send_spi_byte(8'b10101010);

        #40;
        ss = 1;  // Disable SPI slave
        
        #20;
        $stop;  // End simulation
    end

    // Task to send a single byte over SPI
    task send_spi_byte(input [7:0] data_in);
        integer i;
        begin
            for (i = 7; i >= 0; i = i - 1) begin
                // Set MOSI bit
                mosi = data_in[i];
                #10;
                // Generate SCLK rising edge
                sclk = 1;
                #10;
                // Generate SCLK falling edge
                sclk = 0;
                #10;
            end
        end
    endtask

endmodule