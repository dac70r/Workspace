transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/Cyclone_10_LP/SPI_C10LP {C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/Cyclone_10_LP/SPI_C10LP/SPI.v}

