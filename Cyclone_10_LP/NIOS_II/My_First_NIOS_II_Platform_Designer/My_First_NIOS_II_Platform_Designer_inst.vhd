	component My_First_NIOS_II_Platform_Designer is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			gpio_external_connection_export : out std_logic_vector(7 downto 0);        -- export
			reset_adc_export                : out std_logic_vector(7 downto 0);        -- export
			spi_0_external_MISO             : in  std_logic                    := 'X'; -- MISO
			spi_0_external_MOSI             : out std_logic;                           -- MOSI
			spi_0_external_SCLK             : out std_logic;                           -- SCLK
			spi_0_external_SS_n             : out std_logic;                           -- SS_n
			adc_1_spi_external_MISO         : in  std_logic                    := 'X'; -- MISO
			adc_1_spi_external_MOSI         : out std_logic;                           -- MOSI
			adc_1_spi_external_SCLK         : out std_logic;                           -- SCLK
			adc_1_spi_external_SS_n         : out std_logic;                           -- SS_n
			esc_spi_external_MISO           : in  std_logic                    := 'X'; -- MISO
			esc_spi_external_MOSI           : out std_logic;                           -- MOSI
			esc_spi_external_SCLK           : out std_logic;                           -- SCLK
			esc_spi_external_SS_n           : out std_logic                            -- SS_n
		);
	end component My_First_NIOS_II_Platform_Designer;

	u0 : component My_First_NIOS_II_Platform_Designer
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			gpio_external_connection_export => CONNECTED_TO_gpio_external_connection_export, -- gpio_external_connection.export
			reset_adc_export                => CONNECTED_TO_reset_adc_export,                --                reset_adc.export
			spi_0_external_MISO             => CONNECTED_TO_spi_0_external_MISO,             --           spi_0_external.MISO
			spi_0_external_MOSI             => CONNECTED_TO_spi_0_external_MOSI,             --                         .MOSI
			spi_0_external_SCLK             => CONNECTED_TO_spi_0_external_SCLK,             --                         .SCLK
			spi_0_external_SS_n             => CONNECTED_TO_spi_0_external_SS_n,             --                         .SS_n
			adc_1_spi_external_MISO         => CONNECTED_TO_adc_1_spi_external_MISO,         --       adc_1_spi_external.MISO
			adc_1_spi_external_MOSI         => CONNECTED_TO_adc_1_spi_external_MOSI,         --                         .MOSI
			adc_1_spi_external_SCLK         => CONNECTED_TO_adc_1_spi_external_SCLK,         --                         .SCLK
			adc_1_spi_external_SS_n         => CONNECTED_TO_adc_1_spi_external_SS_n,         --                         .SS_n
			esc_spi_external_MISO           => CONNECTED_TO_esc_spi_external_MISO,           --         esc_spi_external.MISO
			esc_spi_external_MOSI           => CONNECTED_TO_esc_spi_external_MOSI,           --                         .MOSI
			esc_spi_external_SCLK           => CONNECTED_TO_esc_spi_external_SCLK,           --                         .SCLK
			esc_spi_external_SS_n           => CONNECTED_TO_esc_spi_external_SS_n            --                         .SS_n
		);

