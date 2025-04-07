	component My_First_NIOS_II_Platform_Designer is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			esc_eepdone_external_export     : in  std_logic                    := 'X'; -- export
			esc_spi_external_MISO           : in  std_logic                    := 'X'; -- MISO
			esc_spi_external_MOSI           : out std_logic;                           -- MOSI
			esc_spi_external_SCLK           : out std_logic;                           -- SCLK
			esc_spi_external_SS_n           : out std_logic;                           -- SS_n
			gpio_external_connection_export : out std_logic_vector(7 downto 0)         -- export
		);
	end component My_First_NIOS_II_Platform_Designer;

	u0 : component My_First_NIOS_II_Platform_Designer
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			esc_eepdone_external_export     => CONNECTED_TO_esc_eepdone_external_export,     --     esc_eepdone_external.export
			esc_spi_external_MISO           => CONNECTED_TO_esc_spi_external_MISO,           --         esc_spi_external.MISO
			esc_spi_external_MOSI           => CONNECTED_TO_esc_spi_external_MOSI,           --                         .MOSI
			esc_spi_external_SCLK           => CONNECTED_TO_esc_spi_external_SCLK,           --                         .SCLK
			esc_spi_external_SS_n           => CONNECTED_TO_esc_spi_external_SS_n,           --                         .SS_n
			gpio_external_connection_export => CONNECTED_TO_gpio_external_connection_export  -- gpio_external_connection.export
		);

