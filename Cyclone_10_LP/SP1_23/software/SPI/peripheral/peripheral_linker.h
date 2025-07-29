#ifndef PERIPHERAL_LINKER_H
#define PERIPHERAL_LINKER_H

#include "system.h"	// must include otherwise will not work
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
//#include "altera_avalon_timer_regs.h"
#include "sys/alt_irq.h"
#include "altera_avalon_spi.h"
#include "altera_avalon_spi_regs.h"

// function declaration
void init_timer (void);												// Initializes the timer
int spi_command (const alt_u8 * write_data, alt_u32 write_length, alt_u32 read_length, 	// SPI Command
		alt_u8 * read_data );
void delay_ms(int milliseconds);									// Simple Delay
void adc_init(void);												// Initializes the ADC
int spi_transmit_receive(alt_u32 base, alt_u32 slave,
                                    const alt_u8 *tx_buf, alt_u8 *rx_buf,
                                    alt_u32 length, alt_u32 flags);
#endif // LINKER_H
