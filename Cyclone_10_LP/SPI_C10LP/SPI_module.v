// Module that configures SPI as Slave
		 
		 // Future works: 
		 // 1. Add support for different CPHA and CPOL modes
		 // 2. Rewrite as state machine
		 // 3. Add support for MISO as this is only supporting MOSI (this is slave)	
		 
	module SPI_module (
		 input clk,          								// System clock
		 input rst_n,        								// Active-low reset
		 
		 input sclk,        								 	// SPI clock
		 input ss,           								// Slave select (active-low)
		 input mosi,         								// Master Out Slave In
		 output reg miso,         							// Master In Slave Out
		 
		 output reg [2:0] bit_count=3'b000,     		// Bit counter for each byte of data
		 output reg [2:0] byte_count=3'b000,     		// Byte counter - keep track how many bytes received
		 
		 output reg [7:0] rx_data, 						// Place holder for a complete byte of data
		 output byte_received,								// Assert when receive a complete byte of data
		 output data_transaction_complete				// Assert when data transaction is complete (all 4 bytes of data received)
	);
	// Internal registers	
   reg [7:0] shift_reg;    								// Shift register for MOSI data
	reg [7:0] tx_data;       								// Data to send
		 
	// Memory declaration: 8 elements, each 8 bits wide
	reg [7:0] memory [7:0];
	
	
	// State Machine Logic
	// State encoding
	localparam 	IDLE = 3'b000,
					RECEIVE_BIT = 3'b001,
					STORE_BYTE = 3'b010,
					CHECK_COMPLETE = 3'b011;
					
	// State Machine variables
	reg current_state;
	reg next_state;
	
	 // Clock edge detection for SCLK
    reg sclk_prev;
    wire sclk_rising_edge;

    assign sclk_rising_edge = ~sclk_prev & sclk;
	
	// State machine logic
    always @(posedge sclk or negedge rst_n) begin
        if (!rst_n) begin
				miso <= 1'b0;
				rx_data <= 8'b0;
				tx_data <= 8'b0;
				bit_count <= 3'b0;
				byte_count <= 3'b0;		
			end
			
			else
			if(!ss) begin
				// current_state <= next_state;
				/*
				if (sclk_rising_edge == 1 && current_state == RECEIVE_BIT) begin
                shift_reg <= {shift_reg[6:0], mosi};
                bit_count <= bit_count + 1;
            end
				
				if (current_state == STORE_BYTE) begin
                rx_data <= shift_reg;
                memory[byte_count] <= shift_reg;
                byte_count <= byte_count + 1;
                bit_count <= 3'b000;
            end
				
				if (current_state == IDLE && ss) begin
					bit_count <= 3'b000;
					byte_count <= 3'b000;
				end */
				
			end
	end

	// Next state logic
	/*
    always @(*) 
	 begin
        case (current_state)
            IDLE: begin
                if (!ss) next_state = RECEIVE_BIT;
                else next_state = IDLE;
            end

            RECEIVE_BIT: begin
                if (bit_count == 3'b111) next_state = STORE_BYTE;
                else next_state = RECEIVE_BIT;
            end

            STORE_BYTE: begin
                if (byte_count == 3'b111) next_state = CHECK_COMPLETE;
                else next_state = RECEIVE_BIT;
            end

            CHECK_COMPLETE: begin
                if (ss) next_state = IDLE;
                else next_state = RECEIVE_BIT;
            end

            default: next_state = IDLE;
        endcase
    end */
			
							  

		
	assign byte_received = (bit_count == 7) ? 1 : 0;
	assign data_transaction_complete = (byte_count == 7 && byte_received == 1) ? 1 : 0;

	endmodule