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

#include "ax58400_flash.h"
#include "ax_intf.h"

#define ADDR_FLASH_SECTOR_0_BANK1     ((uint32_t)0x08000000) /* Base @ of Sector 0, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_1_BANK1     ((uint32_t)0x08020000) /* Base @ of Sector 1, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_2_BANK1     ((uint32_t)0x08040000) /* Base @ of Sector 2, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_3_BANK1     ((uint32_t)0x08060000) /* Base @ of Sector 3, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_4_BANK1     ((uint32_t)0x08080000) /* Base @ of Sector 4, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_5_BANK1     ((uint32_t)0x080A0000) /* Base @ of Sector 5, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_6_BANK1     ((uint32_t)0x080C0000) /* Base @ of Sector 6, Bank1, 128 Kbyte */
#define ADDR_FLASH_SECTOR_7_BANK1     ((uint32_t)0x080E0000) /* Base @ of Sector 7, Bank1, 128 Kbyte */

#define ADDR_FLASH_SECTOR_0_BANK2     ((uint32_t)0x08100000) /* Base @ of Sector 0, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_1_BANK2     ((uint32_t)0x08120000) /* Base @ of Sector 1, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_2_BANK2     ((uint32_t)0x08140000) /* Base @ of Sector 2, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_3_BANK2     ((uint32_t)0x08160000) /* Base @ of Sector 3, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_4_BANK2     ((uint32_t)0x08180000) /* Base @ of Sector 4, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_5_BANK2     ((uint32_t)0x081A0000) /* Base @ of Sector 5, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_6_BANK2     ((uint32_t)0x081C0000) /* Base @ of Sector 6, Bank2, 128 Kbyte */
#define ADDR_FLASH_SECTOR_7_BANK2     ((uint32_t)0x081E0000) /* Base @ of Sector 7, Bank2, 128 Kbyte */

static UINT32 GetSector(UINT32 Address);

/*
 * ----------------------------------------------------------------------------
 * Function Name: Ax58400Flash_Erase()
 * Purpose:
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
int Ax58400Flash_Erase(UINT32 sectorAddr, UINT32 bankSelected, int numSectors)
{
    UINT32 UserStartSector;
    UINT32 SectorError;
    FLASH_EraseInitTypeDef pEraseInit;
  
    /* Get the sector where start the user flash area */
    UserStartSector = GetSector(sectorAddr);
  
    pEraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;
    pEraseInit.Sector = UserStartSector;
    pEraseInit.NbSectors = numSectors;
    pEraseInit.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    /* Sector erase of second bank */
    pEraseInit.Banks = bankSelected;
    if (HAL_FLASHEx_Erase(&pEraseInit, (unsigned int *)&SectorError) != HAL_OK)
    {
      /* Error occurred while sector erase */
      return (1);
    }

    return (0);
}

/*
 * ----------------------------------------------------------------------------
 * Function Name: Ax58400Flash_Write()
 * Purpose: Write the 32-bit data to flash and total 256-bit each called
 * Params:
 * Returns:
 * Note:
 * ----------------------------------------------------------------------------
 */
UINT32 Ax58400Flash_Write(UINT32 FlashAddress, UINT32 *Data)
{
    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
       be done by word */ 
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, FlashAddress, (UINT32)Data) == HAL_OK)
    {
     /* Check the written value */
      if (*(UINT32 *)FlashAddress != Data[0])
      {
        /* Flash content doesn't match SRAM content */
        return(FLASHIF_WRITINGCTRL_ERROR);
      }
    }
    else
    {
      /* Error occurred while writing data in Flash memory */
      return (FLASHIF_WRITING_ERROR);
    }

    return (FLASHIF_OK);
}

/**
  * @brief  Gets the sector of a given address
  * @param  Address: Flash address
  * @retval The sector of a given address
  */
static UINT32 GetSector(UINT32 Address)
{
  UINT32 sector = 0;
  
  if((Address < ADDR_FLASH_SECTOR_1_BANK1) && (Address >= ADDR_FLASH_SECTOR_0_BANK1))
  {
    sector = FLASH_SECTOR_0;  
  }
  else if((Address < ADDR_FLASH_SECTOR_2_BANK1) && (Address >= ADDR_FLASH_SECTOR_1_BANK1))
  {
    sector = FLASH_SECTOR_1;  
  }
  else if((Address < ADDR_FLASH_SECTOR_3_BANK1) && (Address >= ADDR_FLASH_SECTOR_2_BANK1))
  {
    sector = FLASH_SECTOR_2;  
  }
  else if((Address < ADDR_FLASH_SECTOR_4_BANK1) && (Address >= ADDR_FLASH_SECTOR_3_BANK1))
  {
    sector = FLASH_SECTOR_3;  
  }
  else if((Address < ADDR_FLASH_SECTOR_5_BANK1) && (Address >= ADDR_FLASH_SECTOR_4_BANK1))
  {
    sector = FLASH_SECTOR_4;  
  }
  else if((Address < ADDR_FLASH_SECTOR_6_BANK1) && (Address >= ADDR_FLASH_SECTOR_5_BANK1))
  {
    sector = FLASH_SECTOR_5;  
  }
  else if((Address < ADDR_FLASH_SECTOR_7_BANK1) && (Address >= ADDR_FLASH_SECTOR_6_BANK1))
  {
    sector = FLASH_SECTOR_6;  
  }
  else if((Address < ADDR_FLASH_SECTOR_0_BANK2) && (Address >= ADDR_FLASH_SECTOR_7_BANK1))
  {
    sector = FLASH_SECTOR_7;  
  }
  else if((Address < ADDR_FLASH_SECTOR_1_BANK2) && (Address >= ADDR_FLASH_SECTOR_0_BANK2))
  {
    sector = FLASH_SECTOR_0;  
  }
  else if((Address < ADDR_FLASH_SECTOR_2_BANK2) && (Address >= ADDR_FLASH_SECTOR_1_BANK2))
  {
    sector = FLASH_SECTOR_1;  
  }
  else if((Address < ADDR_FLASH_SECTOR_3_BANK2) && (Address >= ADDR_FLASH_SECTOR_2_BANK2))
  {
    sector = FLASH_SECTOR_2;  
  }
  else if((Address < ADDR_FLASH_SECTOR_4_BANK2) && (Address >= ADDR_FLASH_SECTOR_3_BANK2))
  {
    sector = FLASH_SECTOR_3;  
  }
  else if((Address < ADDR_FLASH_SECTOR_5_BANK2) && (Address >= ADDR_FLASH_SECTOR_4_BANK2))
  {
    sector = FLASH_SECTOR_4;  
  }
  else if((Address < ADDR_FLASH_SECTOR_6_BANK2) && (Address >= ADDR_FLASH_SECTOR_5_BANK2))
  {
    sector = FLASH_SECTOR_5;  
  }
  else if((Address < ADDR_FLASH_SECTOR_7_BANK2) && (Address >= ADDR_FLASH_SECTOR_6_BANK2))
  {
    sector = FLASH_SECTOR_6;  
  }
  else /*if((Address < USER_FLASH_END_ADDRESS) && (Address >= ADDR_FLASH_SECTOR_7_BANK2))*/
  {
    sector = FLASH_SECTOR_7;  
  }

  return sector;
}

/**
  * @brief  Returns the write protection status of user flash area.
  * @param  None
  * @retval 0: No write protected sectors inside the user flash area
  *         1: Some sectors inside the user flash area are write protected
  */
uint16_t Ax58400Flash_GetWriteProtectionStatus(UINT32 flashAddress)
{
  uint32_t ProtectedSECTOR = 0x0;
  FLASH_OBProgramInitTypeDef OptionsBytesStruct;

  if (flashAddress < ADDR_FLASH_SECTOR_0_BANK2)
  {
    /* Select Bank1 */
    OptionsBytesStruct.Banks = FLASH_BANK_1;
    
    /* Check if there are write protected sectors inside the user flash area ****/
    HAL_FLASHEx_OBGetConfig(&OptionsBytesStruct);
  
    /* Get pages already write protected ****************************************/
    ProtectedSECTOR = OptionsBytesStruct.WRPSector & FLASH_SECTOR_TO_BE_PROTECTED;
  }
  else
  { 
    /* Select Bank2*/
    OptionsBytesStruct.Banks = FLASH_BANK_2;
  
    /* Check if there are write protected sectors inside the user flash area ****/
    HAL_FLASHEx_OBGetConfig(&OptionsBytesStruct);

    /* Get pages already write protected ****************************************/
    ProtectedSECTOR |= OptionsBytesStruct.WRPSector & FLASH_SECTOR_TO_BE_PROTECTED;
  }
  /* Check if desired pages are already write protected ***********************/
  if(ProtectedSECTOR != 0)
  {
    /* Some sectors inside the user flash area are write protected */
    return FLASHIF_PROTECTION_WRPENABLED;
  }
  else
  { 
    /* No write protected sectors inside the user flash area */
    return FLASHIF_PROTECTION_NONE;
  }
}

/**
  * @brief  Configure the write protection status of user flash area.
  * @param  modifier DISABLE or ENABLE the protection
  * @retval HAL_StatusTypeDef HAL_OK if change is applied.
  */
u16 Ax58400Flash_WriteProtectionConfig(UINT32 flashAddress, UINT32 modifier)
{
  uint32_t ProtectedSECTOR = 0xFFF;
  FLASH_OBProgramInitTypeDef config_new, config_old;
  HAL_StatusTypeDef result = HAL_OK;
  
  /* Unlock the Flash to enable the flash control register access *************/ 
  HAL_FLASH_Unlock();
  
  /* Unlock the Options Bytes *************************************************/
  HAL_FLASH_OB_Unlock();
  if (flashAddress < ADDR_FLASH_SECTOR_0_BANK2)
  {
    /* Select Bank1 */
    config_old.Banks = FLASH_BANK_1;
    config_new.Banks = FLASH_BANK_1;
    
    /* Get pages write protection status ****************************************/
    HAL_FLASHEx_OBGetConfig(&config_old);
    
    /* The parameter says whether we turn the protection on or off */
    config_new.WRPState = modifier;
    
    /* We want to modify only the Write protection */
    config_new.OptionType = OPTIONBYTE_WRP;
    
    /* No read protection, keep BOR and reset settings */
    config_new.RDPLevel = OB_RDP_LEVEL_0;
    config_new.USERConfig = config_old.USERConfig;  
    /* Get pages already write protected ****************************************/
    ProtectedSECTOR = config_old.WRPSector | FLASH_SECTOR_TO_BE_PROTECTED;
    
    config_new.WRPSector    = ProtectedSECTOR;
    result = HAL_FLASHEx_OBProgram(&config_new);
    
  }
  else
  {  
    /* Select Bank2 */
    config_old.Banks = FLASH_BANK_2;
    config_new.Banks = FLASH_BANK_2;
    
    /* Get pages write protection status ****************************************/
    HAL_FLASHEx_OBGetConfig(&config_old);
    
    /* The parameter says whether we turn the protection on or off */
    config_new.WRPState = modifier;
    
    /* We want to modify only the Write protection */
    config_new.OptionType = OPTIONBYTE_WRP;
    
    /* No read protection, keep BOR and reset settings */
    config_new.RDPLevel = OB_RDP_LEVEL_0;
    config_new.USERConfig = config_old.USERConfig;  
    /* Get pages already write protected ****************************************/
    ProtectedSECTOR = config_old.WRPSector | FLASH_SECTOR_TO_BE_PROTECTED;
    config_new.WRPSector    = ProtectedSECTOR;
    result = HAL_FLASHEx_OBProgram(&config_new);
    
  }
   /* Launch the option byte loading */
  HAL_FLASH_OB_Launch();
  
  HAL_FLASH_OB_Lock();
  
  HAL_FLASH_Lock();
  
  return result;
}

/* End of ax58400_flash.c */
