#ifndef __AX58400_FLASH_H__
#define __AX58400_FLASH_H__

#include "stdint.h"

#define FLASH_SECTOR_TO_BE_PROTECTED                                         \
    (OB_WRP_SECTOR_0 | OB_WRP_SECTOR_1 | OB_WRP_SECTOR_2 | OB_WRP_SECTOR_3 | \
     OB_WRP_SECTOR_4 | OB_WRP_SECTOR_5 | OB_WRP_SECTOR_6 | OB_WRP_SECTOR_7)
#define FIRMWARE_UPDATE_BASE_ADDR 0x08180000
/* Error code */
enum {
    FLASHIF_OK = 0,
    FLASHIF_ERASEKO,
    FLASHIF_WRITINGCTRL_ERROR,
    FLASHIF_WRITING_ERROR
};

enum {
    FLASHIF_PROTECTION_NONE = 0,
    FLASHIF_PROTECTION_PCROPENABLED = 0x1,
    FLASHIF_PROTECTION_WRPENABLED = 0x2,
    FLASHIF_PROTECTION_RDPENABLED = 0x4,
};

int Ax58400Flash_Erase(uint32_t sectorAddr, uint32_t bankSelected,
                       int numSectors);
uint32_t Ax58400Flash_Write(uint32_t FlashAddress, uint32_t *Data);
uint16_t Ax58400Flash_GetWriteProtectionStatus(uint32_t flashAddress);
uint16_t Ax58400Flash_WriteProtectionConfig(uint32_t flashAddress,
                                            uint32_t modifier);

#endif