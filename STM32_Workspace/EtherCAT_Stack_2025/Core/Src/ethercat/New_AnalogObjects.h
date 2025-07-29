/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup New_Analog New_Analog
* @{
*/

/**
\file New_AnalogObjects
\author ET9300Utilities.ApplicationHandler (Version 1.6.4.0) | EthercatSSC@beckhoff.com

\brief New_Analog specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
#define PROTO
#else
#define PROTO extern
#endif

UINT8 ReadObject0x8000(UINT16 index, UINT8 subindex, UINT32 dataSize,
                       UINT16 MBXMEM *pData, UINT8 bCompleteAccess);
UINT8 WriteObject0x8000(UINT16 index, UINT8 subindex, UINT32 dataSize,
                        UINT16 MBXMEM *pData, UINT8 bCompleteAccess);

/******************************************************************************
*                    Object 0x1600 : Program State process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | Program State process data mapping
* @{
* \brief Object 0x1600 (Program State process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7000.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x7000.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "Program State process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7000.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 ProgramStateProcessDataMapping0x1600
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x70000120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : Channel 0 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | Channel 0 Value process data mapping
* @{
* \brief Object 0x1A00 (Channel 0 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6000.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6000.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "Channel 0 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 Channel0ValueProcessDataMapping0x1A00
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60000120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A01 : Channel 1 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A01 0x1A01 | Channel 1 Value process data mapping
* @{
* \brief Object 0x1A01 (Channel 1 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6008.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A01[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6008.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A01[] = "Channel 1 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6008.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A01;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A01 Channel1ValueProcessDataMapping0x1A01
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60080120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A02 : Channel 2 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A02 0x1A02 | Channel 2 Value process data mapping
* @{
* \brief Object 0x1A02 (Channel 2 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6010.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A02[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6010.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A02[] = "Channel 2 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6010.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A02;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A02 Channel2ValueProcessDataMapping0x1A02
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60100120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A03 : Channel 3 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A03 0x1A03 | Channel 3 Value process data mapping
* @{
* \brief Object 0x1A03 (Channel 3 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6018.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A03[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6018.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A03[] = "Channel 3 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6018.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A03;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A03 Channel3ValueProcessDataMapping0x1A03
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60180120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A04 : Channel 4 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A04 0x1A04 | Channel 4 Value process data mapping
* @{
* \brief Object 0x1A04 (Channel 4 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6020.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A04[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6020.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A04[] = "Channel 4 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6020.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A04;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A04 Channel4ValueProcessDataMapping0x1A04
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60200120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A05 : Channel 5 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A05 0x1A05 | Channel 5 Value process data mapping
* @{
* \brief Object 0x1A05 (Channel 5 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6028.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A05[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6028.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A05[] = "Channel 5 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6028.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A05;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A05 Channel5ValueProcessDataMapping0x1A05
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60280120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A06 : Channel 6 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A06 0x1A06 | Channel 6 Value process data mapping
* @{
* \brief Object 0x1A06 (Channel 6 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6030.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A06[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6030.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A06[] = "Channel 6 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6030.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A06;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A06 Channel6ValueProcessDataMapping0x1A06
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60300120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A07 : Channel 7 Value process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A07 0x1A07 | Channel 7 Value process data mapping
* @{
* \brief Object 0x1A07 (Channel 7 Value process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6038.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A07[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6038.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A07[] = "Channel 7 Value process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6038.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A07;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A07 Channel7ValueProcessDataMapping0x1A07
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60380120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A08 : AI Inference process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A08 0x1A08 | AI Inference process data mapping
* @{
* \brief Object 0x1A08 (AI Inference process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6040.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A08[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6040.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A08[] = "AI Inference process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6040.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A08;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A08 AIInferenceProcessDataMapping0x1A08
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60400120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A09 : Time process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A09 0x1A09 | Time process data mapping
* @{
* \brief Object 0x1A09 (Time process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6048.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A09[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6048.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A09[] = "Time process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6048.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A09;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A09 TimeProcessDataMapping0x1A09
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0x60480120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
*
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,{0x1600}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
*
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[10];  /**< \brief Subindex 1 - 10 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={10,{0x1A00,0x1A01,0x1A02,0x1A03,0x1A04,0x1A05,0x1A06,0x1A07,0x1A08,0x1A09}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : Channel 0 Value
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | Channel 0 Value
* @{
* \brief Object 0x6000 (Channel 0 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 0 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 0 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "Channel 0 Value\000"
"Channel 0 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel0Value; /* Subindex1 - Channel 0 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 Channel0Value0x6000
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6008 : Channel 1 Value
******************************************************************************/
/**
* \addtogroup 0x6008 0x6008 | Channel 1 Value
* @{
* \brief Object 0x6008 (Channel 1 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 1 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6008[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 1 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6008[] = "Channel 1 Value\000"
"Channel 1 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel1Value; /* Subindex1 - Channel 1 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6008;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6008 Channel1Value0x6008
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6010 : Channel 2 Value
******************************************************************************/
/**
* \addtogroup 0x6010 0x6010 | Channel 2 Value
* @{
* \brief Object 0x6010 (Channel 2 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 2 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6010[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 2 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6010[] = "Channel 2 Value\000"
"Channel 2 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel2Value; /* Subindex1 - Channel 2 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6010;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6010 Channel2Value0x6010
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6018 : Channel 3 Value
******************************************************************************/
/**
* \addtogroup 0x6018 0x6018 | Channel 3 Value
* @{
* \brief Object 0x6018 (Channel 3 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 3 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6018[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 3 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6018[] = "Channel 3 Value\000"
"Channel 3 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel3Value; /* Subindex1 - Channel 3 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6018;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6018 Channel3Value0x6018
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6020 : Channel 4 Value
******************************************************************************/
/**
* \addtogroup 0x6020 0x6020 | Channel 4 Value
* @{
* \brief Object 0x6020 (Channel 4 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 4 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6020[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 4 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6020[] = "Channel 4 Value\000"
"Channel 4 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel4Value; /* Subindex1 - Channel 4 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6020;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6020 Channel4Value0x6020
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6028 : Channel 5 Value
******************************************************************************/
/**
* \addtogroup 0x6028 0x6028 | Channel 5 Value
* @{
* \brief Object 0x6028 (Channel 5 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 5 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6028[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 5 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6028[] = "Channel 5 Value\000"
"Channel 5 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel5Value; /* Subindex1 - Channel 5 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6028;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6028 Channel5Value0x6028
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6030 : Channel 6 Value
******************************************************************************/
/**
* \addtogroup 0x6030 0x6030 | Channel 6 Value
* @{
* \brief Object 0x6030 (Channel 6 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 6 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6030[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 6 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6030[] = "Channel 6 Value\000"
"Channel 6 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel6Value; /* Subindex1 - Channel 6 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6030;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6030 Channel6Value0x6030
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6038 : Channel 7 Value
******************************************************************************/
/**
* \addtogroup 0x6038 0x6038 | Channel 7 Value
* @{
* \brief Object 0x6038 (Channel 7 Value) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Channel 7 Value<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6038[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Channel 7 Value */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6038[] = "Channel 7 Value\000"
"Channel 7 Value\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Channel7Value; /* Subindex1 - Channel 7 Value */
} OBJ_STRUCT_PACKED_END
TOBJ6038;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6038 Channel7Value0x6038
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6040 : AI Inference
******************************************************************************/
/**
* \addtogroup 0x6040 0x6040 | AI Inference
* @{
* \brief Object 0x6040 (AI Inference) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - AI Inference<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6040[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - AI Inference */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6040[] = "AI Inference\000"
"AI Inference\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 AIInference; /* Subindex1 - AI Inference */
} OBJ_STRUCT_PACKED_END
TOBJ6040;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6040 AIInference0x6040
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6048 : Time
******************************************************************************/
/**
* \addtogroup 0x6048 0x6048 | Time
* @{
* \brief Object 0x6048 (Time) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Time<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6048[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - Time */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6048[] = "Time\000"
"Time\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 Time; /* Subindex1 - Time */
} OBJ_STRUCT_PACKED_END
TOBJ6048;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6048 Time0x6048
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : Program State
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | Program State
* @{
* \brief Object 0x7000 (Program State) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Program State<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex1 - Program State */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "Program State\000"
"Program State\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
REAL32 ProgramState; /* Subindex1 - Program State */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 ProgramState0x7000
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={1,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8000 : Parameters
******************************************************************************/
/**
* \addtogroup 0x8000 0x8000 | Parameters
* @{
* \brief Object 0x8000 (Parameters) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Upper Limit<br>
* SubIndex 2 - Lower Limit<br>
* SubIndex 3 - Underrange<br>
* SubIndex 4 - Overrange<br>
* SubIndex 5 - Gain<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex1 - Upper Limit */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex2 - Lower Limit */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex3 - Underrange */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex4 - Overrange */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }}; /* Subindex5 - Gain */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x8000[] = "Parameters\000"
"Upper Limit\000"
"Lower Limit\000"
"Underrange\000"
"Overrange\000"
"Gain\000\377";
#endif //#ifdef _OBJD_

#ifndef _NEW__ANALOG_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 UpperLimit; /* Subindex1 - Upper Limit */
UINT16 LowerLimit; /* Subindex2 - Lower Limit */
UINT16 Underrange; /* Subindex3 - Underrange */
UINT16 Overrange; /* Subindex4 - Overrange */
UINT16 Gain; /* Subindex5 - Gain */
} OBJ_STRUCT_PACKED_END
TOBJ8000;
#endif //#ifndef _NEW__ANALOG_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ8000 Parameters0x8000
#if defined(_NEW__ANALOG_) && (_NEW__ANALOG_ == 1)
={5,0,0,0,0,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &ProgramStateProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &Channel0ValueProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1A01 */
{NULL , NULL ,  0x1A01 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A01 , aName0x1A01 , &Channel1ValueProcessDataMapping0x1A01 , NULL , NULL , 0x0000 },
/* Object 0x1A02 */
{NULL , NULL ,  0x1A02 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A02 , aName0x1A02 , &Channel2ValueProcessDataMapping0x1A02 , NULL , NULL , 0x0000 },
/* Object 0x1A03 */
{NULL , NULL ,  0x1A03 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A03 , aName0x1A03 , &Channel3ValueProcessDataMapping0x1A03 , NULL , NULL , 0x0000 },
/* Object 0x1A04 */
{NULL , NULL ,  0x1A04 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A04 , aName0x1A04 , &Channel4ValueProcessDataMapping0x1A04 , NULL , NULL , 0x0000 },
/* Object 0x1A05 */
{NULL , NULL ,  0x1A05 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A05 , aName0x1A05 , &Channel5ValueProcessDataMapping0x1A05 , NULL , NULL , 0x0000 },
/* Object 0x1A06 */
{NULL , NULL ,  0x1A06 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A06 , aName0x1A06 , &Channel6ValueProcessDataMapping0x1A06 , NULL , NULL , 0x0000 },
/* Object 0x1A07 */
{NULL , NULL ,  0x1A07 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A07 , aName0x1A07 , &Channel7ValueProcessDataMapping0x1A07 , NULL , NULL , 0x0000 },
/* Object 0x1A08 */
{NULL , NULL ,  0x1A08 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A08 , aName0x1A08 , &AIInferenceProcessDataMapping0x1A08 , NULL , NULL , 0x0000 },
/* Object 0x1A09 */
{NULL , NULL ,  0x1A09 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A09 , aName0x1A09 , &TimeProcessDataMapping0x1A09 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 10 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &Channel0Value0x6000 , NULL , NULL , 0x0000 },
/* Object 0x6008 */
{NULL , NULL ,  0x6008 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6008 , aName0x6008 , &Channel1Value0x6008 , NULL , NULL , 0x0000 },
/* Object 0x6010 */
{NULL , NULL ,  0x6010 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6010 , aName0x6010 , &Channel2Value0x6010 , NULL , NULL , 0x0000 },
/* Object 0x6018 */
{NULL , NULL ,  0x6018 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6018 , aName0x6018 , &Channel3Value0x6018 , NULL , NULL , 0x0000 },
/* Object 0x6020 */
{NULL , NULL ,  0x6020 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6020 , aName0x6020 , &Channel4Value0x6020 , NULL , NULL , 0x0000 },
/* Object 0x6028 */
{NULL , NULL ,  0x6028 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6028 , aName0x6028 , &Channel5Value0x6028 , NULL , NULL , 0x0000 },
/* Object 0x6030 */
{NULL , NULL ,  0x6030 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6030 , aName0x6030 , &Channel6Value0x6030 , NULL , NULL , 0x0000 },
/* Object 0x6038 */
{NULL , NULL ,  0x6038 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6038 , aName0x6038 , &Channel7Value0x6038 , NULL , NULL , 0x0000 },
/* Object 0x6040 */
{NULL , NULL ,  0x6040 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6040 , aName0x6040 , &AIInference0x6040 , NULL , NULL , 0x0000 },
/* Object 0x6048 */
{NULL , NULL ,  0x6048 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6048 , aName0x6048 , &Time0x6048 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &ProgramState0x7000 , NULL , NULL , 0x0000 },
/* Object 0x8000 */
{NULL , NULL ,  0x8000 , {DEFTYPE_RECORD , 5 | (OBJCODE_REC << 8)} , asEntryDesc0x8000 , aName0x8000 , &Parameters0x8000 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

#undef PROTO

/** @}*/
#define _NEW__ANALOG_OBJECTS_H_
