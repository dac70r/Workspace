/*
 ******************************************************************************
 *     Copyright (c) 2021	ASIX Electronic Corporation      All rights reserved.
 *
 *     This is unpublished proprietary source code of ASIX Electronic Corporation
 *
 *     The copyright notice above does not evidence any actual or intended
 *     publication of such source code.
 ******************************************************************************
 */

/* INCLUDE FILE DECLARATIONS */
#include "ecat_def.h"
#include "ecatappl.h"
#include "stm32h7xx_hal.h"

#include "main.h"
#define __SAMPLEHW__ 1
#include "ax58400_Hw.h"
#undef __SAMPLEHW__
#define __SAMPLEHW__ 0

#include "cmsis_compiler.h"
#include <stdio.h>

extern void MainLoop(void);

/* NAMING CONSTANT DECLARATIONS */
HW_SPI_IO_CONFIG HW_EscSpiIoCfig = {
  .pInstance              = HW_SPI_ESC_INSTANCE,
  .AlterFunc              = HW_SPI_ESC_GPIO_AF,
  .pCsPort                = HW_SPI_ESC_CS_PORT,
  .CsPin                  = HW_SPI_ESC_CS_PIN,	
  .pClkPort               = HW_SPI_ESC_SCLK_PORT,
  .ClkPin                 = HW_SPI_ESC_SCLK_PIN,	
  .pMisoPort              = HW_SPI_ESC_MISO_PORT,
  .MisoPin                = HW_SPI_ESC_MISO_PIN,		
  .pMosiPort              = HW_SPI_ESC_MOSI_PORT,
  .MosiPin                = HW_SPI_ESC_MOSI_PIN,		
  .pIntrPort              = HW_SPI_ESC_INT_PORT,
  .IntrPin                = HW_SPI_ESC_INT_PIN,
  .IntrIrq                = HW_SPI_ESC_INT_IRQ,
  .IntrPrePrio            = HW_SPI_ESC_INT_NVIC_PREEMPTION_PRIORITY,
  .IntrSubPrio            = HW_SPI_ESC_INT_NVIC_SUB_PRIORITY,
  .Enable3BytesAddr       = 1,
  .Baudrate               = SPI_BAUDRATEPRESCALER_16,
};

HW_SPI_IO_CONFIG HW_FunSpiIoCfig = {
  .pInstance              = HW_SPI_ESC_INSTANCE,
  .AlterFunc              = HW_SPI_ESC_GPIO_AF,	
  .pCsPort                = HW_SPI_FUN_CS_PORT,
  .CsPin                  = HW_SPI_FUN_CS_PIN,
  .pClkPort               = HW_SPI_ESC_SCLK_PORT,
  .ClkPin                 = HW_SPI_ESC_SCLK_PIN,	
  .pMisoPort              = HW_SPI_ESC_MISO_PORT,
  .MisoPin                = HW_SPI_ESC_MISO_PIN,		
  .pMosiPort              = HW_SPI_ESC_MOSI_PORT,
  .MosiPin                = HW_SPI_ESC_MOSI_PIN,		
  .pIntrPort              = HW_SPI_ESC_INT_PORT,
  .IntrPin                = HW_SPI_ESC_INT_PIN,
  .IntrIrq                = HW_SPI_ESC_INT_IRQ,
  .IntrPrePrio            = HW_SPI_ESC_INT_NVIC_PREEMPTION_PRIORITY,
  .IntrSubPrio            = HW_SPI_ESC_INT_NVIC_SUB_PRIORITY,
  .Enable3BytesAddr       = 0,
  .Baudrate               = SPI_BAUDRATEPRESCALER_16,
};

/* MACRO DECLARATIONS */

#if INTERRUPTS_SUPPORTED
/*-----------------------------------------------------------------------------------------
------
------    Global Interrupt setting
------
-----------------------------------------------------------------------------------------*/
#define DISABLE_GLOBAL_INT             do {__set_PRIMASK(1);} while (0)
#define ENABLE_GLOBAL_INT              do {__set_PRIMASK(0);} while (0)
#if AX58400_INTR_QUEUE_ENABLE
#define DISABLE_AL_EVENT_INT
#define ENABLE_AL_EVENT_INT
#else
#define DISABLE_AL_EVENT_INT           do {__set_PRIMASK(1);} while (0)
#define ENABLE_AL_EVENT_INT            do {__set_PRIMASK(0);} while (0)
#endif
/*-----------------------------------------------------------------------------------------
------
------    SYNC0 Interrupt
------
-----------------------------------------------------------------------------------------*/
#if DC_SUPPORTED

#define DISABLE_SYNC0_INT
#define ENABLE_SYNC0_INT

#define DISABLE_SYNC1_INT
#define ENABLE_SYNC1_INT

#endif //#if DC_SUPPORTED

#endif //#if INTERRUPTS_SUPPORTED

#define HW_PHY_SETUP

/* TYPE DECLARATIONS */
typedef union
{
   unsigned short   Word;
   unsigned char    Byte[2];
} UBYTETOWORD;

typedef union 
{
   UINT8           Byte[2];
   UINT16          Word;
} UALEVENT;

/* GLOBAL VARIABLES DECLARATIONS */
#if AX58400_DEBUG_ENABLE
HW_DEBUG  HW_Debug = {0};
#endif

HW_SPI_OBJECT      HW_SpiObj[HW_PDI_NUM];
TIM_HandleTypeDef  TimeTick_Handle;
TIM_HandleTypeDef  TimeTask_Handle;
INTR_QUEUE         Intr;
UINT32             HW_PdiReentryCnt[HW_PDI_NUM] = {0,0};
UINT8              HW_LockFlag[HW_PDI_NUM] = {0,0};

extern UINT8	bootSwitchID;

/* LOCAL VARIABLES DECLARATIONS */

 //Contains the content of the ALEvent register (0x220), this variable is updated on each Access to the Esc
UALEVENT           EscALEvent;

/* LOCAL SUBPROGRAM DECLARATIONS */
static INT32 HW_SPI_Init(HW_SPI_OBJECT* pSpiObj);
static INT32 HW_SPI_DeInit(HW_SPI_OBJECT* pSpiObj);
static void HW_SPI_Read(HW_SPI_OBJECT* pSpiObj, UINT8 *pBuf, UINT16 Addr, UINT16 ByteLen);
static void HW_SPI_Write(HW_SPI_OBJECT* pSpiObj, UINT8 *pData, UINT16 Addr, UINT16 ByteLen);
static INT32 HW_CheckVendorProductID(void);

/* LOCAL SUBPROGRAM BODIES */
/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_GPIO_ClkSource()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_GPIO_ClkSource(GPIO_TypeDef* GpioPort, UINT8 NewState)
{
	if (GpioPort == GPIOA)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOA_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOA_CLK_DISABLE();
		}
	}
	else if  (GpioPort == GPIOB)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOB_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOB_CLK_DISABLE();
		}
	}
	else if  (GpioPort == GPIOC)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOC_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOC_CLK_DISABLE();
		}
	}
	else if  (GpioPort == GPIOD)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOD_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOD_CLK_DISABLE();
		}
	}
	else if  (GpioPort == GPIOE)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOE_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOE_CLK_DISABLE();
		}
	}	
	else if  (GpioPort == GPIOF)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOF_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOF_CLK_DISABLE();
		}
	}
	else if  (GpioPort == GPIOG)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOG_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOG_CLK_DISABLE();
		}
	}
	else if  (GpioPort == GPIOH)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_GPIOH_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_GPIOH_CLK_DISABLE();
		}
	}
	else
	{
		ESC_DEBUG("Unsupported GPIO clock source.(0x%lx)\r\n", (u32)GpioPort);
	}

} /* End of HW_GPIO_ClkSource() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_TIM_ClkSource()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_TIM_ClkSource(TIM_TypeDef* Instance, UINT8 NewState)
{
	if (Instance == TIM1)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM1_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM1_CLK_DISABLE();
		}
	}
	else if (Instance == TIM2)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM2_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM2_CLK_DISABLE();
		}
	}
	else if (Instance == TIM3)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM3_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM3_CLK_DISABLE();
		}
	}
	else if (Instance == TIM4)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM4_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM4_CLK_DISABLE();
		}
	}
	else if (Instance == TIM6)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM6_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM6_CLK_DISABLE();
		}
	}
	else if (Instance == TIM7)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM7_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM7_CLK_DISABLE();
		}
	}	
	else if (Instance == TIM8)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM8_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM8_CLK_DISABLE();
		}
	}		
	else if (Instance == TIM12)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM12_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM12_CLK_DISABLE();
		}
	}	
	else if (Instance == TIM13)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM13_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM13_CLK_DISABLE();
		}
	}
	else if (Instance == TIM14)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM14_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM14_CLK_DISABLE();
		}
	}
	else if (Instance == TIM15)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM15_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM15_CLK_DISABLE();
		}
	}
	else if (Instance == TIM16)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM16_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM16_CLK_DISABLE();
		}
	}	
	else if (Instance == TIM17)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_TIM17_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_TIM17_CLK_DISABLE();
		}
	}		
	else
	{
		ESC_DEBUG("Unsupported TMR clock source.(0x%lx)\r\n", (u32)Instance);
		return;
	}
} /* End of HW_TIM_ClkSource() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_ClkSource()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_SPI_ClkSource(SPI_TypeDef* Instance, UINT8 NewState)
{
	if (Instance == SPI1)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_SPI1_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_SPI1_CLK_DISABLE();
		}
	}		
	else if (Instance == SPI2)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_SPI2_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_SPI2_CLK_DISABLE();
		}
	}
	else if (Instance == SPI3)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_SPI3_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_SPI3_CLK_DISABLE();
		}
	}
	else if (Instance == SPI4)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_SPI4_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_SPI4_CLK_DISABLE();
		}
	}
	else if (Instance == SPI5)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_SPI5_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_SPI5_CLK_DISABLE();
		}
	}
	else if (Instance == SPI6)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_SPI6_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_SPI6_CLK_DISABLE();
		}
	}	
	else
	{
		ESC_DEBUG("Unsupported SPI clock source.(0x%lx)\r\n", (u32)Instance);
		return;
	}
} /* End of HW_SPI_ClkSource() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_UART_ClkSource()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_UART_ClkSource(USART_TypeDef* Instance, UINT8 NewState)
{
	if (Instance == USART1)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_USART1_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_USART1_CLK_DISABLE();
		}
	}		
	else if (Instance == USART2)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_USART2_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_USART2_CLK_DISABLE();
		}
	}		
	else if (Instance == USART3)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_USART3_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_USART3_CLK_DISABLE();
		}
	}
	else if (Instance == UART4)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_UART4_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_UART4_CLK_DISABLE();
		}
	}
	else if (Instance == UART5)
	{
		if (NewState == ENABLE)
		{
			__HAL_RCC_UART5_CLK_ENABLE();
		}
		else
		{
			__HAL_RCC_UART5_CLK_DISABLE();
		}
	}			
	else
	{
		ESC_DEBUG("Unsupported UART/USART clock source.(0x%lx)\r\n", (u32)Instance);
		return;
	}
} /* End of HW_UART_ClkSource() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_PeriphForceReset()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_SPI_PeriphForceReset(SPI_TypeDef* Instance)
{
	if (Instance == SPI1)
	{
		__HAL_RCC_SPI1_FORCE_RESET();
	}
	else if (Instance == SPI2)
	{
		__HAL_RCC_SPI2_FORCE_RESET();
	}
	else if (Instance == SPI3)
	{
		__HAL_RCC_SPI3_FORCE_RESET();
	}
	else if (Instance == SPI4)
	{
		__HAL_RCC_SPI4_FORCE_RESET();
	}
	else
	{
		ESC_DEBUG("ForceReset SPI instance fail.(0x%lx)\r\n", (u32)Instance);
	}
} /* End of HW_SPI_PeriphForceReset() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_PeriphReleaseReset()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_SPI_PeriphReleaseReset(SPI_TypeDef* Instance)
{
	if (Instance == SPI1)
	{
		__HAL_RCC_SPI1_RELEASE_RESET();
	}
	else if (Instance == SPI2)
	{
		__HAL_RCC_SPI2_RELEASE_RESET();
	}
	else if (Instance == SPI3)
	{
		__HAL_RCC_SPI3_RELEASE_RESET();
	}
	else if (Instance == SPI4)
	{
		__HAL_RCC_SPI4_RELEASE_RESET();
	}
	else
	{
		ESC_DEBUG("ReleaseReset SPI instance fail.(0x%lx)\r\n", (u32)Instance);
	}
} /* End of HW_SPI_PeriphReleaseReset() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_Init()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
static INT32 HW_SPI_Init(HW_SPI_OBJECT* pSpiObj)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	HW_SPI_IO_CONFIG  *pSpiIoCfg = pSpiObj->pIoCfg;
	SPI_HandleTypeDef *pSpiHandle = &pSpiObj->Handle;
	
	/* Enable SPI clock source */
	HW_SPI_ClkSource(pSpiIoCfg->pInstance, ENABLE);

	/* SPI CS GPIO pin configuration  */
	HW_GPIO_ClkSource(pSpiIoCfg->pCsPort, ENABLE);
	GPIO_InitStructure.Pin = pSpiIoCfg->CsPin;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(pSpiIoCfg->pCsPort, &GPIO_InitStructure);

	/* SPI CLK GPIO pin configuration  */
	HW_GPIO_ClkSource(pSpiIoCfg->pClkPort, ENABLE);	
	GPIO_InitStructure.Pin = pSpiIoCfg->ClkPin;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Alternate = pSpiIoCfg->AlterFunc;
	HAL_GPIO_Init(pSpiIoCfg->pClkPort, &GPIO_InitStructure);

	/* SPI MISO GPIO pin configuration  */
	HW_GPIO_ClkSource(pSpiIoCfg->pMisoPort, ENABLE);	
	GPIO_InitStructure.Pin = pSpiIoCfg->MisoPin;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Alternate = pSpiIoCfg->AlterFunc;
	HAL_GPIO_Init(pSpiIoCfg->pMisoPort, &GPIO_InitStructure);
	
	/* SPI MOSI GPIO pin configuration  */
	HW_GPIO_ClkSource(pSpiIoCfg->pMosiPort, ENABLE);	
	GPIO_InitStructure.Pin = pSpiIoCfg->MosiPin;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Alternate = pSpiIoCfg->AlterFunc;
	HAL_GPIO_Init(pSpiIoCfg->pMosiPort, &GPIO_InitStructure);

#if AL_EVENT_ENABLED
	/* Configure GPIO as SPI interrupt input */
	HW_GPIO_ClkSource(pSpiIoCfg->pIntrPort, ENABLE);	
	GPIO_InitStructure.Pin = pSpiIoCfg->IntrPin;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(pSpiIoCfg->pIntrPort, &GPIO_InitStructure);
	
	/* Enable SPI interrupt source at NVIC */
	HAL_NVIC_SetPriorityGrouping(HW_NVIC_PRIORITY_GROUP);
	HAL_NVIC_SetPriority(pSpiIoCfg->IntrIrq, pSpiIoCfg->IntrPrePrio, pSpiIoCfg->IntrSubPrio);
	HAL_NVIC_EnableIRQ(pSpiIoCfg->IntrIrq);
#endif

	/* Configure SPI peripheral */
	pSpiHandle->Instance = pSpiIoCfg->pInstance;

	/* Reset the SPI memory interface */	
	pSpiHandle->Init.Mode = SPI_MODE_MASTER;
	pSpiHandle->Init.Direction = SPI_DIRECTION_2LINES;
	pSpiHandle->Init.DataSize = SPI_DATASIZE_8BIT;	
	pSpiHandle->Init.CLKPolarity = SPI_POLARITY_HIGH;		
	pSpiHandle->Init.CLKPhase = SPI_PHASE_2EDGE;
	pSpiHandle->Init.NSS = SPI_NSS_SOFT;	
	pSpiHandle->Init.BaudRatePrescaler = pSpiIoCfg->Baudrate;
	pSpiHandle->Init.FirstBit = SPI_FIRSTBIT_MSB;
	pSpiHandle->Init.TIMode = SPI_TIMODE_DISABLE;	
	pSpiHandle->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	pSpiHandle->Init.CRCPolynomial = 0;
	pSpiHandle->Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
	pSpiHandle->Init.FifoThreshold = SPI_FIFO_THRESHOLD_04DATA;
	
	/* Enable SPI periphral */
	if (HAL_SPI_Init(pSpiHandle) != HAL_OK)
	{
		return -1;
	}
	
	/* Initialize CS pin(s) as idle state */
	HAL_GPIO_WritePin(pSpiIoCfg->pCsPort, pSpiIoCfg->CsPin, GPIO_PIN_SET);

	return 0;
} /* End of HW_SPI_Init() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_DeInit()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
static INT32 HW_SPI_DeInit(HW_SPI_OBJECT* pSpiObj)
{
	return 0;
} /* End of HW_SPI_DeInit() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_WaitFlagStateUntilTimeout()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
static INT32 HW_SPI_WaitFlagStateUntilTimeout(HW_SPI_OBJECT* pSpiObj, UINT32 Flag, UINT32 State, UINT32 Timeout, UINT32 Tickstart)
{
	SPI_HandleTypeDef* hspi = &(pSpiObj->Handle);
	
  while ((__HAL_SPI_GET_FLAG(hspi, Flag) ? SET : RESET) != State)
	{
		if(HW_CheckTimeout(Tickstart, Timeout))
		{
			/* Disable TXE, RXNE and ERR interrupts for the interrupt process */
			__HAL_SPI_DISABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_RXNE | SPI_IT_ERR));

			/* Disable SPI peripheral */
			__HAL_SPI_DISABLE(hspi);
			ESC_DEBUG("SPI wait flag(0x%x) timeout!\r\n", Flag);
			return -1;
		}
	}
	return 0;
} /* End of HW_SPI_WaitFlagStateUntilTimeout() */

static void HW_SPI_CloseTransfer(SPI_HandleTypeDef *hspi)
{
  uint32_t itflag = hspi->Instance->SR;

  __HAL_SPI_CLEAR_EOTFLAG(hspi);
  __HAL_SPI_CLEAR_TXTFFLAG(hspi);

  /* Disable SPI peripheral */
  __HAL_SPI_DISABLE(hspi);

  /* Disable ITs */
  __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_EOT | SPI_IT_TXP | SPI_IT_RXP | SPI_IT_DXP | SPI_IT_UDR | SPI_IT_OVR | SPI_IT_FRE | SPI_IT_MODF));

  /* Disable Tx DMA Request */
  CLEAR_BIT(hspi->Instance->CFG1, SPI_CFG1_TXDMAEN | SPI_CFG1_RXDMAEN);

  /* Report UnderRun error for non RX Only communication */
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    if ((itflag & SPI_FLAG_UDR) != 0UL)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_UDR);
      __HAL_SPI_CLEAR_UDRFLAG(hspi);
    }
  }

  /* Report OverRun error for non TX Only communication */
  if (hspi->State != HAL_SPI_STATE_BUSY_TX)
  {
    if ((itflag & SPI_FLAG_OVR) != 0UL)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_OVR);
      __HAL_SPI_CLEAR_OVRFLAG(hspi);
    }

#if (USE_SPI_CRC != 0UL)
    /* Check if CRC error occurred */
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
      if ((itflag & SPI_FLAG_CRCERR) != 0UL)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
        __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
      }
    }
#endif /* USE_SPI_CRC */
  }

  /* SPI Mode Fault error interrupt occurred -------------------------------*/
  if ((itflag & SPI_FLAG_MODF) != 0UL)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_MODF);
    __HAL_SPI_CLEAR_MODFFLAG(hspi);
  }

  /* SPI Frame error interrupt occurred ------------------------------------*/
  if ((itflag & SPI_FLAG_FRE) != 0UL)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FRE);
    __HAL_SPI_CLEAR_FREFLAG(hspi);
  }

  hspi->TxXferCount = (uint16_t)0UL;
  hspi->RxXferCount = (uint16_t)0UL;
}

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_TransmitReceive()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
static INT32 HW_SPI_TransmitReceive(HW_SPI_OBJECT* pSpiObj, UINT8 *pTxData, UINT8 *pRxData, UINT16 Size, UINT32 Timeout)
{
	HW_SPI_IO_CONFIG* pSpiIoCfg = pSpiObj->pIoCfg;		
  SPI_TypeDef *pInst = pSpiObj->Handle.Instance;
  int32_t errorcode = HAL_OK;

  /* Init tickstart for timeout management*/	
  uint32_t   tickstart = HW_GetTimer();
	
  uint16_t   initial_TxXferCount = Size;
  uint16_t   initial_RxXferCount = Size;

  MODIFY_REG(pInst->CR2, SPI_CR2_TSIZE, 0);
	
	/* Check if the SPI is already enabled */
	if ((pInst->CR1 & SPI_CR1_SPE) == 0)
	{
		/* Enable SPI peripheral */
		pInst->CR1 |= SPI_CR1_SPE;
	}	
	pInst->CR1 |= SPI_CR1_CSTART;	

	/* CS = low */	
	pSpiIoCfg->pCsPort->ODR &= ~(pSpiIoCfg->CsPin);

	/* Transmit and Receive data in 8 Bit mode */
	if(initial_TxXferCount == 0x01)
	{
		*((__IO uint8_t*)&(pInst->TXDR)) = (*pTxData);
		pTxData += sizeof(uint8_t);
		initial_TxXferCount--;
	}	
	
    while ((initial_TxXferCount > 0UL) || (initial_RxXferCount > 0UL))
    {
      /* check TXP flag */
	  if ((pInst->SR & SPI_FLAG_TXP) && (initial_TxXferCount > 0UL))
      {
        if (initial_TxXferCount > 3UL)
        {
          *((__IO uint32_t *)&pInst->TXDR) = *((uint32_t *)pTxData);					
					pTxData += sizeof(uint32_t);
					initial_TxXferCount -= (uint16_t)4UL;
        }
        else if (initial_TxXferCount > 1UL)
        {
          *((__IO uint16_t *)&pInst->TXDR) = *((uint16_t *)pTxData);
					pTxData += sizeof(uint16_t);				
					initial_TxXferCount -= (uint16_t)2UL;	
        }
        else
        {
          *((__IO uint8_t *)&pInst->TXDR) = *((uint8_t *)pTxData);
					pTxData += sizeof(uint8_t);
					initial_TxXferCount--;					
        }
      }

      /* Wait until RXWNE/FRLVL flag is reset */
	  if ((pInst->SR & (SPI_FLAG_RXWNE | SPI_FLAG_FRLVL | SPI_FLAG_RXP)) && (initial_RxXferCount > 0UL))
      {						
				if ((pInst->SR & SPI_FLAG_RXWNE) != 0UL)
        {
          (*(uint32_t *)pRxData) = *((__IO uint32_t *)&pInst->RXDR);
					pRxData += sizeof(uint32_t);
          initial_RxXferCount -= (uint16_t)4UL;
        }
        else if ((pInst->SR & SPI_FLAG_FRLVL) > SPI_RX_FIFO_1PACKET)
        {
          (*(uint16_t *)pRxData) = *((__IO uint16_t *)&pInst->RXDR);					
					pRxData += sizeof(uint16_t);				
          initial_RxXferCount -= (uint16_t)2UL;
        }
        else
        {
          (*(uint8_t *)pRxData) = *((__IO uint8_t *)&pInst->RXDR);
					pRxData += sizeof(uint8_t);
          initial_RxXferCount--;					
        }
      }

      /* Timeout management */
	  if(HW_CheckTimeout(tickstart, Timeout))
	  {
	 	ESC_DEBUG("SPI xfer timeout!(%04x->%04x > %04x)\r\n", (UINT16)tickstart, HW_GetTimer(), (UINT16)Timeout);
		ESC_DEBUG("TxXferCount=%u, RxXferCount=%u\r\n", initial_TxXferCount, initial_RxXferCount);

		errorcode = -2;
		goto HW_SPI_XferError;
      }
    }

	/* Wait until TXE flag */
  if (HW_SPI_WaitFlagStateUntilTimeout(pSpiObj, SPI_FLAG_TXC, SET, Timeout, tickstart) < 0)
  {
		ESC_DEBUG("SPI wait TXE timeout!\r\n");		
		errorcode = -3;
		goto HW_SPI_XferError;		
  }
#if 0
	/* Check Busy flag */
	if(HW_SPI_WaitFlagStateUntilTimeout(pSpiObj, SPI_FLAG_EOT, SET, Timeout, tickstart) < 0)
	{
		ESC_DEBUG("SPI wait BSY timeout!\r\n");
		errorcode = -4;
		goto HW_SPI_XferError;
	}
#endif	

HW_SPI_XferError:
	/* Clear overrun flag in 2 Lines communication mode because received is not read */
	pInst->IFCR |= SPI_IFCR_OVRC|SPI_IFCR_UDRC|SPI_IFCR_EOTC|SPI_IFCR_TIFREC;
	
	/* CS = high */	
	pSpiIoCfg->pCsPort->ODR |= pSpiIoCfg->CsPin;
	
  return errorcode;		
} /* End of HW_SPI_TransmitReceive() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_Read()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
static void HW_SPI_Read(HW_SPI_OBJECT* pSpiObj, UINT8 *pBuf, UINT16 Addr, UINT16 ByteLen)
{
	HW_SPI_IO_CONFIG* pSpiIoCfg = pSpiObj->pIoCfg;
	UINT16 XferLen, AddrTmp, i;
	UINT8 *ptr, DataOffset = 0;
	INT32 ret;
	
	if ((pSpiObj->pLock!=0) && (*(pSpiObj->pLock)))
	{
		if (pSpiObj->pPdiReentryCnt)
		{
			*(pSpiObj->pPdiReentryCnt) += 1;
		}
		return;
	}
	*(pSpiObj->pLock) = 1;
	
	while (ByteLen)
	{
		AddrTmp = Addr;
		
		/* Fragmented to specified data length per-section */
		if (ByteLen > HW_SPI_MAX_DATA_FRAGMENT_SIZE)
		{
			XferLen = HW_SPI_MAX_DATA_FRAGMENT_SIZE;
		}
		else
		{
			XferLen = ByteLen;
		}

		/* Set address, command */
		ptr = (UINT8*)&AddrTmp;
		if (pSpiIoCfg->Enable3BytesAddr)
		{
			pSpiObj->TxBuf[2] = (ptr[1] & 0xe0) | (HW_SPI_READ_WITH_WAIT_CMD << 2);
			AddrTmp = AddrTmp << 3;
			pSpiObj->TxBuf[0] = ptr[1];
			pSpiObj->TxBuf[1] = ptr[0] | HW_SPI_ADDR_EXT_CMD;
			DataOffset = 3;
		}
		else
		{
			AddrTmp = AddrTmp << 3;
			pSpiObj->TxBuf[0] = ptr[1];
			pSpiObj->TxBuf[1] = ptr[0] | HW_SPI_READ_WITH_WAIT_CMD;
			DataOffset = 2;
		}
		
		/* Set dummy byte */
		pSpiObj->TxBuf[DataOffset] = 0xff;
			
		/* Set read terminal byte */
		memset(&pSpiObj->TxBuf[DataOffset+1], 0, XferLen);
		pSpiObj->TxBuf[DataOffset + XferLen] = 0xff;
		DataOffset++;
		
		ret = HW_SPI_TransmitReceive(pSpiObj, pSpiObj->TxBuf, pSpiObj->RxBuf, DataOffset + XferLen, HW_SPI_XFER_TIMEOUT);
		/* Start read */
		if (ret != 0)		
		{
			break;
		}
		
		/* Store received data */
		for (i=0; i<XferLen; i++)
		{
			pBuf[i] = pSpiObj->RxBuf[DataOffset + i];
		}
		
		/* Next section */
		Addr += XferLen;
		pBuf += XferLen;
		ByteLen -= XferLen;
	}

	*(pSpiObj->pLock) = 0;	
	return;	
} /* End of HW_SPI_Read() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_SPI_Write()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
static void HW_SPI_Write(HW_SPI_OBJECT* pSpiObj, UINT8 *pData, UINT16 Addr, UINT16 ByteLen)
{
	HW_SPI_IO_CONFIG* pSpiIoCfg = pSpiObj->pIoCfg;	
	UINT16 XferLen, AddrTmp;
	UINT8 *ptr, DataOffset;
	INT32 ret;
	
	if ((pSpiObj->pLock!=0) && (*(pSpiObj->pLock)))
	{
		if (pSpiObj->pPdiReentryCnt)
		{		
			*(pSpiObj->pPdiReentryCnt) += 1;
		}
		return;
	}
	*(pSpiObj->pLock) = 1;
	
	while (ByteLen)
	{
		AddrTmp = Addr;

		/* Fragmented to specified data length per-section */
		if (ByteLen > HW_SPI_MAX_DATA_FRAGMENT_SIZE)
		{
			XferLen = HW_SPI_MAX_DATA_FRAGMENT_SIZE;
		}
		else
		{
			XferLen = ByteLen;
		}
		
		/* Set address , command */
		ptr = (UINT8*)&AddrTmp;
		if (pSpiIoCfg->Enable3BytesAddr)
		{		
			pSpiObj->TxBuf[2] = (ptr[1] & 0xe0) | (HW_SPI_WRITE_CMD << 2);		
			AddrTmp = AddrTmp << 3;
			pSpiObj->TxBuf[0] = ptr[1];
			pSpiObj->TxBuf[1] = ptr[0] | HW_SPI_ADDR_EXT_CMD;			
			DataOffset = 3;
		}
		else
		{
			AddrTmp = AddrTmp << 3;
			pSpiObj->TxBuf[0] = ptr[1];
			pSpiObj->TxBuf[1] = ptr[0] | HW_SPI_WRITE_CMD;			
			DataOffset = 2;			
		}
		
		/* Set transmit data bytes */
		memcpy(&(pSpiObj->TxBuf[DataOffset]), pData, XferLen);
		DataOffset++;
		
		/* Start write */
		ret = HW_SPI_TransmitReceive(pSpiObj, pSpiObj->TxBuf, pSpiObj->RxBuf, (DataOffset - 1) + XferLen, HW_SPI_XFER_TIMEOUT);
		if (ret != 0)
		{
			break;
		}
		
		Addr += XferLen;
		pData += XferLen;	
		ByteLen -= XferLen;
	}
	
	*(pSpiObj->pLock) = 0;
	return;		
} /* End of HW_SPI_Write() */

/**
  * @brief  The function operates a SPI access without addressing. 
  * @note   The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).
  *         It will be saved in the global "EscALEvent"
  * @param  None
  * @retval None
  */
static void GetInterruptRegister(void)
{
		HW_EscRead((MEM_ADDR*)EscALEvent.Byte, ESC_AL_EVENT_OFFSET, 2);
}

/**
  * @brief  The function operates a SPI access without addressing.
  * @note   Shall be implemented if interrupts are supported else this function is equal to "GetInterruptRegsiter()"
  * @note   The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).
  *         It will be saved in the global "EscALEvent"
  * @param  None
  * @retval None
  */
#if !INTERRUPTS_SUPPORTED
#define ISR_GetInterruptRegister GetInterruptRegister
#else
static void ISR_GetInterruptRegister(void)
{
		HW_EscReadIsr((MEM_ADDR*)EscALEvent.Byte, ESC_AL_EVENT_OFFSET, 2);
}
#endif //#else #if !INTERRUPTS_SUPPORTED

/* EXPORTED SUBPROGRAM BODIES */
#ifdef HW_PHY_SETUP
void HW_MiiPdiAccess(BOOL enable)
{
	UINT8	tmp8;
	
	if (enable) {
		tmp8 = 0x01;
	} else {
		tmp8 = 0x00;
	}
	HW_EscWriteByte(tmp8, 0x0517);
}

void HW_MiiWaitReady(void)
{
	UINT8	tmp8;
	
	/*
		Confirm the last command was successful
	    and current MII interface is idle.
	*/
	do {
		HW_EscReadByte(tmp8, 0x0511);
		if ((tmp8 & 0xC0) == 0x00) {
			break;
		}
	} while (1);
}

UINT16 HW_MiiPhyRead(UINT8 phyAddr, UINT8 page, UINT8 regAddr)
{
	UINT8	pageRegAddr = 0x1F;
	UINT8	opRead = 0x01;
	UINT8	opWrite = 0x02;
	UINT16	tmp16;
	
	/* Select page */
	HW_EscWriteByte(phyAddr, 0x0512);
	HW_EscWriteByte(pageRegAddr, 0x0513);
	HW_EscWriteWord(page, 0x0514);
	HW_EscWriteByte(opWrite, 0x0511);
	HW_MiiWaitReady();
	
	/* Read data from PHY register */
	HW_EscWriteByte(phyAddr, 0x0512);
	HW_EscWriteByte(regAddr, 0x0513);
	HW_EscWriteByte(opRead, 0x0511);
	HW_MiiWaitReady();
	HW_EscReadWord(tmp16, 0x0514);
	return tmp16;
}

void HW_MiiPhyWrite(UINT8 phyAddr, UINT8 page, UINT8 regAddr, UINT16 regValue)
{
	UINT8	pageRegAddr = 0x1F;
//	UINT8	opRead = 0x01;
	UINT8	opWrite = 0x02;
//	UINT16	tmp16;
	
	/* Select page */
	HW_EscWriteByte(phyAddr, 0x0512);
	HW_EscWriteByte(pageRegAddr, 0x0513);
	HW_EscWriteWord(page, 0x0514);
	HW_EscWriteByte(opWrite, 0x0511);
	HW_MiiWaitReady();
	
	/* Write data to PHY register */
	HW_EscWriteWord(regValue, 0x0514);
	HW_EscWriteByte(phyAddr, 0x0512);
	HW_EscWriteByte(regAddr, 0x0513);
	HW_EscWriteByte(opWrite, 0x0511);
	HW_MiiWaitReady();
}
#endif
/**
  * @brief  This function intialize the Process Data Interface (PDI) and the host controller.
  * @param  None
  * @retval 0 if initialization was successful
  */
UINT8 HW_Init(void)
{
	UINT32            intMask;
	UINT16            tmp16;	
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	__HAL_RCC_SYSCFG_CLK_ENABLE();
#if AX58400_DEBUG_ENABLE
	memset(&HW_Debug, 0, sizeof(HW_Debug));		
#endif	
	/* Initialize PDIs */
//	memset(&HW_SpiObj[HW_FUN_PDI], 0, sizeof(HW_SPI_OBJECT));
//	HW_SpiObj[HW_FUN_PDI].pIoCfg = &HW_FunSpiIoCfig;
//	HW_SpiObj[HW_FUN_PDI].pLock = &HW_LockFlag[HW_ESC_PDI];
//	HW_SpiObj[HW_FUN_PDI].pPdiReentryCnt = &HW_PdiReentryCnt[HW_ESC_PDI];	
//	HW_SPI_Init(&HW_SpiObj[HW_FUN_PDI]);

	memset(&HW_SpiObj[HW_ESC_PDI], 0, sizeof(HW_SPI_OBJECT));
	HW_SpiObj[HW_ESC_PDI].pIoCfg = &HW_EscSpiIoCfig;
	HW_SpiObj[HW_ESC_PDI].pLock = &HW_LockFlag[HW_ESC_PDI];
	HW_SpiObj[HW_ESC_PDI].pPdiReentryCnt = &HW_PdiReentryCnt[HW_ESC_PDI];	
	HW_SPI_Init(&HW_SpiObj[HW_ESC_PDI]);
#if 0
	/* Enable Indicator GPIOs */
	HW_GPIO_ClkSource(HW_RUNLED_PORT, ENABLE);
	GPIO_InitStructure.Pin = HW_RUNLED_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(HW_RUNLED_PORT, &GPIO_InitStructure);

	HW_GPIO_ClkSource(HW_ERRLED_PORT, ENABLE);
	GPIO_InitStructure.Pin = HW_ERRLED_PIN;
	HAL_GPIO_Init(HW_ERRLED_PORT, &GPIO_InitStructure);
#endif
	/* Enable time tick peripheral */
	TimeTick_Handle.Instance = HW_TIMETICK_INSTANCE;
	HW_TIM_ClkSource(TimeTick_Handle.Instance, ENABLE);
	TimeTick_Handle.Init.Prescaler = HW_TIMETICK_PRESCALER;
	TimeTick_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimeTick_Handle.Init.Period = HW_TIMETICK_PRELOAD;
	TimeTick_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimeTick_Handle.Init.RepetitionCounter = 0;
	TimeTick_Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_Base_Init(&TimeTick_Handle);
	/* Start time tick */	
	HAL_TIM_Base_Start(&TimeTick_Handle);

	/* Enable EEPROM done GPIO */
	HW_GPIO_ClkSource(HW_EEPROM_PORT, ENABLE);
	GPIO_InitStructure.Pin = HW_EEPROM_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;	
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(HW_EEPROM_PORT, &GPIO_InitStructure);

	/* Wait ESC ready by checking EEPDONE pin goes high */
	tmp16 = HW_GetTimer();
	do
	{
		if (HW_CheckTimeout(tmp16, HW_EEPROM_RELOAD_TIMEOUT))
		{
			return 1;
		}
	} while (HAL_GPIO_ReadPin(HW_EEPROM_PORT, HW_EEPROM_PIN) == GPIO_PIN_RESET);

	do
	{
		intMask = 0x93;
		HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
		intMask = 0;
		HW_EscReadDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
	} while (intMask != 0x93);

	intMask = 0x00;
	HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);

	/* Check Chip ID */
	if (HW_CheckVendorProductID() < 0)
	{
		return 2;
	}
#ifdef HW_PHY_SETUP
	/* Enable PDI access of MII management */
	HW_MiiPdiAccess(TRUE);
	
	/*
		Change w4_init value of Page0_0x1Eh[15:14]
	*/
	/* Port0 */
	tmp16 = HW_MiiPhyRead(0, 0x00, 0x1E);
//	ESC_DEBUG("Original Page0_0x1Eh of Port0 = 0x%04x\r\n", tmp16);
	HW_MiiPhyWrite(0, 0x00, 0x1E, (tmp16 | 0x4000));
	tmp16 = HW_MiiPhyRead(0, 0x00, 0x1E);
//	ESC_DEBUG("New Page0_0x1Eh of Port0 = 0x%04x\r\n", tmp16);
	/* Port1 */
	tmp16 = HW_MiiPhyRead(1, 0x00, 0x1E);
//	ESC_DEBUG("Original Page0_0x1Eh of Port1 = 0x%04x\r\n", tmp16);
	HW_MiiPhyWrite(1, 0x00, 0x1E, (tmp16 | 0x4000));
	tmp16 = HW_MiiPhyRead(1, 0x00, 0x1E);
//	ESC_DEBUG("New Page0_0x1Eh of Port1 = 0x%04x\r\n", tmp16);

	/* Restart auto negotiation for port0 and port1 */
	tmp16 = HW_MiiPhyRead(0, 0, 0x00);
	HW_MiiPhyWrite(0, 0, 0x00, (tmp16 | 0x0200));
//	ESC_DEBUG("Restart auto-negotiation for Port0.\r\n");
	tmp16 = HW_MiiPhyRead(1, 0, 0x00);
	HW_MiiPhyWrite(1, 0, 0x00, (tmp16 | 0x0200));
//	ESC_DEBUG("Restart auto-negotiation for Port1.\r\n");

	/* Disable PDI access of MII management */
	HW_MiiPdiAccess(FALSE);
#endif

	/* Enable interrupt */
	memset(&Intr, 0, sizeof(Intr));
	
#if AL_EVENT_ENABLED
	/* Enable ESC interrupt */	
	ENABLE_ESC_INT();
#endif	

#if DC_SUPPORTED
	/* Enable SYNC0 GPIO */
	HW_GPIO_ClkSource(HW_SYNC0_PORT, ENABLE);
	GPIO_InitStructure.Pin = HW_SYNC0_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(HW_SYNC0_PORT, &GPIO_InitStructure);

	/* Enable SYNC0 interrupt source at NVIC */	
	HAL_NVIC_SetPriorityGrouping(HW_NVIC_PRIORITY_GROUP);
	HAL_NVIC_SetPriority(HW_SYNC0_IRQ, HW_SYNC0_NVIC_PREEMPTION_PRIORITY, HW_SYNC0_NVIC_SUB_PRIORITY);
	HAL_NVIC_EnableIRQ(HW_SYNC0_IRQ);

	/* Enable SYNC1 GPIO */
	HW_GPIO_ClkSource(HW_SYNC1_PORT, ENABLE);	
	GPIO_InitStructure.Pin = HW_SYNC1_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStructure.Pull = GPIO_PULLUP;	
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(HW_SYNC1_PORT, &GPIO_InitStructure);

	/* Enable SYNC1 interrupt source at NVIC */
	HAL_NVIC_SetPriorityGrouping(HW_NVIC_PRIORITY_GROUP);
	HAL_NVIC_SetPriority(HW_SYNC1_IRQ, HW_SYNC1_NVIC_PREEMPTION_PRIORITY, HW_SYNC1_NVIC_SUB_PRIORITY);
	HAL_NVIC_EnableIRQ(HW_SYNC1_IRQ);

	/* Enable SYNC0/SYNC1 interrupt */
	ENABLE_SYNC0_INT;
	ENABLE_SYNC1_INT;
#endif
	
#if ECAT_TIMER_INT
	/* Enable time task peripheral */
	TimeTask_Handle.Instance = HW_TIMETASK_INSTANCE;
	HW_TIM_ClkSource(TimeTask_Handle.Instance, ENABLE);

	TimeTask_Handle.Init.Prescaler = HW_TIMETASK_PRESCALER;
	TimeTask_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimeTask_Handle.Init.Period = HW_TIMETASK_PRELOAD;
	TimeTask_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimeTask_Handle.Init.RepetitionCounter = 0;
	TimeTask_Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	HAL_TIM_Base_Init(&TimeTask_Handle);

	/* Enable timer interrupt source at NVIC */
	HAL_NVIC_SetPriorityGrouping(HW_NVIC_PRIORITY_GROUP);
	HAL_NVIC_SetPriority(HW_TIMETASK_IRQ, HW_TIMETASK_NVIC_PREEMPTION_PRIORITY, HW_TIMETASK_NVIC_SUB_PRIORITY);
	HAL_NVIC_EnableIRQ(HW_TIMETASK_IRQ);
	
	/* Start timer with interrupt */
	HAL_TIM_Base_Start_IT(&TimeTask_Handle);
#endif

#if INTERRUPTS_SUPPORTED

	/* enable all interrupts */
	ENABLE_GLOBAL_INT;
#endif

	/* If Switch ID is not zero, write it into station alias register */
	if (bootSwitchID)
	{
		tmp16 = bootSwitchID;
		HW_EscWriteWord(tmp16, ESC_ALIAS_ADDRESS_OFFSET);
	}
	
	return 0;
}

/**
  * @brief  This function shall be implemented if hardware resources need to be release
  *         when the sample application stops.
  * @param  None
  * @retval None
  */
void HW_Release(void)
{

}

/**
  * @brief  This function gets the current content of ALEvent register
  * @param  None
  * @retval First two Bytes of ALEvent register (0x220)
  */
UINT16 HW_GetALEventRegister(void)
{
    GetInterruptRegister();
    return EscALEvent.Word;
}

#if INTERRUPTS_SUPPORTED
/**
  * @brief  The SPI PDI requires an extra ESC read access functions from interrupts service routines.
  *         The behaviour is equal to "HW_GetALEventRegister()"
  * @param  None
  * @retval First two Bytes of ALEvent register (0x220)
  */
UINT16 HW_GetALEventRegister_Isr(void)
{
	ISR_GetInterruptRegister();
	return EscALEvent.Word;
}
#endif

#if UC_SET_ECAT_LED
/**
  * @brief  This function updates the EtherCAT run and error led.
  * @param  RunLed  desired EtherCAT Run led state
  * @param  ErrLed  desired EtherCAT Error led state
  * @retval None
  */
void HW_SetLed(UINT8 RunLed,UINT8 ErrLed)
{
}
#endif //#if UC_SET_ECAT_LED
/**
  * @brief  This function operates the SPI read access to the EtherCAT ASIC.
  * @param  pData     Pointer to a byte array which holds data to write or saves read data.
  * @param  Address   EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
  * @param  Len       Access size in Bytes.
  * @retval None
  */
void HW_EscRead( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
#if AL_EVENT_ENABLED
		DISABLE_AL_EVENT_INT;
#endif		
		
		HW_SPI_Read(&HW_SpiObj[HW_ESC_PDI], (UINT8*)pData, Address, Len);
		
#if AL_EVENT_ENABLED
		ENABLE_AL_EVENT_INT;
#endif
}

#if INTERRUPTS_SUPPORTED
/**
  * @brief  The SPI PDI requires an extra ESC read access functions from interrupts service routines.
  *         The behaviour is equal to "HW_EscRead()"
  * @param  pData       Pointer to a byte array which holds data to write or saves read data.
  * @param  Address     EtherCAT ASIC address ( upper limit is 0x1FFF ) for access.
  * @param  Len         Access size in Bytes.
  * @retval None
  */
void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
		HW_SPI_Read(&HW_SpiObj[HW_ESC_PDI], (UINT8*)pData, Address, Len);
}
#endif //#if INTERRUPTS_SUPPORTED

/**
  * @brief  This function operates the SPI write access to the EtherCAT ASIC.
  * @param  pData       Pointer to a byte array which holds data to write or saves write data.
  * @param  Address     EtherCAT ASIC address ( upper limit is 0x1FFF ) for access.
  * @param  Len         Access size in Bytes.
  * @retval None
  */
void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
#if AL_EVENT_ENABLED
		DISABLE_AL_EVENT_INT;
#endif
		
		HW_SPI_Write(&HW_SpiObj[HW_ESC_PDI], (UINT8*)pData, Address, Len);

#if AL_EVENT_ENABLED
		ENABLE_AL_EVENT_INT;
#endif
}

#if INTERRUPTS_SUPPORTED
/**
  * @brief  The SPI PDI requires an extra ESC write access functions from interrupts service routines.
  *         The behaviour is equal to "HW_EscWrite()"
  * @param  pData       Pointer to a byte array which holds data to write or saves write data.
  * @param  Address     EtherCAT ASIC address ( upper limit is 0x1FFF ) for access.
  * @param  Len         Access size in Bytes.
  * @retval None
  */
void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
	HW_SPI_Write(&HW_SpiObj[HW_ESC_PDI], (UINT8*)pData, Address, Len);
}
#endif //#if INTERRUPTS_SUPPORTED

/**
  * @brief  This function operates the SPI read access by Function chip select
  * @param  pData     Pointer to a byte array which holds data to write or saves read data.
  * @param  Address   Function register address.
  * @param  Len       Access size in Bytes.
  * @retval None
  */
void HW_FunRead( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
#if AL_EVENT_ENABLED
		DISABLE_AL_EVENT_INT;
#endif		
		
		HW_SPI_Read(&HW_SpiObj[HW_FUN_PDI], (UINT8*)pData, Address, Len);
		
#if AL_EVENT_ENABLED
		ENABLE_AL_EVENT_INT;
#endif
}

/**
  * @brief  This function operates the SPI write access by Function chip select.
  * @param  pData       Pointer to a byte array which holds data to write or saves write data.
  * @param  Address     Function register address.
  * @param  Len         Access size in Bytes.
  * @retval None
  */
void HW_FunWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
#if AL_EVENT_ENABLED
		DISABLE_AL_EVENT_INT;
#endif
		
		HW_SPI_Write(&HW_SpiObj[HW_FUN_PDI], (UINT8*)pData, Address, Len);

#if AL_EVENT_ENABLED
		ENABLE_AL_EVENT_INT;
#endif
}

#if BOOTSTRAPMODE_SUPPORTED
/**
  * @brief  This function resets the hardware
  * @param  None
  * @retval None
  */
void HW_RestartTarget(void)
{
}
#endif

#if ESC_EEPROM_EMULATION
/**
  * @brief  This function is called when the master has request an EEPROM reload during EEPROM emulation
  * @param  None
  * @retval 0 if reload was successful
  */
UINT16 HW_EepromReload (void)
{
    return 0;
}
#endif

#if (AL_EVENT_ENABLED || DC_SUPPORTED)
/**
  * @brief  Interrupt service routine for SYNC0/SYNC1
  * @param  None
  * @retval None
  */
void HW_SYNC0_SYNC1_IRQHandler(void)
{
#if DC_SUPPORTED
	if (__HAL_GPIO_EXTI_GET_FLAG(HW_SYNC0_PIN))
	{
		__HAL_GPIO_EXTI_CLEAR_FLAG(HW_SYNC0_PIN);
#if AX58400_INTR_QUEUE_ENABLE		
		HW_IntrEnqueue(INTR_SYNC0);
#else
		Sync0_Isr();
#endif
#if AX58400_DEBUG_ENABLE	
		HW_Debug.Sync0IsrCnt++;
#endif			
	}
	
	if (__HAL_GPIO_EXTI_GET_FLAG(HW_SYNC1_PIN))
	{		
		__HAL_GPIO_EXTI_CLEAR_FLAG(HW_SYNC1_PIN);
#if AX58400_INTR_QUEUE_ENABLE		
		HW_IntrEnqueue(INTR_SYNC1);		
#else
		Sync1_Isr();
#endif		
#if AX58400_DEBUG_ENABLE	
		HW_Debug.Sync1IsrCnt++;
#endif			
	}
#endif

	if (__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_9))
	{
    /* Detected DAC trigger signal */
		__HAL_GPIO_EXTI_CLEAR_FLAG(GPIO_PIN_9);
	}
} /* End of HW_SYNC0_SYNC1_IRQHandler() */

/**
  * @brief  Interrupt service routine for AL
  * @param  None
  * @retval None
  */
void HW_ALEVENT_IRQHandler(void)
{
	if (__HAL_GPIO_EXTI_GET_FLAG(HW_SPI_ESC_INT_PIN))
	{				
		__HAL_GPIO_EXTI_CLEAR_FLAG(HW_SPI_ESC_INT_PIN);
#if AX58400_INTR_QUEUE_ENABLE		
		HW_IntrEnqueue(INTR_ESC);				
#else
		PDI_Isr();
#endif		
#if AX58400_DEBUG_ENABLE
		HW_Debug.EscIsrCnt ++;
#endif		
	}
	
} /* End of HW_ALEVENT_IRQHandler() */
#endif

#if ECAT_TIMER_INT
/**
  * @brief  Interrupt service routine for the Timer
  * @param  None
  * @retval None
  */
void HW_TIMETASK_IRQHandler(void)
{
	if ((__HAL_TIM_GET_IT_SOURCE(&TimeTask_Handle, TIM_IT_UPDATE) == SET) && 
		  (__HAL_TIM_GET_FLAG(&TimeTask_Handle, TIM_FLAG_UPDATE)!=0))
	{
		__HAL_TIM_CLEAR_FLAG(&TimeTask_Handle, TIM_FLAG_UPDATE);
#if AX58400_INTR_QUEUE_ENABLE
		HW_IntrEnqueue(INTR_TIMETASK);
#else
		ECAT_CheckTimer();
#endif
#if AX58400_DEBUG_ENABLE		
		HW_Debug.TmrTskIsrCnt ++;
#endif		
	}
} /* End of HW_TIMETASK_IRQHandler() */
#endif

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_IntrEnqueue
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_IntrEnqueue(INTR_TYPE IntrType)
{
	Intr.Queue[Intr.EnQueuePtr] = IntrType;
	Intr.EnQueuePtr++;	
	if (Intr.EnQueuePtr >= HW_MAX_INTR_QUEUE)
	{
		Intr.EnQueuePtr = 0;
	}
} /* End of HW_IntrEnqueue() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_IntrDequeue
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
void HW_IntrDequeue(void)
{
	while (Intr.DeQueuePtr != Intr.EnQueuePtr)
	{
		if (Intr.Queue[Intr.DeQueuePtr] == INTR_TIMETASK)
		{
			ECAT_CheckTimer();
		}
		else if (Intr.Queue[Intr.DeQueuePtr] == INTR_SYNC0)
		{
			Sync0_Isr();
		}
		else if (Intr.Queue[Intr.DeQueuePtr] == INTR_SYNC1)
		{
			Sync1_Isr();
		}
		else if (Intr.Queue[Intr.DeQueuePtr] == INTR_ESC)
		{
			PDI_Isr();
		}
		
		Intr.DeQueuePtr++;
		if (Intr.DeQueuePtr >= HW_MAX_INTR_QUEUE)
		{
			Intr.DeQueuePtr = 0;
		}
	}
} /* End of HW_IntrDequeue() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_CheckTimeout
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
UINT8 HW_CheckTimeout(UINT16 StartTime, UINT16 Timeout)
{
	UINT16 tmp16 = HW_GetTimer();
	
	if (tmp16 < StartTime)
	{
		tmp16 = (HW_TIMETICK_MAX_VALUE - StartTime) + tmp16;
	}
	else
	{
		tmp16 = tmp16 - StartTime;		
	}

	return ((tmp16 >= Timeout) ? 1:0);
}/* End of HW_CheckTimeout() */

/*
 * ----------------------------------------------------------------------------
 * Function Name: HW_CheckVendorProductID
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
INT32 HW_CheckVendorProductID(void)
{
	oIC_VENDOR_ID    vendor_id;	
	oIC_PRODUCT_ID   product_id;
	
	AX_INTF_EscRead(IC_VENDOR_ID, vendor_id.d32, sizeof(oIC_VENDOR_ID));
	if (vendor_id.b.vendor_id != AX58400_VENDOR_ID)
	{
		return -1;
	}

	AX_INTF_EscRead(IC_PRODUCT_ID, product_id.d32, sizeof(oIC_PRODUCT_ID));
	if (product_id.b.chip_revision != AX58400_CHIP_REVISION)
	{
		return -2;
	}

	if (product_id.b.product_id != AX58400_PRODUCT_ID)
	{
		return -3;
	}
	
	return 0;
} /* End of HW_CheckVendorProductID() */

#if (AX58400_DEBUG_ENABLE)
HW_DEBUG *HW_GetDebugCounter(void)
{
	return (&HW_Debug);
}
#endif

/* End of samplehw.c */

