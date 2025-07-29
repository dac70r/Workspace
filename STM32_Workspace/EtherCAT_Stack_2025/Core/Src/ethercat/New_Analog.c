/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
\addtogroup New_Analog New_Analog
@{
*/

/**
\file New_Analog.c
\brief Implementation
 Created with SSC Tool application parser 1.6.4.0
\version 0.0.0.1
*/


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "applInterface.h"
#include "ecat_def.h"

#define _NEW__ANALOG_ 1
#include "New_Analog.h"
#undef _NEW__ANALOG_
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
adc_data_struct my_adc_struct;
adc_data_struct* ptr_my_adc_struct = &my_adc_struct;

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
void APPL_InputMapping(UINT16 *pData) {
    UINT8 *pTmpData = (UINT8 *)pData;
    for (UINT8 j = 0; j < sTxPDOassign.u16SubIndex0; j++) {
        switch (sTxPDOassign.aEntries[j]) {
            // case 0x1A00:
            //     memcpy(pTmpData, &Channel0Value0x6000.aEntries[0],
            //            sizeof(Channel0Value0x6000.aEntries));
            //     pTmpData += sizeof(Channel0Value0x6000.aEntries);
            //     break;
            // case 0x1A01:
            //     memcpy(pTmpData, &Channel1Value0x6008.aEntries[0],
            //            sizeof(Channel1Value0x6008.aEntries));
            //     pTmpData += sizeof(Channel1Value0x6008.aEntries);
            //     break;
            // case 0x1A02:
            //     memcpy(pTmpData, &Channel2Value0x6010.aEntries[0],
            //            sizeof(Channel2Value0x6010.aEntries));
            //     pTmpData += sizeof(Channel2Value0x6010.aEntries);
            //     break;
            // case 0x1A03:
            //     memcpy(pTmpData, &Channel3Value0x6018.aEntries[0],
            //            sizeof(Channel3Value0x6018.aEntries));
            //     pTmpData += sizeof(Channel3Value0x6018.aEntries);
            //     break;
            case 0x1A00:
                memcpy(pTmpData, &Channel0Value0x6000.Channel0Value,
                       sizeof(Channel0Value0x6000.Channel0Value));
                pTmpData += sizeof(Channel0Value0x6000.Channel0Value);
                break;
            case 0x1A01:
                memcpy(pTmpData, &Channel1Value0x6008.Channel1Value,
                       sizeof(Channel1Value0x6008.Channel1Value));
                pTmpData += sizeof(Channel1Value0x6008.Channel1Value);
                break;
            case 0x1A02:
                memcpy(pTmpData, &Channel2Value0x6010.Channel2Value,
                       sizeof(Channel2Value0x6010.Channel2Value));
                pTmpData += sizeof(Channel2Value0x6010.Channel2Value);
                break;
            case 0x1A03:
                memcpy(pTmpData, &Channel3Value0x6018.Channel3Value,
                       sizeof(Channel3Value0x6018.Channel3Value));
                pTmpData += sizeof(Channel3Value0x6018.Channel3Value);
                break;
            case 0x1A04:
				memcpy(pTmpData, &Channel4Value0x6020.Channel4Value,
					   sizeof(Channel4Value0x6020.Channel4Value));
				pTmpData += sizeof(Channel4Value0x6020.Channel4Value);
				break;
			case 0x1A05:
				memcpy(pTmpData, &Channel5Value0x6028.Channel5Value,
					   sizeof(Channel5Value0x6028.Channel5Value));
				pTmpData += sizeof(Channel5Value0x6028.Channel5Value);
				break;
			case 0x1A06:
				memcpy(pTmpData, &Channel6Value0x6030.Channel6Value,
					   sizeof(Channel6Value0x6030.Channel6Value));
				pTmpData += sizeof(Channel6Value0x6030.Channel6Value);
				break;
			case 0x1A07:
				memcpy(pTmpData, &Channel7Value0x6038.Channel7Value,
					   sizeof(Channel7Value0x6038.Channel7Value));
				pTmpData += sizeof(Channel7Value0x6038.Channel7Value);
				break;
			case 0x1A08:
				memcpy(pTmpData, &AIInference0x6040.AIInference,
					   sizeof(AIInference0x6040.AIInference));
				pTmpData += sizeof(AIInference0x6040.AIInference);
				break;
			case 0x1A09:
				memcpy(pTmpData, &Time0x6048.Time,
					   sizeof(Time0x6048.Time));
				pTmpData += sizeof(Time0x6048.Time);
				break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\param      pData  pointer to output process data

\brief    This function will copies the outputs from the ESC memory to the local
memory to the hardware
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_OutputMapping(UINT16 *pData) {
    UINT8 *pTmpData = (UINT8 *)pData;
    for (UINT8 k = 0; k < sRxPDOassign.u16SubIndex0; k++) {
        switch (sRxPDOassign.aEntries[k]) {
            case 0x1600:
                memcpy(pTmpData, &ProgramState0x7000.ProgramState,
                       sizeof(ProgramState0x7000.ProgramState));
                pTmpData += sizeof(ProgramState0x7000.ProgramState);
                break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     index               index of the requested object.
 \param     subindex            subindex of the requested object.
 \param     objSize             size of the requested object data, calculated
 with OBJ_GetObjectLength \param     pData               Pointer to the buffer
 where the data can be copied to \param     bCompleteAccess     Indicates if a
 complete read of all subindices of the object shall be done or not

 \return    ABORTIDX_XXX

 \brief     Handles SDO read requests to TxPDO Parameter
*////////////////////////////////////////////////////////////////////////////////////////
UINT8 ReadObject0x8000(UINT16 index, UINT8 subindex, UINT32 dataSize,
                       UINT16 MBXMEM *pData, UINT8 bCompleteAccess) {
    //    if (bCompleteAccess) {
    //        return ABORTIDX_UNSUPPORTED_ACCESS;
    //    }
    //
    //    switch (subindex) {
    //        case 0:          // Refers to 0x8000
    //            *pData = 5;  // Indicate the number of sub-indexes
    //            break;
    //        case 1:  // Refers to 0x8000 : Index 1
    //            Parameters0x8000.UpperLimit = getParameterValues(UPPER_LIMIT);
    //            memcpy(pData, &Parameters0x8000.UpperLimit, dataSize);
    //            break;
    //        case 2:  // Refers to 0x8000 : Index 2
    //            Parameters0x8000.LowerLimit = getParameterValues(LOWER_LIMIT);
    //            memcpy(pData, &Parameters0x8000.LowerLimit, dataSize);
    //            break;
    //        case 3:  // Refers to 0x8000 : Index 3
    //            Parameters0x8000.Underrange = getParameterValues(UNDER_RANGE);
    //            memcpy(pData, &Parameters0x8000.Underrange, dataSize);
    //            break;
    //        case 4:  // Refers to 0x8000 : Index 4
    //            Parameters0x8000.Overrange = getParameterValues(OVER_RANGE);
    //            memcpy(pData, &Parameters0x8000.Overrange, dataSize);
    //            break;
    //        case 5:  // Refers to 0x8000 : Index 5
    //            Parameters0x8000.Gain = getParameterValues(GAIN);
    //            memcpy(pData, &Parameters0x8000.Gain, dataSize);
    //            break;
    //        default:
    //            return ABORTIDX_SUBINDEX_NOT_EXISTING;
    //            break;
    //    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     index               index of the requested object.
 \param     subindex            subindex of the requested object.
 \param     objSize             size of the requested object data, calculated
 with OBJ_GetObjectLength \param     pData               Pointer to the buffer
 where the data can be copied to \param     bCompleteAccess     Indicates if a
 complete read of all subindices of the object shall be done or not

 \return    ABORTIDX_XXX

 \brief     Handles SDO read requests to TxPDO Parameter
*////////////////////////////////////////////////////////////////////////////////////////
UINT8 WriteObject0x8000(UINT16 index, UINT8 subindex, UINT32 dataSize,
                        UINT16 MBXMEM *pData, UINT8 bCompleteAccess) {
    //    if (bCompleteAccess) {
    //        return ABORTIDX_UNSUPPORTED_ACCESS;
    //    }
    //
    //    switch (subindex) {
    //        case 0:          // Refers to 0x8000
    //            *pData = 1;  // Indicate the number of sub-indexes
    //            break;
    //        case 1:  // Refers to 0x8000 : Index 1
    //            memcpy(&Parameters0x8000.UpperLimit, pData, dataSize);
    //            setParameterValues(Parameters0x8000.UpperLimit, UPPER_LIMIT);
    //            break;
    //        case 2:  // Refers to 0x8000 : Index 2
    //            memcpy(&Parameters0x8000.LowerLimit, pData, dataSize);
    //            setParameterValues(Parameters0x8000.LowerLimit, LOWER_LIMIT);
    //            break;
    //        case 3:  // Refers to 0x8000 : Index 3
    //            memcpy(&Parameters0x8000.Underrange, pData, dataSize);
    //            setParameterValues(Parameters0x8000.Underrange, UNDER_RANGE);
    //            break;
    //        case 4:  // Refers to 0x8000 : Index 4
    //            memcpy(&Parameters0x8000.Overrange, pData, dataSize);
    //            setParameterValues(Parameters0x8000.Overrange, OVER_RANGE);
    //            break;
    //        case 5:  // Refers to 0x8000 : Index 5
    //            memcpy(&Parameters0x8000.Gain, pData, dataSize);
    //            setParameterValues(Parameters0x8000.Gain, GAIN);
    //            break;
    //        default:
    //            return ABORTIDX_SUBINDEX_NOT_EXISTING;
    //            break;
    //    }
    return 0;
}

// adc_channel_data myAdc;
//uint16_t counter=0;
/////////////////////////////////////////////////////////////////////////////////////////
/**
\brief    This function will called from the synchronisation ISR
           or from the mainloop if no synchronisation is supported
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_Application(void) {

	/* Added by Dennis 2/8/2024 */
	//MX_X_CUBE_AI_Process();

	/* ADC 1: Added by Dennis 29/7/2024 */
	bool isReadSuccess = readData(&my_adc_struct); // 82.5micro seconds
	Channel0Value0x6000.Channel0Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel0);
	Channel1Value0x6008.Channel1Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel1);
	Channel2Value0x6010.Channel2Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel2);
	Channel3Value0x6018.Channel3Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel3);

	/* ADC 2: Added by Dennis 29/7/2024 */
	/* To be Modified 5/8/2024  */
	Channel4Value0x6020.Channel4Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel4);
	Channel5Value0x6028.Channel5Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel5);
	Channel6Value0x6030.Channel6Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel6);
	Channel7Value0x6038.Channel7Value = ADS131A04_convert_to_mVolt(ptr_my_adc_struct->channel7);

	/* AIInference: Added by Dennis 5/8/2024 */
	/* Added in MX_X_CUBE_AI_Process();  */

	/* Time: Added by Dennis 5/8/2024 */
	/* To be Modified 5/8/2024  */
	Time0x6048.Time = 0; // ADS131A04_convert_to_mVolt(ptr_my_adc_struct->time);

//	readData(&myAdc);
//	counter++;
//	if(counter == 100){
		// readADC();
//		if(ADS131A04_receive_data() == 0){
//           Channel0Value0x6000.Channel0Value = getVoltage(0);

//		uint8_t outMsg[100] = {'\0'};
//		sprintf(outMsg, "Channel 1 is %d \r\n", getVoltage(1));
//		printToUART((uint8_t*)outMsg, sizeof(outMsg));


//		Channel1Value0x6008.Channel1Value = getVoltage(1);
//		sprintf(outMsg, "Channel 1 is %lu \r\n", getVoltage(1));
//				printToUART((uint8_t*)outMsg, sizeof(outMsg));
//	//    printToConsole(Channel1Value0x6008.Channel1Value);

//		Channel2Value0x6010.Channel2Value = getVoltage(2);
//	//    printToConsole(Channel2Value0x6010.Channel2Value);
//		sprintf(outMsg, "Channel 2 is %lu \r\n", getVoltage(2));
//				printToUART((uint8_t*)outMsg, sizeof(outMsg));

//		Channel3Value0x6018.Channel3Value = getVoltage(3);
//	//    printToConsole(Channel3Value0x6018.Channel3Value);
//		sprintf(outMsg, "Channel 3 is %lu \r\n", getVoltage(3));
//				printToUART((uint8_t*)outMsg, sizeof(outMsg));
//		counter=0;
//       }
//	}

//    if (RunReady()) {
        //         uint32_t *arrayChanData;
        //
        //		 arrayChanData = getADCChannelData(0, 0);
        //			Channel0Value0x6000.Channel0Value =
        // arrayChanData[0]; 			free(arrayChanData);
        //
        //			arrayChanData = getADCChannelData(1, 0);
        //			Channel1Value0x6008.Channel1Value =
        // arrayChanData[0]; 			free(arrayChanData);
        //
        //			arrayChanData = getADCChannelData(2, 0);
        //			Channel2Value0x6010.Channel2Value =
        // arrayChanData[0]; 			free(arrayChanData);
        //
        //			arrayChanData = getADCChannelData(3, 0);
        //			Channel3Value0x6018.Channel3Value =
        // arrayChanData[0]; 			free(arrayChanData);

        //         arrayChanData = getADCChannelData(0, 0);
        //         memcpy(Channel0Value0x6000.aEntries[0], arrayChanData,
        //                sizeof(Channel0Value0x6000.aEntries));
        //         free(arrayChanData);
        //
        //         arrayChanData = getADCChannelData(1, 0);
        //         memcpy(Channel1Value0x6008.aEntries[0], arrayChanData,
        //                sizeof(Channel1Value0x6008.aEntries));
        //         free(arrayChanData);
        //
        //         arrayChanData = getADCChannelData(2, 0);
        //         memcpy(Channel2Value0x6010.aEntries[0], arrayChanData,
        //                sizeof(Channel2Value0x6010.aEntries));
        //         free(arrayChanData);
        //
        //         arrayChanData = getADCChannelData(3, 0);
        //         memcpy(Channel3Value0x6018.aEntries[0], arrayChanData,
        //                sizeof(Channel3Value0x6018.aEntries));
        //         free(arrayChanData);

#if DEVICE_USE == 0
        // TODO change to 4-7
//        arrayChanData = getADCChannelData(0, 0);
//        memcpy(Channel0Value0x6000.aEntries[0], arrayChanData,
//               sizeof(Channel0Value0x6000.aEntries));
//        free(arrayChanData);
//
//        arrayChanData = getADCChannelData(1, 0);
//        memcpy(Channel1Value0x6008.aEntries[0], arrayChanData,
//               sizeof(Channel1Value0x6008.aEntries));
//        free(arrayChanData);
//
//        arrayChanData = getADCChannelData(2, 0);
//        memcpy(Channel2Value0x6010.aEntries[0], arrayChanData,
//               sizeof(Channel2Value0x6010.aEntries));
//        free(arrayChanData);
//
//        arrayChanData = getADCChannelData(3, 0);
//        memcpy(Channel3Value0x6018.aEntries[0], arrayChanData,
//               sizeof(Channel3Value0x6018.aEntries));
//        free(arrayChanData);
#endif
//    } else {
//        memcpy(Channel0Value0x6000.aEntries[0], 0,
//               sizeof(Channel0Value0x6000.aEntries));
//        memcpy(Channel1Value0x6008.aEntries[0], 0,
//               sizeof(Channel1Value0x6008.aEntries));
//        memcpy(Channel2Value0x6010.aEntries[0], 0,
//               sizeof(Channel2Value0x6010.aEntries));
//        memcpy(Channel3Value0x6018.aEntries[0], 0,
//               sizeof(Channel3Value0x6018.aEntries));
#if DEVICE_USE == 0
        // TODO change to 4-7
//        memcpy(Channel0Value0x6000.aEntries[0], 0,
//               sizeof(Channel0Value0x6000.aEntries));
//        memcpy(Channel1Value0x6008.aEntries[0], 0,
//               sizeof(Channel1Value0x6008.aEntries));
//        memcpy(Channel2Value0x6010.aEntries[0], 0,
//               sizeof(Channel2Value0x6010.aEntries));
//        memcpy(Channel3Value0x6018.aEntries[0], 0,
//               sizeof(Channel3Value0x6018.aEntries));
#endif
//    }

    //    resetReadingNumber();
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    The Explicit Device ID of the EtherCAT slave

 \brief     Read the Explicit Device ID (from an external ID switch)
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 APPL_GetDeviceID() { return 5; }


#if USE_DEFAULT_MAIN
/////////////////////////////////////////////////////////////////////////////////////////
/**

 \brief    This is the main function

*////////////////////////////////////////////////////////////////////////////////////////
void main_initial(void) {
    /* initialize the Hardware and the EtherCAT Slave Controller */
    HW_Init();
    MainInit();

    /* FoE Init*/
    //AX58400_FoeInit();

    // printToConsole("Init Check"); // 29/7/2024 Check if program reached here
    //AppInit();

    bRunApplication = TRUE;
    do {
        MainLoop();

        /* Check if we need to reboot */
        BL_Reboot();
    } while (bRunApplication == TRUE);

    HW_Release();
}
#endif //#if USE_DEFAULT_MAIN
/** @} */

