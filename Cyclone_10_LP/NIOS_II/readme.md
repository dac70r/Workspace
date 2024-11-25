# Using NIOS II to do Blinky with Timer Peripheral on Cyclone 10 LP Evaluation Kit

# Skills learnt: 

1. Design including a soft-core processor - NIOS-II and using it to blink LEDs on the Cyclone 10 LP Eval Kit using platform designer. 

2. How to create a .hex file of the softcore program and flash onto the evaluation kit. For more information, can refer to this link: https://www.macnica.co.jp/en/business/semiconductor/articles/intel/113961/

3. A .bdf is not always required, sometimes we may opt to create an instantiation of a design from platform designer in our main module, see example below. Do not add _inst.v file to your files.

4. Everytime we port our design elsewhere, we need to regerate the bsp file in NIOS. To generate the hex file, make file -> build -> mem_init_gen, remember to add this to onchip memory in platform designer.

# Peripherals used: Timer
1. Add a timer to your system using Platform Designer
2. Configure your parameters with the desired period and mode of operation.
3. In this example, we run an ISR every time the timer period is up. The ISR program includes the toggling of LED on the Cyclone 10 LP Dev Kit. 

