#include "ecat_def.h"
#include "ecatslv.h"
#define _BOOTMODE_ 1
#include "bootmode.h"
#undef _BOOTMODE_
#include "ax58400_flash.h"
#include "ecatfoe.h"
#include "foeappl.h"
#include "stm32h7xx_hal.h"

#define FIRMWARE_UPDATE_MAX_PAGE_NUMBER 4
#define FIRMWARE_UPDATE_MAX_FILE_SIZE 0x80000
#define SIGNATURE_STR "ASIX"
#define FIRMWARE_UPDATE_ENABLE 1
#define H2NL(x)                                                                \
    ((x >> 24 & 0x000000FF) | (x >> 8 & 0x0000FF00) | (x << 24 & 0xFF000000) | \
     (x << 8 & 0x00FF0000))
#define H2NS(x) ((x >> 8 & 0x00FF) | (x << 8 & 0xFF00))
#define TIMEOUT_FOR_REBOOT 1000  // ms

typedef struct _UPGRADE_RUNTIME_HEADER {
    unsigned char Signature[4];
    unsigned short ImageType;
    unsigned short Compress;
    unsigned long ContentOffset;
    unsigned long FileLen;
    unsigned long Reserved0;
    unsigned long Checksum32;
    unsigned long Reserved1[2];
} UPGRADE_RT_HEAD;

typedef struct _UPGRADE_FIRMWARE {
    unsigned char State;
    unsigned short ImageType;
    unsigned long FileOffset;
    unsigned long FileLength;
    unsigned int NumberPageErase;
    unsigned int PageBeErased;
} UPGRADE_FIRMWARE;

UPGRADE_FIRMWARE firmwareObj;
UPGRADE_RT_HEAD firmwareHeader;
uint16_t timerForJumpToBldr;
uint16_t foeLeftBytes;
unsigned long dwordData[8];
static uint32_t FirmwareChecksum32(uint32_t length);

/**
 * @brief Called from INIT to BOOT
 *
 * @param State : Current state
 */
void BL_Start(uint8_t State) {
    if (State == STATE_BOOT) {
        firmwareObj.State = BL_STATE_START;
        foeLeftBytes = 0;
    } else if (State == 0)  // Polling
    {
    }
}

/**
 * @brief BL_Init Function
 *
 */
void BL_Init(void) {
    firmwareObj.State = BL_STATE_IDLE;
    firmwareObj.FileOffset = 0;
    firmwareObj.FileLength = 0;
}

/**
 * @brief Called in the state transition from BOOT to Init
 *
 */
void BL_Stop(void) {}

/**
 * @brief BL_StartDownload function
 *
 * @param password0 : download password
 */
void BL_StartDownload(uint32_t password0) {
    if (firmwareObj.State == BL_STATE_START) {
        firmwareObj.State = BL_STATE_START_DOWNLOAD;
        firmwareObj.FileOffset = 0;
        firmwareObj.FileLength = 0;
        /* Unlock the Flash to enable the flash control register access
         * *************/
        HAL_FLASH_Unlock();
        /* Clear pending flags (if any) */
        __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR |
                               FLASH_FLAG_WRPERR | FLASH_FLAG_PGSERR |
                               FLASH_FLAG_WRPERR);
        HAL_FLASH_Lock();
    }
}

/**
 * @brief BL_Data function
 *
 * @param pData : Data pointer
 * @param Size : Data Length
 * @return uint16_t
 */
uint16_t BL_Data(uint16_t *pData, uint16_t Size) {
    int updateLen = 0;
    uint16_t writeSize = Size;
    unsigned char *pSrcData = (unsigned char *)pData;

    if (firmwareObj.State < BL_STATE_START_DOWNLOAD) {
        return ECAT_FOE_ERRCODE_ILLEGAL;
    } else if (firmwareObj.State == BL_STATE_START_DOWNLOAD) {
        if (firmwareObj.FileOffset == 0) {
            memcpy((unsigned char *)&firmwareHeader, pSrcData,
                   sizeof(UPGRADE_RT_HEAD));
            /* Check the signature */
            if ((firmwareHeader.Signature[0] != 'A') |
                (firmwareHeader.Signature[1] != 'S') |
                (firmwareHeader.Signature[2] != 'I') |
                (firmwareHeader.Signature[3] != 'X')) {
                return ECAT_FOE_ERRCODE_INVALID_FIRMWARE;
            }

            /* Check the file size */
            firmwareObj.FileLength = H2NL(firmwareHeader.FileLen);
            if (firmwareObj.FileLength > FIRMWARE_UPDATE_MAX_FILE_SIZE) {
                return ECAT_FOE_ERRCODE_DISKFULL;
            }

            /* Check the image type must be either 1(CM7) or 2(CM4) */
            firmwareObj.ImageType = firmwareHeader.ImageType;
            if (firmwareObj.ImageType != 1 && firmwareObj.ImageType != 2) {
                return ECAT_FOE_ERRCODE_INVALID_FIRMWARE;
            }

            firmwareObj.NumberPageErase =
                firmwareObj.FileLength / FLASH_SECTOR_SIZE;
            if (firmwareObj.FileLength % FLASH_SECTOR_SIZE) {
                firmwareObj.NumberPageErase += 1;
            }

            firmwareObj.PageBeErased = 0;
        }
        firmwareObj.State = BL_STATE_DATA;
    }

    /* Erase the flash for firmware update */
    if (firmwareObj.NumberPageErase > 0) {
        HAL_FLASH_Unlock();
        if (Ax58400Flash_Erase(
                FIRMWARE_UPDATE_BASE_ADDR +
                    (firmwareObj.PageBeErased * FLASH_SECTOR_SIZE),
                FLASH_BANK_2, 1) < 0) {
            Ax58400Flash_Erase(FIRMWARE_UPDATE_BASE_ADDR, FLASH_BANK_2, 1);
            HAL_FLASH_Lock();
            return ECAT_FOE_ERRCODE_PROGERROR;
        }
        HAL_FLASH_Lock();

        firmwareObj.NumberPageErase--;
        firmwareObj.PageBeErased++;
    }

    if ((firmwareObj.FileOffset + Size) > firmwareObj.FileLength) {
        HAL_FLASH_Unlock();
        Ax58400Flash_Erase(FIRMWARE_UPDATE_BASE_ADDR, FLASH_BANK_2, 1);
        HAL_FLASH_Lock();
        return ECAT_FOE_ERRCODE_DISKFULL;
    }

    HAL_FLASH_Unlock();
    writeSize = Size;
    if (foeLeftBytes > 0) {
        unsigned char *ptr = (unsigned char *)dwordData;

        if ((writeSize + foeLeftBytes) >= 32)
            updateLen = 32 - foeLeftBytes;
        else
            updateLen = writeSize;

        memcpy((ptr + foeLeftBytes), pSrcData, updateLen);
        if ((foeLeftBytes + updateLen) == 32) {
            /* Write data to flash, 32 bytes write */
            if (Ax58400Flash_Write(
                    FIRMWARE_UPDATE_BASE_ADDR + firmwareObj.FileOffset,
                    dwordData) != 0) {
                Ax58400Flash_Erase(FIRMWARE_UPDATE_BASE_ADDR, FLASH_BANK_2,
                                   1); /* Erase the signature page */
                HAL_FLASH_Lock();
                return ECAT_FOE_ERRCODE_PROGERROR;
            }

            firmwareObj.FileOffset += (foeLeftBytes + updateLen);
            foeLeftBytes = 0;
        } else {
            foeLeftBytes += updateLen;
        }

        pSrcData += updateLen;
        writeSize = writeSize - updateLen;
    }

    while (writeSize > 0) {
        if (writeSize >= 32) {
            memcpy((unsigned char *)dwordData, pSrcData, 32);
            updateLen = 32;
        } else {
            memset((unsigned char *)dwordData, 0xFF, 32);
            updateLen = writeSize;
            foeLeftBytes = updateLen;
            memcpy((unsigned char *)dwordData, pSrcData, updateLen);
            break;
        }

        /* Write data to flash, 32 bytes write */
        if (Ax58400Flash_Write(
                FIRMWARE_UPDATE_BASE_ADDR + firmwareObj.FileOffset,
                dwordData) != 0) {
            Ax58400Flash_Erase(FIRMWARE_UPDATE_BASE_ADDR, FLASH_BANK_2,
                               1); /* Erase the signature page */
            HAL_FLASH_Lock();
            return ECAT_FOE_ERRCODE_PROGERROR;
        }

        firmwareObj.FileOffset += updateLen;
        writeSize -= updateLen;
        pSrcData += updateLen;
    }
    HAL_FLASH_Lock();

    if ((firmwareObj.FileOffset + foeLeftBytes) >= firmwareObj.FileLength) {
        unsigned long checksum;
        if (foeLeftBytes > 0) {
            HAL_FLASH_Unlock();
            /* Write data to flash, 32 bytes write */
            if (Ax58400Flash_Write(
                    FIRMWARE_UPDATE_BASE_ADDR + firmwareObj.FileOffset,
                    dwordData) != 0) {
                Ax58400Flash_Erase(FIRMWARE_UPDATE_BASE_ADDR, FLASH_BANK_2,
                                   1); /* Erase the signature page */
                HAL_FLASH_Lock();
                return ECAT_FOE_ERRCODE_PROGERROR;
            }
            firmwareObj.FileOffset += foeLeftBytes;
            foeLeftBytes = 0;
            HAL_FLASH_Lock();
        }

        checksum = FirmwareChecksum32(firmwareObj.FileLength -
                                      sizeof(UPGRADE_RT_HEAD));

        if (checksum != ~firmwareHeader.Checksum32) {
            HAL_FLASH_Unlock();
            Ax58400Flash_Erase(FIRMWARE_UPDATE_BASE_ADDR, FLASH_BANK_2,
                               1); /* Erase the signature page */
            HAL_FLASH_Lock();
            return ECAT_FOE_ERRCODE_INVALID_CHECKSUM;
        }
        timerForJumpToBldr = HW_GetTimer();
        firmwareObj.State = BL_STATE_FW_TRANSMIT_DONE;
    }

    return 0;
}

/**
 * @brief checksum function
 *
 * @param length
 * @return uint32_t
 */
static uint32_t FirmwareChecksum32(uint32_t length) {
    uint32_t i;
    uint32_t count = (length >> 2);
    uint32_t cksum = 0, data32;
    uint32_t firmwareAddr = FIRMWARE_UPDATE_BASE_ADDR + sizeof(UPGRADE_RT_HEAD);

    HAL_FLASH_Unlock();
    for (i = 0; i < count; i++) {
        data32 = *(uint32_t *)firmwareAddr;
        cksum += data32;
        firmwareAddr += 4;
        if (cksum < data32) {
            cksum++;
        }
    }

    if (length % 4) {
        data32 = *(uint32_t *)firmwareAddr;
        count = length % 4;
        if (count == 3) {
            data32 = (data32 & 0x00FFFFFF);
        } else if (count == 2) {
            data32 = (data32 & 0x0000FFFF);
        } else {
            data32 = (data32 & 0x000000FF);
        }

        cksum += data32;
        if (cksum < data32) {
            cksum++;
        }
    }
    HAL_FLASH_Lock();

    return cksum;
}

/**
 * @brief Bootloader Reboot Function
 *
 */
void BL_Reboot(void) {
    uint16_t tmp16;

    if (firmwareObj.State == BL_STATE_FW_TRANSMIT_DONE) {
        tmp16 = HW_GetTimer();
        if (tmp16 >= timerForJumpToBldr) {
            if ((tmp16 - timerForJumpToBldr) >= TIMEOUT_FOR_REBOOT) {
                NVIC_SystemReset();
            }
        } else {
            timerForJumpToBldr = tmp16;
        }
    }
}