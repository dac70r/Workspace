#ifndef __CHIP_DRIVER_CONFIG_H__
#define __CHIP_DRIVER_CONFIG_H__

#include <stdio.h>

/**
 * @brief Function Settings
 *
 */
#define AX58400 0  // use 0 for AX58100, or
#define SW_STN_ALIAS 1
#define DEVICE_ID_SWITCH 1

/**
 * @brief Platform Selection
 *
 */
#define STM32 1

#if STM32 == 1
#include "cmsis_compiler.h"
#include "gpio.h"
#include "main.h"
#include "spi.h"
#include "stm32h7xx_hal.h"
#include "tim.h"
#endif

#endif
