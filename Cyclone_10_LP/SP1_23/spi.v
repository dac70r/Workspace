module spi (
		input    clk_clk,                       //                    clk.clk
		input    esc_spi_eepdone_export_export, // esc_spi_eepdone_export.export
		input    esc_spi_export_MISO,           //         esc_spi_export.MISO
		output   esc_spi_export_MOSI,           //                       .MOSI
		output   esc_spi_export_SCLK,           //                       .SCLK
		output   esc_spi_export_SS_n,           //                       .SS_n
		output   esc_spi_ss_export_export,      //      esc_spi_ss_export.export
		input    reset_reset_n,                 //                  reset.reset_n
		output   spi_adc_reset_export_export,   //   spi_adc_reset_export.export
		input    spi_export_MISO,               //             spi_export.MISO
		output   spi_export_MOSI,               //                       .MOSI
		output   spi_export_SCLK,               //                       .SCLK
		output   spi_export_SS_n,               //                       .SS_n
		
		// The following signals are for signal tapping, hence they are input only
		input   st_esc_spi_export_SS_n, 
		input   st_esc_spi_export_MOSI,       	 //                       .MOSI
		input   st_esc_spi_export_MISO,         //            			  .MISO
		input   st_esc_spi_export_SCLK,         //                       .SCLK
		input   st_esc_spi_ss_export_export     //                       .SS_n
	);

spi_platform_designer u0 (
    .clk_clk(clk_clk),
    .reset_reset_n(reset_reset_n),
    .esc_spi_eepdone_export_export(esc_spi_eepdone_export_export),
    .esc_spi_export_MISO(esc_spi_export_MISO),
    .esc_spi_export_MOSI(esc_spi_export_MOSI),
    .esc_spi_export_SCLK(esc_spi_export_SCLK),
    .esc_spi_export_SS_n(esc_spi_export_SS_n),
    .esc_spi_ss_export_export(esc_spi_ss_export_export),
    .spi_adc_reset_export_export(spi_adc_reset_export_export),
    .spi_export_MISO(spi_export_MISO),
    .spi_export_MOSI(spi_export_MOSI),
    .spi_export_SCLK(spi_export_SCLK),
    .spi_export_SS_n(spi_export_SS_n)
);

endmodule