	component My_First_NIOS_II_Platform_Designer is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			gpio_external_connection_export : out std_logic_vector(7 downto 0)         -- export
		);
	end component My_First_NIOS_II_Platform_Designer;

	u0 : component My_First_NIOS_II_Platform_Designer
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			gpio_external_connection_export => CONNECTED_TO_gpio_external_connection_export  -- gpio_external_connection.export
		);

