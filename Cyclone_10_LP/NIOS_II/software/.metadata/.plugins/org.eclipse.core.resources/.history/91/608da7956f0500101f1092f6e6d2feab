/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
 * \addtogroup ViCAT_LSC ViCAT_LSC
 * @{
 */

/**
\file ViCAT_LSC.h
\brief ViCAT_LSC function prototypes and defines

\version 1.0.0.11
 */

 
 #ifndef _VI_CAT__LSC_H_
#define _VI_CAT__LSC_H_


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "../imported_source/ecat_def.h"

#include "../imported_source/ecatappl.h"

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/

#endif //_VI_CAT__LSC_H_

//include custom application object dictionary 
#include "../imported_source/ViCAT_LSCObjects.h"


#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
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

