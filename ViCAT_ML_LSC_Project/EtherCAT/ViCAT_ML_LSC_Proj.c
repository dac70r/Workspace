/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
\addtogroup ViCAT_ML_LSC_Proj ViCAT_ML_LSC_Proj
@{
*/

/**
\file ViCAT_ML_LSC_Proj.c
\brief Implementation
 Created with SSC Tool application parser 1.6.4.0
\version 0.0.0.1
*/


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecat_def.h"

#include "applInterface.h"

#define _VI_CAT__ML__LSC__PROJ_ 1
#include "ViCAT_ML_LSC_Proj.h"
#undef _VI_CAT__ML__LSC__PROJ_
/*--------------------------------------------------------------------------------------
------
------    local types and defines
------
--------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    local variables and constants
------
-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    application specific functions
------
-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    generic functions
------
-----------------------------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    The function is called when an error state was acknowledged by the master

*////////////////////////////////////////////////////////////////////////////////////////

void    APPL_AckErrorInd(UINT16 stateTrans)
{

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    AL Status Code (see ecatslv.h ALSTATUSCODE_....)

 \brief    The function is called in the state transition from INIT to PREOP when
             all general settings were checked to start the mailbox handler. This function
             informs the application about the state transition, the application can refuse
             the state transition when returning an AL Status error code.
            The return code NOERROR_INWORK can be used, if the application cannot confirm
            the state transition immediately, in that case this function will be called cyclically
            until a value unequal NOERROR_INWORK is returned

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StartMailboxHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     0, NOERROR_INWORK

 \brief    The function is called in the state transition from PREEOP to INIT
             to stop the mailbox handler. This functions informs the application
             about the state transition, the application cannot refuse
             the state transition.

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StopMailboxHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param    pIntMask    pointer to the AL Event Mask which will be written to the AL event Mask
                       register (0x204) when this function is succeeded. The event mask can be adapted
                       in this function
 \return    AL Status Code (see ecatslv.h ALSTATUSCODE_....)

 \brief    The function is called in the state transition from PREOP to SAFEOP when
           all general settings were checked to start the input handler. This function
           informs the application about the state transition, the application can refuse
           the state transition when returning an AL Status error code.
           The return code NOERROR_INWORK can be used, if the application cannot confirm
           the state transition immediately, in that case the application need to be complete 
           the transition by calling ECAT_StateChange.
*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StartInputHandler(UINT16 *pIntMask)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     0, NOERROR_INWORK

 \brief    The function is called in the state transition from SAFEOP to PREEOP
             to stop the input handler. This functions informs the application
             about the state transition, the application cannot refuse
             the state transition.

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StopInputHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    AL Status Code (see ecatslv.h ALSTATUSCODE_....)

 \brief    The function is called in the state transition from SAFEOP to OP when
             all general settings were checked to start the output handler. This function
             informs the application about the state transition, the application can refuse
             the state transition when returning an AL Status error code.
           The return code NOERROR_INWORK can be used, if the application cannot confirm
           the state transition immediately, in that case the application need to be complete 
           the transition by calling ECAT_StateChange.
*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StartOutputHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     0, NOERROR_INWORK

 \brief    The function is called in the state transition from OP to SAFEOP
             to stop the output handler. This functions informs the application
             about the state transition, the application cannot refuse
             the state transition.

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StopOutputHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\return     0(ALSTATUSCODE_NOERROR), NOERROR_INWORK
\param      pInputSize  pointer to save the input process data length
\param      pOutputSize  pointer to save the output process data length

\brief    This function calculates the process data sizes from the actual SM-PDO-Assign
            and PDO mapping
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize)
{
    UINT16 result = ALSTATUSCODE_NOERROR;
    UINT16 InputSize = 0;
    UINT16 OutputSize = 0;

#if COE_SUPPORTED
    UINT16 PDOAssignEntryCnt = 0;
    OBJCONST TOBJECT OBJMEM * pPDO = NULL;
    UINT16 PDOSubindex0 = 0;
    UINT32 *pPDOEntry = NULL;
    UINT16 PDOEntryCnt = 0;
   
#if MAX_PD_OUTPUT_SIZE > 0
    /*Scan object 0x1C12 RXPDO assign*/
    for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sRxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)
    {
        pPDO = OBJ_GetObjectHandle(sRxPDOassign.aEntries[PDOAssignEntryCnt]);
        if(pPDO != NULL)
        {
            PDOSubindex0 = *((UINT16 *)pPDO->pVarPtr);
            for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)
            {
                pPDOEntry = (UINT32 *)(((UINT16 *)pPDO->pVarPtr) + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>4));    //goto PDO entry
                // we increment the expected output size depending on the mapped Entry
                OutputSize += (UINT16) ((*pPDOEntry) & 0xFF);
            }
        }
        else
        {
            /*assigned PDO was not found in object dictionary. return invalid mapping*/
            OutputSize = 0;
            result = ALSTATUSCODE_INVALIDOUTPUTMAPPING;
            break;
        }
    }

    OutputSize = (OutputSize + 7) >> 3;
#endif

#if MAX_PD_INPUT_SIZE > 0
    if(result == 0)
    {
        /*Scan Object 0x1C13 TXPDO assign*/
        for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sTxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)
        {
            pPDO = OBJ_GetObjectHandle(sTxPDOassign.aEntries[PDOAssignEntryCnt]);
            if(pPDO != NULL)
            {
                PDOSubindex0 = *((UINT16 *)pPDO->pVarPtr);
                for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)
                {
                    pPDOEntry = (UINT32 *)(((UINT16 *)pPDO->pVarPtr) + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>4));    //goto PDO entry
                    // we increment the expected output size depending on the mapped Entry
                    InputSize += (UINT16) ((*pPDOEntry) & 0xFF);
                }
            }
            else
            {
                /*assigned PDO was not found in object dictionary. return invalid mapping*/
                InputSize = 0;
                result = ALSTATUSCODE_INVALIDINPUTMAPPING;
                break;
            }
        }
    }
    InputSize = (InputSize + 7) >> 3;
#endif

#else
#if _WIN32
   #pragma message ("Warning: Define 'InputSize' and 'OutputSize'.")
#else
    #warning "Define 'InputSize' and 'OutputSize'."
#endif
#endif

    *pInputSize = InputSize;
    *pOutputSize = OutputSize;
    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\param      pData  pointer to input process data

\brief      This function will copies the inputs from the local memory to the ESC memory
            to the hardware
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_InputMapping(UINT16* pData)
{
	void APPL_InputMapping(UINT16 *pData) {
	    UINT8 *pTmpData = (UINT8 *)pData;
	    for (UINT8 j = 0; j < sTxPDOassign.u16SubIndex0; j++) {
	        switch (sTxPDOassign.aEntries[j]) {
	            case 0x1A00:
	                memcpy(pTmpData, &IN_GENERIC0x6000.IN_GEN_INT1,
	                       sizeof(IN_GENERIC0x6000.IN_GEN_INT1));
	                pTmpData += sizeof(IN_GENERIC0x6000.IN_GEN_INT1);
	                break;
	                /*
	            case 0x1A01:
	                memcpy(pTmpData, &Channel0Value0x6008.Channel0Value,
	                       sizeof(Channel0Value0x6008.Channel0Value));
	                pTmpData += sizeof(Channel0Value0x6008.Channel0Value);
	                break;
	            case 0x1A02:
	                memcpy(pTmpData, &Channel0Status0x6010.Channel0Status,
	                       sizeof(Channel0Status0x6010.Channel0Status));
	                pTmpData += sizeof(Channel0Status0x6010.Channel0Status);
	                break;
	            case 0x1A03:
	                memcpy(pTmpData, &Channel1Value0x6018.Channel1Value,
	                       sizeof(Channel1Value0x6018.Channel1Value));
	                pTmpData += sizeof(Channel1Value0x6018.Channel1Value);
	                break;
	            case 0x1A04:
	                memcpy(pTmpData, &Channel1Status0x6020.Channel1Status,
	                       sizeof(Channel1Status0x6020.Channel1Status));
	                pTmpData += sizeof(Channel1Status0x6020.Channel1Status);
	                break;
	            case 0x1A05:
	                memcpy(pTmpData, &Channel2Value0x6028.Channel2Value,
	                       sizeof(Channel2Value0x6028.Channel2Value));
	                pTmpData += sizeof(Channel2Value0x6028.Channel2Value);
	                break;

	            case 0x1A06:
	                memcpy(pTmpData, &Channel2Status0x6030.Channel2Status,
	                       sizeof(Channel2Status0x6030.Channel2Status));
	                pTmpData += sizeof(Channel2Status0x6030.Channel2Status);
	                break;
	            case 0x1A07:
	                memcpy(pTmpData, &Channel3Value0x6038.Channel3Value,
	                       sizeof(Channel3Value0x6038.Channel3Value));
	                pTmpData += sizeof(Channel3Value0x6038.Channel3Value);
	                break;
	            case 0x1A08:
	                memcpy(pTmpData, &Channel3Status0x6040.Channel3Status,
	                       sizeof(Channel3Status0x6040.Channel3Status));
	                pTmpData += sizeof(Channel3Status0x6040.Channel3Status);
	                break;
	            case 0x1A09:
	                memcpy(pTmpData, &Channel4Value0x6048.Channel4Value,
	                       sizeof(Channel4Value0x6048.Channel4Value));
	                pTmpData += sizeof(Channel4Value0x6048.Channel4Value);
	                break;
	            case 0x1A0A:
	                memcpy(pTmpData, &Channel4Status0x6050.Channel4Status,
	                       sizeof(Channel4Status0x6050.Channel4Status));
	                pTmpData += sizeof(Channel4Status0x6050.Channel4Status);
	                break;
	            case 0x1A0B:
	                memcpy(pTmpData, &Channel5Value0x6058.Channel5Value,
	                       sizeof(Channel5Value0x6058.Channel5Value));
	                pTmpData += sizeof(Channel5Value0x6058.Channel5Value);
	                break;
	            case 0x1A0C:
	                memcpy(pTmpData, &Channel5Status0x6060.Channel5Status,
	                       sizeof(Channel5Status0x6060.Channel5Status));
	                pTmpData += sizeof(Channel5Status0x6060.Channel5Status);
	                break;
	            case 0x1A0D:
	                memcpy(pTmpData, &Channel6Value0x6068.Channel6Value,
	                       sizeof(Channel6Value0x6068.Channel6Value));
	                pTmpData += sizeof(Channel6Value0x6068.Channel6Value);
	                break;
	            case 0x1A0E:
	                memcpy(pTmpData, &Channel6Status0x6070.Channel6Status,
	                       sizeof(Channel6Status0x6070.Channel6Status));
	                pTmpData += sizeof(Channel6Status0x6070.Channel6Status);
	                break;
	            case 0x1A0F:
	                memcpy(pTmpData, &Channel7Value0x6078.Channel7Value,
	                       sizeof(Channel7Value0x6078.Channel7Value));
	                pTmpData += sizeof(Channel7Value0x6078.Channel7Value);
	                break;
	            case 0x1A10:
	                memcpy(pTmpData, &Channel7Status0x6080.Channel7Status,
	                       sizeof(Channel7Status0x6080.Channel7Status));
	                pTmpData += sizeof(Channel7Status0x6080.Channel7Status);
	                break; */
	        }
	    }
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
/**
\param      pData  pointer to output process data

\brief    This function will copies the outputs from the ESC memory to the local memory
            to the hardware
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_OutputMapping(UINT16* pData)
{
    UINT8 *pTmpData = (UINT8 *)pData;
    for (UINT8 k = 0; k < sRxPDOassign.u16SubIndex0; k++) {
        switch (sRxPDOassign.aEntries[k]) {
            case 0x1600:
                memcpy(pTmpData, &OUT_GENERIC0x7000.OUT_GEN_INT1,
                       sizeof(OUT_GENERIC0x7000.OUT_GEN_INT1));
                pTmpData += sizeof(OUT_GENERIC0x7000.OUT_GEN_INT1);
                break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\brief    This function will called from the synchronisation ISR 
            or from the mainloop if no synchronisation is supported
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_Application(void)
{
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_1);
}

#if EXPLICIT_DEVICE_ID
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    The Explicit Device ID of the EtherCAT slave

 \brief     Read the Explicit Device ID (from an external ID switch)
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 APPL_GetDeviceID()
{
#if _WIN32
   #pragma message ("Warning: Implement explicit Device ID latching")
#else
    #warning "Implement explicit Device ID latching"
#endif
    /* Explicit Device 5 is expected by Explicit Device ID conformance tests*/
    return 0x5;
}
#endif


/////////////////////////////////////////////////////////////////////////////////////////
/**

 \brief    This is the main function

*////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/**

 \brief    This is the main function

*////////////////////////////////////////////////////////////////////////////////////////
void main_initial(void) {
    /* initialize the Hardware and the EtherCAT Slave Controller */
    HW_Init();
    MainInit();

    // appInit(); // user defined application

    bRunApplication = TRUE;
    do {
        MainLoop();
        //HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_1);
        //process_app();
    } while (bRunApplication == TRUE);

    HW_Release();
}
/** @} */
