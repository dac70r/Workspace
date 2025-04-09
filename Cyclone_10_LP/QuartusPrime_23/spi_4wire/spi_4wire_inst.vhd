	component spi_4wire is
		port (
			clk_clk             : in  std_logic := 'X'; -- clk
			reset_reset_n       : in  std_logic := 'X'; -- reset_n
			spi_0_external_MISO : in  std_logic := 'X'; -- MISO
			spi_0_external_MOSI : out std_logic;        -- MOSI
			spi_0_external_SCLK : out std_logic;        -- SCLK
			spi_0_external_SS_n : out std_logic         -- SS_n
		);
	end component spi_4wire;

	u0 : component spi_4wire
		port map (
			clk_clk             => CONNECTED_TO_clk_clk,             --            clk.clk
			reset_reset_n       => CONNECTED_TO_reset_reset_n,       --          reset.reset_n
			spi_0_external_MISO => CONNECTED_TO_spi_0_external_MISO, -- spi_0_external.MISO
			spi_0_external_MOSI => CONNECTED_TO_spi_0_external_MOSI, --               .MOSI
			spi_0_external_SCLK => CONNECTED_TO_spi_0_external_SCLK, --               .SCLK
			spi_0_external_SS_n => CONNECTED_TO_spi_0_external_SS_n  --               .SS_n
		);

