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
#ifndef __SAMPLEHW_H__
#define __SAMPLEHW_H__

/* INCLUDE FILE DECLARATIONS */
#include <stdio.h>
#include "stm32h7xx_hal.h"
#include "esc.h" 
#include "ax_intf.h" 

/* NAMING CONSTANT DECLARATIONS */
#define AX58400_CHIP_REVISION      0x01
#define AX58400_PRODUCT_ID         0x00058100
#define AX58400_VENDOR_ID          0x00000B95

#define ESC_ALIAS_ADDRESS_OFFSET			0x0012

	/* Interrupt, Sync0 and Syn1 */
#define HW_NVIC_PRIORITY_GROUP             NVIC_PRIORITYGROUP_3

#define HW_SYNC0_PORT                      GPIOD
#define HW_SYNC0_PIN                       GPIO_PIN_5
#define HW_SYNC0_IRQ                       EXTI9_5_IRQn
#define HW_SYNC0_NVIC_PREEMPTION_PRIORITY  6
#define HW_SYNC0_NVIC_SUB_PRIORITY         0

#define HW_SYNC1_PORT                      GPIOD
#define HW_SYNC1_PIN                       GPIO_PIN_6
#define HW_SYNC1_IRQ                       EXTI9_5_IRQn
#define HW_SYNC1_NVIC_PREEMPTION_PRIORITY  6
#define HW_SYNC1_NVIC_SUB_PRIORITY         0

	/* Timer for tick or delay function use */
#define HW_TIMETICK_CLOCK                  100000000 //120000000
#define HW_TIMETICK_COUNTING_RATE          2000
#define HW_TIMETICK_PRELOAD                0xFFFFU
#define HW_TIMETICK_PRESCALER              ((HW_TIMETICK_CLOCK/HW_TIMETICK_COUNTING_RATE)-1)
#define HW_TIMETICK_INSTANCE               TIM6
#define HW_TIMETICK_MAX_VALUE              (HW_TIMETICK_PRELOAD>>1)

	/* Timer for periodic task execution */
#define HW_TIMETASK_CLOCK                  200000000 //240000000
#define HW_TIMETASK_UPDATE_RATE            1000
#define HW_TIMETASK_PRESCALER              ((HW_TIMETASK_CLOCK/1000000)-1)
#define HW_TIMETASK_PRELOAD                (HW_TIMETASK_CLOCK/((HW_TIMETASK_PRESCALER+1)*HW_TIMETASK_UPDATE_RATE))
#define HW_TIMETASK_INSTANCE               TIM7
#define HW_TIMETASK_IRQHandler             TIM7_IRQHandler
#define HW_TIMETASK_IRQ                    TIM7_IRQn
#define HW_TIMETASK_NVIC_PREEMPTION_PRIORITY  6
#define HW_TIMETASK_NVIC_SUB_PRIORITY         1

	/* SPI PDI */
#define HW_SPI_MAX_DATA_FRAGMENT_SIZE      512
#define HW_SPI_MAX_ADDR_DUMMY_BYTES        4
#define HW_SPI_MAX_XFER_BUF_SIZE           (HW_SPI_MAX_ADDR_DUMMY_BYTES + HW_SPI_MAX_DATA_FRAGMENT_SIZE)
#define HW_SPI_XFER_TIMEOUT                10//ms
#define HW_MAX_DELAY                       0xFFFFFFFFU

	/* SPI PDI */
#define HW_SPI_ESC_INSTANCE                SPI3
#define HW_SPI_ESC_GPIO_AF                 GPIO_AF6_SPI3

#define HW_SPI_ESC_CS_PORT                 GPIOE
#define HW_SPI_ESC_CS_PIN                  GPIO_PIN_10

#define HW_SPI_FUN_CS_PORT                 GPIOC
#define HW_SPI_FUN_CS_PIN                  GPIO_PIN_8

#define HW_SPI_ESC_SCLK_PORT               GPIOC
#define HW_SPI_ESC_SCLK_PIN                GPIO_PIN_10

#define HW_SPI_ESC_MISO_PORT               GPIOC
#define HW_SPI_ESC_MISO_PIN                GPIO_PIN_11

#define HW_SPI_ESC_MOSI_PORT               GPIOC
#define HW_SPI_ESC_MOSI_PIN                GPIO_PIN_12

#define HW_SPI_ESC_INT_PORT                GPIOD
#define HW_SPI_ESC_INT_PIN                 GPIO_PIN_4
#define HW_SPI_ESC_INT_IRQ                 EXTI4_IRQn //EXTI9_5_IRQn
#define HW_SPI_ESC_INT_NVIC_PREEMPTION_PRIORITY  6
#define HW_SPI_ESC_INT_NVIC_SUB_PRIORITY         1
#define HW_ALEVENT_IRQHandler              EXTI4_IRQHandler
#define HW_SYNC0_SYNC1_IRQHandler          EXTI9_5_IRQHandler

	/* Indicators */
//#define HW_RUNLED_PORT                     GPIOA
//#define HW_RUNLED_PIN                      GPIO_PIN_2

//#define HW_ERRLED_PORT                     GPIOA
//#define HW_ERRLED_PIN                      GPIO_PIN_3

	/* EEPROM done check pin */
#define HW_EEPROM_RELOAD_TIMEOUT           10000//unit in 1ms
#define HW_EEPROM_PORT                     GPIOD
#define HW_EEPROM_PIN                      GPIO_PIN_3

	/* SPI command definition */
#define HW_SPI_NOP_CMD                     0x00
#define HW_SPI_READ_CMD                    0x02
#define HW_SPI_READ_WITH_WAIT_CMD          0x03
#define HW_SPI_WRITE_CMD                   0x04
#define HW_SPI_ADDR_EXT_CMD                0x06
#define HW_SPI_CMD_MASK                    0x07

/* TYPE DECLARATIONS */

/* GLOBAL VARIABLES */

/* EXPORTED SUBPROGRAM SPECIFICATIONS */

/**
  * @brief  625 ticks per ms
  */
#define ECAT_TIMER_INC_P_MS    0x271

/**
  * @brief  Disable interrupt source INT1
  */
#ifndef DISABLE_ESC_INT
#define DISABLE_ESC_INT()
#endif

/**
  * @brief  ENABLE interrupt source INT1
  */
#ifndef ENABLE_ESC_INT
#define ENABLE_ESC_INT()
#endif

/**
  * @brief  Access to the hardware timer
  */
#ifndef HW_GetTimer
#define HW_GetTimer()          ((UINT16)(HW_TIMETICK_INSTANCE->CNT>>1))
#endif

/**
  * @brief  Clear the hardware timer
  */
#ifndef HW_ClearTimer
#define HW_ClearTimer()        (HW_TIMETICK_INSTANCE->CNT = 0)
#endif

/**
  * @brief  No interrupts are supported so the default Get AL Event register (0x220) function is used
  */
#if !INTERRUPTS_SUPPORTED
#define HW_GetALEventRegister_Isr HW_GetALEventRegister
#endif

/**
  * @brief  16Bit ESC read access
  */
#define HW_EscReadWord(WordValue, Address) HW_EscRead(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2)

/**
  * @brief  32Bit ESC read access
  */
#define HW_EscReadDWord(DWordValue, Address) HW_EscRead(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4)

/**
  * @brief  8Bit ESC read access
  */
#if !ESC_16BIT_ACCESS
#define HW_EscReadByte(ByteValue, Address) HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#endif

/**
  * @brief  The mailbox data is stored in the local uC memory therefore the default read function is used.
  */
#define HW_EscReadMbxMem(pData,Address,Len) HW_EscRead(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len))

#if INTERRUPTS_SUPPORTED
/**
  * @brief  Interrupt specific 16Bit ESC read access
  */
#define HW_EscReadWordIsr(WordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2)

/**
  * @brief  Interrupt specific 32Bit ESC read access
  */
#define HW_EscReadDWordIsr(DWordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4)

/**
  * @brief  Interrupt specific 8Bit ESC read access
  */
#if !ESC_16BIT_ACCESS
#define HW_EscReadByteIsr(ByteValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#endif

#else //!INTERRUPTS_SUPPORTED

/**
  * @brief  No Interrupts are supported so the generic ESC write access function is used
  */
#define HW_EscReadIsr(pData, Address, Len ) HW_EscRead(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len))

/**
  * @brief  No Interrupts are used so the generic (16Bit) ESC read access function is used
  */
#define HW_EscReadWordIsr(WordValue, Address) HW_EscRead(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2)

/**
  * @brief  No Interrupts are used so the generic (32Bit) ESC read access function is used
  */
#define HW_EscReadDWordIsr(DWordValue, Address) HW_EscRead(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4)

/**
  * @brief  No Interrupts are used so the generic (8Bit) ESC read access function is used
  */
#if !ESC_16BIT_ACCESS
#define HW_EscReadByteIsr(ByteValue, Address) HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#endif //!ESC_16BIT_ACCESS

#endif //end of INTERRUPTS_SUPPORTED

/**
  * @brief  16Bit ESC write access
  */
#define HW_EscWriteWord(WordValue, Address) HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2)

/**
  * @brief  32Bit ESC write access
  */
#define HW_EscWriteDWord(DWordValue, Address) HW_EscWrite(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4)

/**
  * @brief  8Bit ESC write access
  */
#if !ESC_16BIT_ACCESS
#define HW_EscWriteByte(ByteValue, Address) HW_EscWrite(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#endif

/**
  * @brief  The mailbox data is stored in the local uC memory therefore the default write function is used.
  */
#define HW_EscWriteMbxMem(pData,Address,Len) HW_EscWrite(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len))

#if INTERRUPTS_SUPPORTED
/**
  * @brief  Interrupt specific 16Bit ESC write access
  */
#define HW_EscWriteWordIsr(WordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2)

/**
  * @brief  Interrupt specific 32Bit ESC write access
  */
#define HW_EscWriteDWordIsr(DWordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4)

/**
  * @brief  Interrupt specific 8Bit ESC write access
  */
#if !ESC_16BIT_ACCESS
#define HW_EscWriteByteIsr(ByteValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#endif

#else //!INTERRUPTS_SUPPORTED

/**
  * @brief  No Interrupts are supported so the generic ESC write access function is used
  */
#define HW_EscWriteIsr(pData, Address, Len ) HW_EscWrite(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len))

/**
  * @brief  No Interrupts are used so the generic (16Bit) ESC write access function is used
  */
#define HW_EscWriteWordIsr(WordValue, Address) HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2)

/**
  * @brief  No Interrupts are used so the generic (32Bit) ESC write access function is used
  */
#define HW_EscWriteDWordIsr(DWordValue, Address) HW_EscWrite(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4)

/**
  * @brief  No Interrupts are used so the generic (8Bit) ESC write access function is used
  */
#if !ESC_16BIT_ACCESS
#define HW_EscWriteByteIsr(ByteValue, Address) HW_EscWrite(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#endif

#endif //end of INTERRUPTS_SUPPORTED

#if __SAMPLEHW__
    #define PROTO
#else
    #define PROTO extern
#endif

PROTO UINT8 HW_Init(void);
PROTO void HW_Release(void);
PROTO UINT16 HW_GetALEventRegister(void);

#if INTERRUPTS_SUPPORTED
PROTO UINT16 HW_GetALEventRegister_Isr(void);
#endif //end of INTERRUPTS_SUPPORTED

#if UC_SET_ECAT_LED
PROTO void HW_SetLed(UINT8 RunLed,UINT8 ErrLed);
#endif //end of UC_SET_ECAT_LED

PROTO void HW_EscRead( MEM_ADDR * pData, UINT16 Address, UINT16 Len );
#if INTERRUPTS_SUPPORTED
PROTO void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );
#endif

PROTO void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

#if INTERRUPTS_SUPPORTED
PROTO void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );
#endif

#if BOOTSTRAPMODE_SUPPORTED
PROTO void HW_RestartTarget(void);
#endif

#if ESC_EEPROM_EMULATION
PROTO UINT16 HW_EepromReload (void);
#endif

#if AL_EVENT_ENABLED
PROTO void HW_ESC_IRQHandler(void);
PROTO void HW_FUN_IRQHandler(void);

#define HW_MAX_INTR_QUEUE 100
typedef enum {
	INTR_ESC = 0,
	INTR_SYNC0,	
	INTR_SYNC1,	
	INTR_TIMETASK,	
} INTR_TYPE;

typedef struct{
	INTR_TYPE  Queue[HW_MAX_INTR_QUEUE];
	UINT32     EnQueuePtr;
	UINT32     DeQueuePtr;	
} INTR_QUEUE;
PROTO void HW_IntrEnqueue(INTR_TYPE IntrType);
PROTO void HW_IntrDequeue(void);
#endif

#if DC_SUPPORTED
PROTO void HW_SYNC0_IRQHandler(void);
PROTO void HW_SYNC1_IRQHandler(void);
#endif

PROTO void   HW_GPIO_ClkSource(GPIO_TypeDef* GpioPort, UINT8 NewState);
PROTO void   HW_TIM_ClkSource(TIM_TypeDef* Instance, UINT8 NewState);
PROTO void   HW_SPI_ClkSource(SPI_TypeDef* Instance, UINT8 NewState);
PROTO void   HW_UART_ClkSource(USART_TypeDef* Instance, UINT8 NewState);
PROTO void   HW_SPI_PeriphForceReset(SPI_TypeDef* Instance);
PROTO void   HW_SPI_PeriphReleaseReset(SPI_TypeDef* Instance);
#undef PROTO

void HW_FunRead( MEM_ADDR *pData, UINT16 Address, UINT16 Len );
void HW_FunWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len );
UINT8 HW_CheckTimeout(UINT16 StartTime, UINT16 Timeout);

#if (AX58400_DEBUG_ENABLE)
	#define ESC_DEBUG       	printd
#else
	#define ESC_DEBUG(f, ...)	{}
#endif

typedef enum {
	HW_FUN_PDI = 0,
	HW_ESC_PDI,
	HW_PDI_NUM,
} HW_PDI_TYPE;

#if AX58400_DEBUG_ENABLE
typedef struct{
  UINT32  EscIsrCnt;
  UINT32  FunIsrCnt;
  UINT32  Sync0IsrCnt;
  UINT32  Sync1IsrCnt;
  UINT32  TIM1IsrCnt;
  UINT32  EncIsrCnt;	
  UINT32  TmrTskIsrCnt;
} HW_DEBUG;

HW_DEBUG* HW_GetDebugCounter(void);
#define HW_Get500usTimer()          ((UINT16)HW_TIMETICK_INSTANCE->CNT)
#endif

typedef struct{
  SPI_TypeDef   *pInstance;
  UINT8          AlterFunc;
  GPIO_TypeDef  *pCsPort;
  UINT16         CsPin;
  GPIO_TypeDef  *pClkPort;
  UINT16         ClkPin;
  GPIO_TypeDef  *pMisoPort;
  UINT16         MisoPin;
  GPIO_TypeDef  *pMosiPort;
  UINT16         MosiPin;
  GPIO_TypeDef  *pIntrPort;
  UINT16         IntrPin;
  IRQn_Type      IntrIrq;
  UINT32         IntrPrePrio;
  UINT32         IntrSubPrio;
  UINT8          Enable3BytesAddr;
  UINT32         Baudrate;
} HW_SPI_IO_CONFIG;

typedef struct{
	HW_SPI_IO_CONFIG  *pIoCfg;
	SPI_HandleTypeDef Handle;
  UINT8             *pLock;
  UINT32            *pPdiReentryCnt;	
	UINT8             TxBuf[HW_SPI_MAX_XFER_BUF_SIZE];
	UINT8             RxBuf[HW_SPI_MAX_XFER_BUF_SIZE];	
} HW_SPI_OBJECT;

extern HW_SPI_OBJECT      HW_SpiObj[];
#endif /* __SAMPLEHW_H__ */

/* End of samplehw.h */
