set_global_assignment -entity "one_hz" -library "lib_one_hz" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "one_hz" -library "lib_one_hz" -name IP_TOOL_VERSION "18.1"
set_global_assignment -entity "one_hz" -library "lib_one_hz" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_one_hz" -name SPD_FILE [file join $::quartus(sip_path) "one_hz.spd"]

set_global_assignment -library "lib_one_hz" -name MISC_FILE [file join $::quartus(sip_path) "one_hz_sim/one_hz.vo"]
