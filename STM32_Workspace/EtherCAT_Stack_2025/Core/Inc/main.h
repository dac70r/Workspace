/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI_CLK_Pin GPIO_PIN_5
#define SPI_CLK_GPIO_Port GPIOA
#define SPI_MISO_Pin GPIO_PIN_6
#define SPI_MISO_GPIO_Port GPIOA
#define SPI_MOSI_Pin GPIO_PIN_7
#define SPI_MOSI_GPIO_Port GPIOA
#define ESC_SYNC_L0_Pin GPIO_PIN_5
#define ESC_SYNC_L0_GPIO_Port GPIOC
#define ESC_SYNC_L0_EXTI_IRQn EXTI9_5_IRQn
#define ESC_SPI_SCS_Pin GPIO_PIN_10
#define ESC_SPI_SCS_GPIO_Port GPIOE
#define LED_OUT_Pin GPIO_PIN_14
#define LED_OUT_GPIO_Port GPIOB
#define ESC_SPI_CLK_Pin GPIO_PIN_10
#define ESC_SPI_CLK_GPIO_Port GPIOC
#define ESC_SPI_MISO_Pin GPIO_PIN_11
#define ESC_SPI_MISO_GPIO_Port GPIOC
#define ESC_SPI_MOSI_Pin GPIO_PIN_12
#define ESC_SPI_MOSI_GPIO_Port GPIOC
#define ESC_EEP_DONE_Pin GPIO_PIN_3
#define ESC_EEP_DONE_GPIO_Port GPIOD
#define ESC_SPI_SINT_Pin GPIO_PIN_4
#define ESC_SPI_SINT_GPIO_Port GPIOD
#define ESC_SYNC_L1_Pin GPIO_PIN_6
#define ESC_SYNC_L1_GPIO_Port GPIOD
#define ESC_SYNC_L1_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
