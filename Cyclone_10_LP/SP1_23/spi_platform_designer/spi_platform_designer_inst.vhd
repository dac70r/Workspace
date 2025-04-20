	component spi_platform_designer is
		port (
			clk_clk                       : in  std_logic := 'X'; -- clk
			esc_spi_eepdone_export_export : in  std_logic := 'X'; -- export
			esc_spi_export_MISO           : in  std_logic := 'X'; -- MISO
			esc_spi_export_MOSI           : out std_logic;        -- MOSI
			esc_spi_export_SCLK           : out std_logic;        -- SCLK
			esc_spi_export_SS_n           : out std_logic;        -- SS_n
			esc_spi_ss_export_export      : out std_logic;        -- export
			reset_reset_n                 : in  std_logic := 'X'; -- reset_n
			spi_adc_reset_export_export   : out std_logic;        -- export
			spi_export_MISO               : in  std_logic := 'X'; -- MISO
			spi_export_MOSI               : out std_logic;        -- MOSI
			spi_export_SCLK               : out std_logic;        -- SCLK
			spi_export_SS_n               : out std_logic         -- SS_n
		);
	end component spi_platform_designer;

	u0 : component spi_platform_designer
		port map (
			clk_clk                       => CONNECTED_TO_clk_clk,                       --                    clk.clk
			esc_spi_eepdone_export_export => CONNECTED_TO_esc_spi_eepdone_export_export, -- esc_spi_eepdone_export.export
			esc_spi_export_MISO           => CONNECTED_TO_esc_spi_export_MISO,           --         esc_spi_export.MISO
			esc_spi_export_MOSI           => CONNECTED_TO_esc_spi_export_MOSI,           --                       .MOSI
			esc_spi_export_SCLK           => CONNECTED_TO_esc_spi_export_SCLK,           --                       .SCLK
			esc_spi_export_SS_n           => CONNECTED_TO_esc_spi_export_SS_n,           --                       .SS_n
			esc_spi_ss_export_export      => CONNECTED_TO_esc_spi_ss_export_export,      --      esc_spi_ss_export.export
			reset_reset_n                 => CONNECTED_TO_reset_reset_n,                 --                  reset.reset_n
			spi_adc_reset_export_export   => CONNECTED_TO_spi_adc_reset_export_export,   --   spi_adc_reset_export.export
			spi_export_MISO               => CONNECTED_TO_spi_export_MISO,               --             spi_export.MISO
			spi_export_MOSI               => CONNECTED_TO_spi_export_MOSI,               --                       .MOSI
			spi_export_SCLK               => CONNECTED_TO_spi_export_SCLK,               --                       .SCLK
			spi_export_SS_n               => CONNECTED_TO_spi_export_SS_n                --                       .SS_n
		);

