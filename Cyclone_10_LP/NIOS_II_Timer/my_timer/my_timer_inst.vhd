	component my_timer is
		port (
			clk_clk       : in  std_logic := 'X'; -- clk
			led_export    : out std_logic;        -- export
			reset_reset_n : in  std_logic := 'X'  -- reset_n
		);
	end component my_timer;

	u0 : component my_timer
		port map (
			clk_clk       => CONNECTED_TO_clk_clk,       --   clk.clk
			led_export    => CONNECTED_TO_led_export,    --   led.export
			reset_reset_n => CONNECTED_TO_reset_reset_n  -- reset.reset_n
		);

