	qsys_top u0 (
		.clk_clk                                     (<connected-to-clk_clk>),                                     //                                   clk.clk
		.eth_tse_0_mac_mdio_connection_mdc           (<connected-to-eth_tse_0_mac_mdio_connection_mdc>),           //         eth_tse_0_mac_mdio_connection.mdc
		.eth_tse_0_mac_mdio_connection_mdio_in       (<connected-to-eth_tse_0_mac_mdio_connection_mdio_in>),       //                                      .mdio_in
		.eth_tse_0_mac_mdio_connection_mdio_out      (<connected-to-eth_tse_0_mac_mdio_connection_mdio_out>),      //                                      .mdio_out
		.eth_tse_0_mac_mdio_connection_mdio_oen      (<connected-to-eth_tse_0_mac_mdio_connection_mdio_oen>),      //                                      .mdio_oen
		.eth_tse_0_mac_misc_connection_xon_gen       (<connected-to-eth_tse_0_mac_misc_connection_xon_gen>),       //         eth_tse_0_mac_misc_connection.xon_gen
		.eth_tse_0_mac_misc_connection_xoff_gen      (<connected-to-eth_tse_0_mac_misc_connection_xoff_gen>),      //                                      .xoff_gen
		.eth_tse_0_mac_misc_connection_ff_tx_crc_fwd (<connected-to-eth_tse_0_mac_misc_connection_ff_tx_crc_fwd>), //                                      .ff_tx_crc_fwd
		.eth_tse_0_mac_misc_connection_ff_tx_septy   (<connected-to-eth_tse_0_mac_misc_connection_ff_tx_septy>),   //                                      .ff_tx_septy
		.eth_tse_0_mac_misc_connection_tx_ff_uflow   (<connected-to-eth_tse_0_mac_misc_connection_tx_ff_uflow>),   //                                      .tx_ff_uflow
		.eth_tse_0_mac_misc_connection_ff_tx_a_full  (<connected-to-eth_tse_0_mac_misc_connection_ff_tx_a_full>),  //                                      .ff_tx_a_full
		.eth_tse_0_mac_misc_connection_ff_tx_a_empty (<connected-to-eth_tse_0_mac_misc_connection_ff_tx_a_empty>), //                                      .ff_tx_a_empty
		.eth_tse_0_mac_misc_connection_rx_err_stat   (<connected-to-eth_tse_0_mac_misc_connection_rx_err_stat>),   //                                      .rx_err_stat
		.eth_tse_0_mac_misc_connection_rx_frm_type   (<connected-to-eth_tse_0_mac_misc_connection_rx_frm_type>),   //                                      .rx_frm_type
		.eth_tse_0_mac_misc_connection_ff_rx_dsav    (<connected-to-eth_tse_0_mac_misc_connection_ff_rx_dsav>),    //                                      .ff_rx_dsav
		.eth_tse_0_mac_misc_connection_ff_rx_a_full  (<connected-to-eth_tse_0_mac_misc_connection_ff_rx_a_full>),  //                                      .ff_rx_a_full
		.eth_tse_0_mac_misc_connection_ff_rx_a_empty (<connected-to-eth_tse_0_mac_misc_connection_ff_rx_a_empty>), //                                      .ff_rx_a_empty
		.eth_tse_0_mac_rgmii_connection_rgmii_in     (<connected-to-eth_tse_0_mac_rgmii_connection_rgmii_in>),     //        eth_tse_0_mac_rgmii_connection.rgmii_in
		.eth_tse_0_mac_rgmii_connection_rgmii_out    (<connected-to-eth_tse_0_mac_rgmii_connection_rgmii_out>),    //                                      .rgmii_out
		.eth_tse_0_mac_rgmii_connection_rx_control   (<connected-to-eth_tse_0_mac_rgmii_connection_rx_control>),   //                                      .rx_control
		.eth_tse_0_mac_rgmii_connection_tx_control   (<connected-to-eth_tse_0_mac_rgmii_connection_tx_control>),   //                                      .tx_control
		.eth_tse_0_mac_status_connection_set_10      (<connected-to-eth_tse_0_mac_status_connection_set_10>),      //       eth_tse_0_mac_status_connection.set_10
		.eth_tse_0_mac_status_connection_set_1000    (<connected-to-eth_tse_0_mac_status_connection_set_1000>),    //                                      .set_1000
		.eth_tse_0_mac_status_connection_eth_mode    (<connected-to-eth_tse_0_mac_status_connection_eth_mode>),    //                                      .eth_mode
		.eth_tse_0_mac_status_connection_ena_10      (<connected-to-eth_tse_0_mac_status_connection_ena_10>),      //                                      .ena_10
		.eth_tse_0_pcs_mac_rx_clock_connection_clk   (<connected-to-eth_tse_0_pcs_mac_rx_clock_connection_clk>),   // eth_tse_0_pcs_mac_rx_clock_connection.clk
		.eth_tse_0_pcs_mac_tx_clock_connection_clk   (<connected-to-eth_tse_0_pcs_mac_tx_clock_connection_clk>),   // eth_tse_0_pcs_mac_tx_clock_connection.clk
		.reset_reset_n                               (<connected-to-reset_reset_n>)                                //                                 reset.reset_n
	);

