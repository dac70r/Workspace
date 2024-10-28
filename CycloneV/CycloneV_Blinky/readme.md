# Blinky Project for the Cyclone V 

## Hardware
- Dev Kit: PCIe16IO 
- Quartus Prime 19.1 lite

## Software 
- Unlike off-the-shelf dev kits, the PCIe16IO is using reference clock from PCIe, as such we cannot use the clock signal directly but rather, we must pass the clock signal through a PLL before it can be fed into a blinky module.
