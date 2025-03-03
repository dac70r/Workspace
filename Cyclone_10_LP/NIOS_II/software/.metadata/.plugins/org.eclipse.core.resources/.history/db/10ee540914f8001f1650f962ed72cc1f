/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
 * \addtogroup Microcontroller_Asix58100_ESI Microcontroller_Asix58100_ESI
 * @{
 */

/**
\file Microcontroller_Asix58100_ESI.h
\brief Microcontroller_Asix58100_ESI function prototypes and defines

\version 1.0.0.11
 */

 
 #ifndef _MICROCONTROLLER__ASIX58100__ESI_H_
#define _MICROCONTROLLER__ASIX58100__ESI_H_


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecat_def.h"

#include "ecatappl.h"

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/

#endif //_MICROCONTROLLER__ASIX58100__ESI_H_

//include custom application object dictionary 
#include "Microcontroller_Asix58100_ESIObjects.h"


#if defined(_MICROCONTROLLER__ASIX58100__ESI_) && (_MICROCONTROLLER__ASIX58100__ESI_ == 1)
    #define PROTO
#else
    #define PROTO extern
#endif


PROTO void APPL_Application(void);
#if EXPLICIT_DEVICE_ID
PROTO UINT16 APPL_GetDeviceID(void);
#endif

PROTO void   APPL_AckErrorInd(UINT16 stateTrans);
PROTO UINT16 APPL_StartMailboxHandler(void);
PROTO UINT16 APPL_StopMailboxHandler(void);
PROTO UINT16 APPL_StartInputHandler(UINT16 *pIntMask);
PROTO UINT16 APPL_StopInputHandler(void);
PROTO UINT16 APPL_StartOutputHandler(void);
PROTO UINT16 APPL_StopOutputHandler(void);

PROTO UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize);
PROTO void APPL_InputMapping(UINT16* pData);
PROTO void APPL_OutputMapping(UINT16* pData);

#undef PROTO
/** @}*/

