	component My_First_NIOS_II_Platform_Designer is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			gpio_external_connection_export : out std_logic_vector(7 downto 0);        -- export
			reset_reset_n                   : in  std_logic                    := 'X'  -- reset_n
		);
	end component My_First_NIOS_II_Platform_Designer;

	u0 : component My_First_NIOS_II_Platform_Designer
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			gpio_external_connection_export => CONNECTED_TO_gpio_external_connection_export, -- gpio_external_connection.export
			reset_reset_n                   => CONNECTED_TO_reset_reset_n                    --                    reset.reset_n
		);

