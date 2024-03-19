# Simulate Block RAM Functionality of Cyclone 10 LP FPGA on Nucleo_H755 Microcontroller
This project serves to validate the functional design of Block RAMs on the Cyclone 10 LP FPGA. 

The cyclone 10 LP lacks features like switches, it is difficult to manipulate the input address and data, as such, the GPIO on the FPGA is configured as inputs, based on the inputs, will determine the address to which the data will be written to. 

To validate the correctness of the design, LEDs on the Nucleo_H755 were also configured to display the data present at each address of the allocated RAM on the Cyclone 10 LP FPGA. 
