// MOdule that configures SPI as Slave

module spi_start_clk (
	
    input clk,      // System clock (for synchronizing)
    input rst,      // Reset signal
    input SCK,      // SPI Clock input
    output reg first_clk_detected // Output flag indicating the first rising edge of SCK
	 
);

reg SCK_d1; // Delayed version of SCK (to detect rising edge)

always @(posedge clk or posedge rst) begin
    if (rst) begin
        SCK_d1 <= 0;
        first_clk_detected <= 0;
    end else begin
        SCK_d1 <= SCK;
        
        // Detect rising edge of SCK
        if (~SCK_d1 && SCK) begin
            first_clk_detected <= 1; // First rising edge detected
        end
    end
end

endmodule
