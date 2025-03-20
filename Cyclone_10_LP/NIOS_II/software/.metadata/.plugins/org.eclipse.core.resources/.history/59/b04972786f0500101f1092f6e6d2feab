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
 
#include "ax_types.h"
 
#define FLASH_SECTOR_TO_BE_PROTECTED (OB_WRP_SECTOR_0 | OB_WRP_SECTOR_1 | OB_WRP_SECTOR_2 | OB_WRP_SECTOR_3 |\
                                      OB_WRP_SECTOR_4 | OB_WRP_SECTOR_5 | OB_WRP_SECTOR_6 | OB_WRP_SECTOR_7)
#define FIRMWARE_UPDATE_BASE_ADDR		0x08180000
 /* Error code */
enum 
{
  FLASHIF_OK = 0,
  FLASHIF_ERASEKO,
  FLASHIF_WRITINGCTRL_ERROR,
  FLASHIF_WRITING_ERROR
};
  
enum{
  FLASHIF_PROTECTION_NONE         = 0,
  FLASHIF_PROTECTION_PCROPENABLED = 0x1,
  FLASHIF_PROTECTION_WRPENABLED   = 0x2,
  FLASHIF_PROTECTION_RDPENABLED   = 0x4,
};

int Ax58400Flash_Erase(UINT32 sectorAddr, UINT32 bankSelected, int numSectors);
UINT32 Ax58400Flash_Write(UINT32 FlashAddress, UINT32 *Data);
u16 Ax58400Flash_GetWriteProtectionStatus(UINT32 flashAddress);
u16 Ax58400Flash_WriteProtectionConfig(UINT32 flashAddress, UINT32 modifier);

/* End of ax58400_flash.h */
