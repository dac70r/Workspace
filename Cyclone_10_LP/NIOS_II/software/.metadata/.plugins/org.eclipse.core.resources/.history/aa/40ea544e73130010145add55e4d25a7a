#ifndef PERIPHERAL_LINKER_H
#define PERIPHERAL_LINKER_H

#include "system.h"	// must include otherwise will not work
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "sys/alt_irq.h"
#include "altera_avalon_spi.h"
#include "altera_avalon_spi_regs.h"

// Base addresses for peripherals (example addresses, these will depend on your actual hardware)
#define GPIO 			GPIO_BASE
#define TIMER_0			TIMER_0_BASE

// SPI Channels for Machine Learning
#define SPI0		SPI_0_BASE
//#define SPI1		SPI_1_BASE

// SPI Channel for EtherCAT Slave Controller
#define ESC_SPI		ESC_SPI_BASE

// Other Peripherals as required
#define RESET_ADC	PIO_0_BASE

// function declaration
void init_timer (void);												// Initializes the timer
int spi_command (const alt_u8 * write_data, alt_u32 write_length, alt_u32 read_length, 	// SPI Command
		alt_u8 * read_data );
void delay_ms(int milliseconds);									// Simple Delay
void adc_init(void);												// Initializes the ADC

#endif // LINKER_H
