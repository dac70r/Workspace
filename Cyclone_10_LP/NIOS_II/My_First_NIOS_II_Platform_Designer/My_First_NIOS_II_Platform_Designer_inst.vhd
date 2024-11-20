	component My_First_NIOS_II_Platform_Designer is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			gpio_external_connection_export : out std_logic_vector(7 downto 0);        -- export
			spi_0_external_MISO             : in  std_logic                    := 'X'; -- MISO
			spi_0_external_MOSI             : out std_logic;                           -- MOSI
			spi_0_external_SCLK             : out std_logic;                           -- SCLK
			spi_0_external_SS_n             : out std_logic                            -- SS_n
		);
	end component My_First_NIOS_II_Platform_Designer;

	u0 : component My_First_NIOS_II_Platform_Designer
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			gpio_external_connection_export => CONNECTED_TO_gpio_external_connection_export, -- gpio_external_connection.export
			spi_0_external_MISO             => CONNECTED_TO_spi_0_external_MISO,             --           spi_0_external.MISO
			spi_0_external_MOSI             => CONNECTED_TO_spi_0_external_MOSI,             --                         .MOSI
			spi_0_external_SCLK             => CONNECTED_TO_spi_0_external_SCLK,             --                         .SCLK
			spi_0_external_SS_n             => CONNECTED_TO_spi_0_external_SS_n              --                         .SS_n
		);

