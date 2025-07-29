/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup ViCAT_LSC ViCAT_LSC
* @{
*/

/**
\file ViCAT_LSCObjects
\author ET9300Utilities.ApplicationHandler (Version 1.6.4.0) | EthercatSSC@beckhoff.com

\brief ViCAT_LSC specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : OUT_GENERIC process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | OUT_GENERIC process data mapping
* @{
* \brief Object 0x1600 (OUT_GENERIC process data mapping) definition
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
OBJCONST UCHAR OBJMEM aName0x1600[] = "OUT_GENERIC process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7000.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 OUT_GENERICProcessDataMapping0x1600
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={1,0x70000110}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : IN_GENERIC process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | IN_GENERIC process data mapping
* @{
* \brief Object 0x1A00 (IN_GENERIC process data mapping) definition
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
OBJCONST UCHAR OBJMEM aName0x1A00[] = "IN_GENERIC process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 IN_GENERICProcessDataMapping0x1A00
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={1,0x60000110}
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

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
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

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={1,{0x1A00}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : IN_GENERIC
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | IN_GENERIC
* @{
* \brief Object 0x6000 (IN_GENERIC) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - IN_GEN_INT1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex1 - IN_GEN_INT1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "IN_GENERIC\000"
"IN_GEN_INT1\000\377";
#endif //#ifdef _OBJD_

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 IN_GEN_INT1; /* Subindex1 - IN_GEN_INT1 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 IN_GENERIC0x6000
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={1,0x0000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : OUT_GENERIC
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | OUT_GENERIC
* @{
* \brief Object 0x7000 (OUT_GENERIC) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - OUT_GEN_INT1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }}; /* Subindex1 - OUT_GEN_INT1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "OUT_GENERIC\000"
"OUT_GEN_INT1\000\377";
#endif //#ifdef _OBJD_

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 OUT_GEN_INT1; /* Subindex1 - OUT_GEN_INT1 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 OUT_GENERIC0x7000
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={1,0x0000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8000 : ML Parameter Setting
******************************************************************************/
/**
* \addtogroup 0x8000 0x8000 | ML Parameter Setting
* @{
* \brief Object 0x8000 (ML Parameter Setting) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - ML Setting 0<br>
* SubIndex 2 - ML Setting 1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex1 - ML Setting 0 */
{ DEFTYPE_UNSIGNED64 , 0x40 , ACCESS_READWRITE }}; /* Subindex2 - ML Setting 1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x8000[] = "ML Parameter Setting\000"
"ML Setting 0\000"
"ML Setting 1\000\377";
#endif //#ifdef _OBJD_

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 MLSetting0; /* Subindex1 - ML Setting 0 */
UINT64 MLSetting1; /* Subindex2 - ML Setting 1 */
} OBJ_STRUCT_PACKED_END
TOBJ8000;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ8000 MLParameterSetting0x8000
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={2,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8008 : ADC Parameter Setting
******************************************************************************/
/**
* \addtogroup 0x8008 0x8008 | ADC Parameter Setting
* @{
* \brief Object 0x8008 (ADC Parameter Setting) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - ADC Sensor Setting 0<br>
* SubIndex 2 - ADC Sensor Setting 1<br>
* SubIndex 3 - ADC Sensor Setting 2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8008[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex1 - ADC Sensor Setting 0 */
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READWRITE }, /* Subindex2 - ADC Sensor Setting 1 */
{ DEFTYPE_REAL32 , 0x20 , ACCESS_READWRITE }}; /* Subindex3 - ADC Sensor Setting 2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x8008[] = "ADC Parameter Setting\000"
"ADC Sensor Setting 0\000"
"ADC Sensor Setting 1\000"
"ADC Sensor Setting 2\000\377";
#endif //#ifdef _OBJD_

#ifndef _VI_CAT__LSC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 ADCSensorSetting0; /* Subindex1 - ADC Sensor Setting 0 */
REAL32 ADCSensorSetting1; /* Subindex2 - ADC Sensor Setting 1 */
REAL32 ADCSensorSetting2; /* Subindex3 - ADC Sensor Setting 2 */
} OBJ_STRUCT_PACKED_END
TOBJ8008;
#endif //#ifndef _VI_CAT__LSC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ8008 ADCParameterSetting0x8008
#if defined(_VI_CAT__LSC_) && (_VI_CAT__LSC_ == 1)
={3,0,0,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &OUT_GENERICProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &IN_GENERICProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &IN_GENERIC0x6000 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &OUT_GENERIC0x7000 , NULL , NULL , 0x0000 },
/* Object 0x8000 */
{NULL , NULL ,  0x8000 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x8000 , aName0x8000 , &MLParameterSetting0x8000 , NULL , NULL , 0x0000 },
/* Object 0x8008 */
{NULL , NULL ,  0x8008 , {DEFTYPE_RECORD , 3 | (OBJCODE_REC << 8)} , asEntryDesc0x8008 , aName0x8008 , &ADCParameterSetting0x8008 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

#undef PROTO

/** @}*/
#define _VI_CAT__LSC_OBJECTS_H_
