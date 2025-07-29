
#include "sys/alt_stdio.h"
#include "peripheral/peripheral_linker.h"
#include "imported_source/ViCAT_LSC.h"
#include "stdint.h"
#include "system.h"				// must include otherwise will not work
int main()
{
	uint8_t out = 0;
	init_timer1();

	// Event loop that runs forever
	while (out != 1){
		out = IORD_ALTERA_AVALON_PIO_DATA(ESC_EEPDONE_BASE);
		IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE, out); // testing out
	}

	main_initial();

  return 0;
}
