#include "ecat_def.h"
#include "ecatappl.h"

#define __AX58100_HW__ 1
#include "ax58100_hw.h"
#undef __AX58100_HW__
#define __AX58100_HW__ 0

#if INTERRUPTS_SUPPORTED
#define DISABLE_GLOBAL_INT \
    do {                   \
        __set_PRIMASK(1);  \
    } while (0)
#define ENABLE_GLOBAL_INT \
    do {                  \
        __set_PRIMASK(0); \
    } while (0)

#define DISABLE_AL_EVENT_INT \
    do {                     \
        __set_PRIMASK(1);    \
    } while (0)
#define ENABLE_AL_EVENT_INT \
    do {                    \
        __set_PRIMASK(0);   \
    } while (0)

#endif

typedef union {
    unsigned short Word;
    unsigned char Byte[2];
} UBYTETOWORD;

typedef union {
    uint8_t Byte[2];
    uint16_t Word;
} UALEVENT;

// Contains the content of the ALEvent register (0x220), this variable is
// updated on each Access to the Esc
UALEVENT EscALEvent;

uint16_t bootSwitchID = 0;
uint8_t spiTxBuf[HW_SPI_MAX_XFER_BUF_SIZE];
uint8_t spiRxBuf[HW_SPI_MAX_XFER_BUF_SIZE];

/**
 * @brief TransmitReceive low level function
 *
 * @param pTxData transmit data
 * @param pRxData receive data
 * @param Size
 * @param Timeout
 * @return int32_t
 */
static int32_t HW_SPI_TransmitReceive(uint8_t* pTxData, uint8_t* pRxData,
                                      uint16_t Size, uint32_t Timeout) {
#if SPI_ACTIVE_LOW == 1
    HAL_GPIO_WritePin(HW_SPI_ESC_CS_PORT, HW_SPI_ESC_CS_PIN, GPIO_PIN_RESET);
#else
    HAL_GPIO_WritePin(HW_SPI_ESC_CS_PORT, HW_SPI_ESC_CS_PIN, GPIO_PIN_SET);
#endif

    int32_t errorcode = HAL_SPI_TransmitReceive(&HW_SPI_ESC_INSTANCE_H, pTxData,
                                                pRxData, Size, Timeout);

#if SPI_ACTIVE_LOW == 1
    HAL_GPIO_WritePin(HW_SPI_ESC_CS_PORT, HW_SPI_ESC_CS_PIN, GPIO_PIN_SET);
#else
    HAL_GPIO_WritePin(HW_SPI_ESC_CS_PORT, HW_SPI_ESC_CS_PIN, GPIO_PIN_RESET);
#endif

    return errorcode;
}

/**
 * @brief Driver SPI read function
 *
 * @param pBuf
 * @param Addr
 * @param ByteLen
 */
static void HW_SPI_Read(uint8_t* pBuf, uint16_t Addr, uint16_t ByteLen) {
    uint16_t XferLen, AddrTmp, i;
    uint8_t *ptr, DataOffset = 0;

    while (ByteLen) {
        AddrTmp = Addr;

        /* Fragmented to specified data length per-section */
        if (ByteLen > HW_SPI_MAX_DATA_FRAGMENT_SIZE) {
            XferLen = HW_SPI_MAX_DATA_FRAGMENT_SIZE;
        } else {
            XferLen = ByteLen;
        }

        /* Set address, command */
        ptr = (uint8_t*)&AddrTmp;

#if ENABLE_3_BYTE_ADDR == 1
        spiTxBuf[2] = (ptr[1] & 0xe0) | (HW_SPI_READ_WITH_WAIT_CMD << 2);
        AddrTmp = AddrTmp << 3;
        spiTxBuf[0] = ptr[1];
        spiTxBuf[1] = ptr[0] | HW_SPI_ADDR_EXT_CMD;
        DataOffset = 3;
#else
        AddrTmp = AddrTmp << 3;
        spiTxBuf[0] = ptr[1];
        spiTxBuf[1] = ptr[0] | HW_SPI_READ_WITH_WAIT_CMD;
        DataOffset = 2;
#endif

        /* Set dummy byte */
        spiTxBuf[DataOffset] = 0xff;

        /* Set read terminal byte */
        memset(&spiTxBuf[DataOffset + 1], 0, XferLen);
        spiTxBuf[DataOffset + XferLen] = 0xff;
        DataOffset++;

        /* Start read */
        if (HW_SPI_TransmitReceive(spiTxBuf, spiRxBuf, DataOffset + XferLen,
                                   HW_SPI_XFER_TIMEOUT) != 0) {
            break;
        }

        /* Store received data */
        for (i = 0; i < XferLen; i++) {
            pBuf[i] = spiRxBuf[DataOffset + i];
        }

        /* Next section */
        Addr += XferLen;
        pBuf += XferLen;
        ByteLen -= XferLen;
    }
}

/**
 * @brief driver write function
 *
 * @param pData
 * @param Addr
 * @param ByteLen
 */
static void HW_SPI_Write(uint8_t* pData, uint16_t Addr, uint16_t ByteLen) {
    uint16_t XferLen, AddrTmp;
    uint8_t *ptr, DataOffset;

    while (ByteLen) {
        AddrTmp = Addr;

        /* Fragmented to specified data length per-section */
        if (ByteLen > HW_SPI_MAX_DATA_FRAGMENT_SIZE) {
            XferLen = HW_SPI_MAX_DATA_FRAGMENT_SIZE;
        } else {
            /* Avoid 3bytes access */
            XferLen = ((ByteLen == 3) ? 2 : ByteLen);
        }

        /* Set address , command */
        ptr = (uint8_t*)&AddrTmp;

#if ENABLE_3_BYTE_ADDR == 1
        spiTxBuf[2] = (ptr[1] & 0xe0) | (HW_SPI_WRITE_CMD << 2);
        AddrTmp = AddrTmp << 3;
        spiTxBuf[0] = ptr[1];
        spiTxBuf[1] = ptr[0] | HW_SPI_ADDR_EXT_CMD;
        DataOffset = 3;
#else
        AddrTmp = AddrTmp << 3;
        spiTxBuf[0] = ptr[1];
        spiTxBuf[1] = ptr[0] | HW_SPI_WRITE_CMD;
        DataOffset = 2;
#endif

        /* Set transmit data bytes */
        memcpy(&(spiTxBuf[DataOffset]), pData, XferLen);
        DataOffset++;

        /* Start write */
        if (HW_SPI_TransmitReceive(spiTxBuf, spiRxBuf,
                                   (DataOffset - 1) + XferLen,
                                   HW_SPI_XFER_TIMEOUT) != 0) {
            break;
        }

        Addr += XferLen;
        pData += XferLen;
        ByteLen -= XferLen;
    }
}

/**
 * @brief  The function operates a SPI access without addressing.
 * @note   The first two bytes of an access to the EtherCAT ASIC always deliver
 * the AL_Event register (0x220). It will be saved in the global "EscALEvent"
 * @param  None
 * @retval None
 */
static void GetInterruptRegister(void) {
#if AL_EVENT_ENABLED
    DISABLE_AL_EVENT_INT;
#endif

    HW_EscRead((MEM_ADDR*)EscALEvent.Byte, ESC_AL_EVENT_OFFSET, 2);

#if AL_EVENT_ENABLED
    ENABLE_AL_EVENT_INT;
#endif
}

/**
 * @brief  The function operates a SPI access without addressing.
 * @note   Shall be implemented if interrupts are supported else this function
 * is equal to "GetInterruptRegsiter()"
 * @note   The first two bytes of an access to the EtherCAT ASIC always deliver
 * the AL_Event register (0x220). It will be saved in the global "EscALEvent"
 * @param  None
 * @retval None
 */
#if !INTERRUPTS_SUPPORTED
#define ISR_GetInterruptRegister GetInterruptRegister
#else
static void ISR_GetInterruptRegister(void) {
    HW_EscReadIsr((MEM_ADDR*)EscALEvent.Byte, ESC_AL_EVENT_OFFSET, 2);
}
#endif  // #else #if !INTERRUPTS_SUPPORTED

/**
 * @brief  This function intialize the Process Data Interface (PDI) and the host
 * controller.
 * @param  None
 * @retval 0 if initialization was successful
 */
uint8_t HW_Init(void) {
    uint32_t intMask;
    uint16_t startTime;
    uint16_t currentTime;
    uint16_t elapsedTime;

    /* Enable time tick peripheral */
    HAL_TIM_Base_Start(&HW_TIMETICK_INSTANCE_H);

    /* Wait ESC ready by checking EEPDONE pin goes high */
    startTime = HW_GetTimer();  // Get the starting time
    do {
        currentTime = HW_GetTimer();  // Get the current timer value

        if (currentTime < startTime) {
            // Handle timer overflow
            elapsedTime = (HW_TIMETICK_MAX_VALUE - startTime) + currentTime;
        } else {
            elapsedTime = currentTime - startTime;
        }

        if (elapsedTime >= HW_EEPROM_RELOAD_TIMEOUT) {
            return 1;  // Timeout occurred
        }
    } while (HAL_GPIO_ReadPin(HW_EEPROM_PORT, HW_EEPROM_PIN) == GPIO_PIN_RESET);

    do {
        intMask = 0x93;
        HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
        intMask = 0;
        HW_EscReadDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
    } while (intMask != 0x93);
    intMask = 0x00;
    HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);

#if AL_EVENT_ENABLED
    /* Enable ESC interrupt */
    ENABLE_ESC_INT();
#endif

    HAL_TIM_Base_Start_IT(&HW_TIMETASK_INSTANCE_H);

#if INTERRUPTS_SUPPORTED
    /* enable all interrupts */
    ENABLE_GLOBAL_INT;
#endif

    /* If Switch ID is not zero, write it into station alias register */
    if (bootSwitchID) {
        HW_EscWriteWord(bootSwitchID, ESC_ALIAS_ADDRESS_OFFSET);
    }

    return 0;
}

/**
 * @brief  This function shall be implemented if hardware resources need to be
 * release when the sample application stops.
 * @param  None
 * @retval None
 */
void HW_Release(void) {}

/* Start of AL Event Functions */
/**
 * @brief  This function gets the current content of ALEvent register
 * @param  None
 * @retval First two Bytes of ALEvent register (0x220)
 */
uint16_t HW_GetALEventRegister(void) {
    GetInterruptRegister();
    return EscALEvent.Word;
}

#if INTERRUPTS_SUPPORTED
/**
 * @brief  The SPI PDI requires an extra ESC read access functions from
 * interrupts service routines. The behaviour is equal to
 * "HW_GetALEventRegister()"
 * @param  None
 * @retval First two Bytes of ALEvent register (0x220)
 */
uint16_t HW_GetALEventRegister_Isr(void) {
    ISR_GetInterruptRegister();
    return EscALEvent.Word;
}
#endif

/* Start of ESC read write Functions */
/**
 * @brief  This function operates the SPI read access to the EtherCAT ASIC.
 * @param  pData     Pointer to a byte array which holds data to write or saves
 * read data.
 * @param  Address   EtherCAT ASIC address ( upper limit is 0x1FFF )    for
 * access.
 * @param  Len       Access size in Bytes.
 * @retval None
 */
void HW_EscRead(MEM_ADDR* pData, uint16_t Address, uint16_t Len) {
#if AL_EVENT_ENABLED
    DISABLE_AL_EVENT_INT;
#endif
    HW_SPI_Read((uint8_t*)pData, Address, Len);

#if AL_EVENT_ENABLED
    ENABLE_AL_EVENT_INT;
#endif
}

#if INTERRUPTS_SUPPORTED
/**
 * @brief  The SPI PDI requires an extra ESC read access functions from
 * interrupts service routines. The behaviour is equal to "HW_EscRead()"
 * @param  pData       Pointer to a byte array which holds data to write or
 * saves read data.
 * @param  Address     EtherCAT ASIC address ( upper limit is 0x1FFF ) for
 * access.
 * @param  Len         Access size in Bytes.
 * @retval None
 */
void HW_EscReadIsr(MEM_ADDR* pData, uint16_t Address, uint16_t Len) {
    HW_SPI_Read((uint8_t*)pData, Address, Len);
}
#endif  // #if INTERRUPTS_SUPPORTED

/**
 * @brief  This function operates the SPI write access to the EtherCAT ASIC.
 * @param  pData       Pointer to a byte array which holds data to write or
 * saves write data.
 * @param  Address     EtherCAT ASIC address ( upper limit is 0x1FFF ) for
 * access.
 * @param  Len         Access size in Bytes.
 * @retval None
 */
void HW_EscWrite(MEM_ADDR* pData, uint16_t Address, uint16_t Len) {
#if AL_EVENT_ENABLED
    DISABLE_AL_EVENT_INT;
#endif
    HW_SPI_Write((uint8_t*)pData, Address, Len);

#if AL_EVENT_ENABLED
    ENABLE_AL_EVENT_INT;
#endif
}

#if INTERRUPTS_SUPPORTED
/**
 * @brief  The SPI PDI requires an extra ESC write access functions from
 * interrupts service routines. The behaviour is equal to "HW_EscWrite()"
 * @param  pData       Pointer to a byte array which holds data to write or
 * saves write data.
 * @param  Address     EtherCAT ASIC address ( upper limit is 0x1FFF ) for
 * access.
 * @param  Len         Access size in Bytes.
 * @retval None
 */
void HW_EscWriteIsr(MEM_ADDR* pData, uint16_t Address, uint16_t Len) {
    HW_SPI_Write((uint8_t*)pData, Address, Len);
}
#endif  // #if INTERRUPTS_SUPPORTED

#if BOOTSTRAPMODE_SUPPORTED
/**
 * @brief  This function resets the hardware
 * @param  None
 * @retval None
 */
void HW_RestartTarget(void) {}
#endif

#if ESC_EEPROM_EMULATION
/**
 * @brief  This function is called when the master has request an EEPROM reload
 * during EEPROM emulation
 * @param  None
 * @retval 0 if reload was successful
 */
uint16_t HW_EepromReload(void) { return 0; }
#endif

#if (AL_EVENT_ENABLED || DC_SUPPORTED)
/**
 * @brief  Interrupt service routine for AL
 * @param  None
 * @retval None
 */
void HW_ALEVENT_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_FLAG(HW_SPI_ESC_INT_PIN)) {
        __HAL_GPIO_EXTI_CLEAR_FLAG(HW_SPI_ESC_INT_PIN);
        PDI_Isr();
    }
}

/**
 * @brief  Interrupt service routine for SYNC0/SYNC1
 * @param  None
 * @retval None
 */
void HW_SYNC0_IRQHandler(void) {
#if DC_SUPPORTED
    if (__HAL_GPIO_EXTI_GET_FLAG(HW_SYNC0_PIN)) {
        __HAL_GPIO_EXTI_CLEAR_FLAG(HW_SYNC0_PIN);
        Sync0_Isr();
    }

#endif
}

/**
 * @brief  Interrupt service routine for SYNC0/SYNC1
 * @param  None
 * @retval None
 */

void HW_SYNC1_IRQHandler(void) {
#if DC_SUPPORTED
    if (__HAL_GPIO_EXTI_GET_FLAG(HW_SYNC1_PIN)) {
        __HAL_GPIO_EXTI_CLEAR_FLAG(HW_SYNC1_PIN);
        Sync1_Isr();
    }

#endif
}

#endif

    /**
     * @brief  Interrupt service routine for the Timer
     * @param  None
     * @retval None
     */
    void HW_TIMETASK_IRQHandler(void) {
        if ((__HAL_TIM_GET_IT_SOURCE(&HW_TIMETASK_INSTANCE_H, TIM_IT_UPDATE) ==
             SET) &&
            (__HAL_TIM_GET_FLAG(&HW_TIMETASK_INSTANCE_H, TIM_FLAG_UPDATE) != 0)) {
            __HAL_TIM_CLEAR_FLAG(&HW_TIMETASK_INSTANCE_H, TIM_FLAG_UPDATE);
            ECAT_CheckTimer();
            //appTimerRun();  // TODO place your run on timer task here
        }
    }

