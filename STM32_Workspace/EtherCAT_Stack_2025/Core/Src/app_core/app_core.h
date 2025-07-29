#ifndef __APP_CORE_H
#define __APP_CORE_H

// #include "ads131a04.h"
// #include "ADS131A04.h"
#include "ads131a04.h"
#include "led_heartbeat.h"
#include "stdbool.h"
#include "spi.h"

#define ADS131A04 1

void AppInit(void);
void AppTimerRun(void);
bool RunReady(void);

#endif
