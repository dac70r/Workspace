#create_clock -period 20.000 -name OSC_Clock
#derive_pll_clocks
#derive_clock_uncertainty
#set_false_path - to {get_ports LED}