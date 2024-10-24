	component my_timer is
		port (
			clk_clk    : in  std_logic := 'X'; -- clk
			led_export : out std_logic         -- export
		);
	end component my_timer;

	u0 : component my_timer
		port map (
			clk_clk    => CONNECTED_TO_clk_clk,    -- clk.clk
			led_export => CONNECTED_TO_led_export  -- led.export
		);

