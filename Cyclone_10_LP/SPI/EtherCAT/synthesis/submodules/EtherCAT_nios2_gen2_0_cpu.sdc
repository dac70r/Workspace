# Legal Notice: (C)2024 Altera Corporation. All rights reserved.  Your
# use of Altera Corporation's design tools, logic functions and other
# software and tools, and its AMPP partner logic functions, and any
# output files any of the foregoing (including device programming or
# simulation files), and any associated documentation or information are
# expressly subject to the terms and conditions of the Altera Program
# License Subscription Agreement or other applicable license agreement,
# including, without limitation, that your use is for the sole purpose
# of programming logic devices manufactured by Altera and sold by Altera
# or its authorized distributors.  Please refer to the applicable
# agreement for further details.

#**************************************************************
# Timequest JTAG clock definition
#   Uncommenting the following lines will define the JTAG
#   clock in TimeQuest Timing Analyzer
#**************************************************************

#create_clock -period 10MHz {altera_reserved_tck}
#set_clock_groups -asynchronous -group {altera_reserved_tck}

#**************************************************************
# Set TCL Path Variables 
#**************************************************************

set 	EtherCAT_nios2_gen2_0_cpu 	EtherCAT_nios2_gen2_0_cpu:*
set 	EtherCAT_nios2_gen2_0_cpu_oci 	EtherCAT_nios2_gen2_0_cpu_nios2_oci:the_EtherCAT_nios2_gen2_0_cpu_nios2_oci
set 	EtherCAT_nios2_gen2_0_cpu_oci_break 	EtherCAT_nios2_gen2_0_cpu_nios2_oci_break:the_EtherCAT_nios2_gen2_0_cpu_nios2_oci_break
set 	EtherCAT_nios2_gen2_0_cpu_ocimem 	EtherCAT_nios2_gen2_0_cpu_nios2_ocimem:the_EtherCAT_nios2_gen2_0_cpu_nios2_ocimem
set 	EtherCAT_nios2_gen2_0_cpu_oci_debug 	EtherCAT_nios2_gen2_0_cpu_nios2_oci_debug:the_EtherCAT_nios2_gen2_0_cpu_nios2_oci_debug
set 	EtherCAT_nios2_gen2_0_cpu_wrapper 	EtherCAT_nios2_gen2_0_cpu_debug_slave_wrapper:the_EtherCAT_nios2_gen2_0_cpu_debug_slave_wrapper
set 	EtherCAT_nios2_gen2_0_cpu_jtag_tck 	EtherCAT_nios2_gen2_0_cpu_debug_slave_tck:the_EtherCAT_nios2_gen2_0_cpu_debug_slave_tck
set 	EtherCAT_nios2_gen2_0_cpu_jtag_sysclk 	EtherCAT_nios2_gen2_0_cpu_debug_slave_sysclk:the_EtherCAT_nios2_gen2_0_cpu_debug_slave_sysclk
set 	EtherCAT_nios2_gen2_0_cpu_oci_path 	 [format "%s|%s" $EtherCAT_nios2_gen2_0_cpu $EtherCAT_nios2_gen2_0_cpu_oci]
set 	EtherCAT_nios2_gen2_0_cpu_oci_break_path 	 [format "%s|%s" $EtherCAT_nios2_gen2_0_cpu_oci_path $EtherCAT_nios2_gen2_0_cpu_oci_break]
set 	EtherCAT_nios2_gen2_0_cpu_ocimem_path 	 [format "%s|%s" $EtherCAT_nios2_gen2_0_cpu_oci_path $EtherCAT_nios2_gen2_0_cpu_ocimem]
set 	EtherCAT_nios2_gen2_0_cpu_oci_debug_path 	 [format "%s|%s" $EtherCAT_nios2_gen2_0_cpu_oci_path $EtherCAT_nios2_gen2_0_cpu_oci_debug]
set 	EtherCAT_nios2_gen2_0_cpu_jtag_tck_path 	 [format "%s|%s|%s" $EtherCAT_nios2_gen2_0_cpu_oci_path $EtherCAT_nios2_gen2_0_cpu_wrapper $EtherCAT_nios2_gen2_0_cpu_jtag_tck]
set 	EtherCAT_nios2_gen2_0_cpu_jtag_sysclk_path 	 [format "%s|%s|%s" $EtherCAT_nios2_gen2_0_cpu_oci_path $EtherCAT_nios2_gen2_0_cpu_wrapper $EtherCAT_nios2_gen2_0_cpu_jtag_sysclk]
set 	EtherCAT_nios2_gen2_0_cpu_jtag_sr 	 [format "%s|*sr" $EtherCAT_nios2_gen2_0_cpu_jtag_tck_path]

#**************************************************************
# Set False Paths
#**************************************************************

set_false_path -from [get_keepers *$EtherCAT_nios2_gen2_0_cpu_oci_break_path|break_readreg*] -to [get_keepers *$EtherCAT_nios2_gen2_0_cpu_jtag_sr*]
set_false_path -from [get_keepers *$EtherCAT_nios2_gen2_0_cpu_oci_debug_path|*resetlatch]     -to [get_keepers *$EtherCAT_nios2_gen2_0_cpu_jtag_sr[33]]
set_false_path -from [get_keepers *$EtherCAT_nios2_gen2_0_cpu_oci_debug_path|monitor_ready]  -to [get_keepers *$EtherCAT_nios2_gen2_0_cpu_jtag_sr[0]]
set_false_path -from [get_keepers *$EtherCAT_nios2_gen2_0_cpu_oci_debug_path|monitor_error]  -to [get_keepers *$EtherCAT_nios2_gen2_0_cpu_jtag_sr[34]]
set_false_path -from [get_keepers *$EtherCAT_nios2_gen2_0_cpu_ocimem_path|*MonDReg*] -to [get_keepers *$EtherCAT_nios2_gen2_0_cpu_jtag_sr*]
set_false_path -from *$EtherCAT_nios2_gen2_0_cpu_jtag_sr*    -to *$EtherCAT_nios2_gen2_0_cpu_jtag_sysclk_path|*jdo*
set_false_path -from sld_hub:*|irf_reg* -to *$EtherCAT_nios2_gen2_0_cpu_jtag_sysclk_path|ir*
set_false_path -from sld_hub:*|sld_shadow_jsm:shadow_jsm|state[1] -to *$EtherCAT_nios2_gen2_0_cpu_oci_debug_path|monitor_go
