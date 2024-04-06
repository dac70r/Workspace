# Basys 3 Project Files and References

Reference manual - https://digilent.com/reference/programmable-logic/basys-3/reference-manual      

#Feature Projects: 
## Traffic Controller Project

This project was developed to gain experience working with state machines and was referenced from: https://github.com/FPGADude/Digital-Design with minor alterations. 

### From the project, it was found that you need the following important concepts

1. state machine handler - this always block defines all of the states that exist in your machine and what are the conditions to trigger the next state.

2. the outputs of each state of the machine - this always block executes the set of instructions of a given state when the state machines changes to that particular state. In this example, the instructions would be to blink a new set of leds. 