# NIOS II STM32

This project was created to let the author gain more experience in SPI and Timer Peripherals especially interrupts. 

## Features 
1. 2 x SPIs: SPI3 and SPI6 are configured as masters and slaves respectively. Hardware NSS has been disabled, only Clock, MISO and MOSI are connected via jumper cables. 

2. 1 x Timer with interrupt. This timer is configured and when the timer elapsed, a function know as HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) will be triggered.

### HAL_SPI_Transmit_IT()
1. The usage of this API is similar to HAL_SPI_Transmit except that this is non-blocking. Additionally, this API is single-use, which means user needs to retrigger HAL_SPI_Transmit_IT if wish to perform SPI Transmit again. 

### HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi) 
1. This is a self-defined Callback function that will be called everytime HAL_SPI_Receive_IT completes its function call. Usually, we will put HAL_SPI_Transmit_IT() inside.   