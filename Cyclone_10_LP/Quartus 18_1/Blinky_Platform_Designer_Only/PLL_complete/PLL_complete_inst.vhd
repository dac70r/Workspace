	component PLL_complete is
		port (
			clk_clk          : in  std_logic := 'X'; -- clk
			reset_reset_n    : in  std_logic := 'X'; -- reset_n
			to_outside_led   : out std_logic;        -- led
			to_outside_1_led : out std_logic         -- led
		);
	end component PLL_complete;

	u0 : component PLL_complete
		port map (
			clk_clk          => CONNECTED_TO_clk_clk,          --          clk.clk
			reset_reset_n    => CONNECTED_TO_reset_reset_n,    --        reset.reset_n
			to_outside_led   => CONNECTED_TO_to_outside_led,   --   to_outside.led
			to_outside_1_led => CONNECTED_TO_to_outside_1_led  -- to_outside_1.led
		);

