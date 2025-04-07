
#include "sys/alt_stdio.h"
#include "peripheral/peripheral_linker.h"
#include "imported_source/ViCAT_LSC.h"
#include "stdint.h"
#include "system.h"				// must include otherwise will not work
int main()
{
	// led status will be used as ESC_SPI_NSS

	alt_u8 led_status = 0;
	alt_u32 value =0;
	uint8_t pio_data = 0;
	uint8_t bit_value = 0;
	uint8_t out = 0;

	// Event loop that runs forever
	while (1){
		out = IORD_ALTERA_AVALON_PIO_DATA(0x0);
		IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE, out);
		alt_putstr("Delay 1000ms !\n");
		led_status = ~led_status;
		alt_busy_sleep(500000);
		//main_initial();
	}

  return 0;
}
