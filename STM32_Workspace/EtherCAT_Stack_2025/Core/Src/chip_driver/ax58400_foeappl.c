#include "ecat_def.h"
#include "ecatfoe.h"
#include "ecatslv.h"
#define _FOEAPPL_ 1
#include "foeappl.h"
#undef _FOEAPPL_
#define _FOEAPPL_ 0

#include "AX58400_FoeAppl.h"
#include "applInterface.h"
#include "bootmode.h"

#define MAX_FILE_NAME_SIZE 16

uint32_t nFileSize;
uint32_t nFileWriteOffset;
CHAR aFileName[MAX_FILE_NAME_SIZE];
uint16_t MBXMEM aFileData[(MAX_FILE_SIZE >> 1)];
const uint16_t HUGE aFirmwareDownloadHeader[4] = {0x5841, 0x3835, 0x3034,
                                                  0x5F30};  // "AX58400_"

/**
 * @brief The function starts a file reading
 *
 * @param pName : Pointer to the name of the file
 * @param nameSize : Length of the file name
 * @param password : Password for the file read
 * @param maxBlockSize
 * @param pData : Pointer to the response data
 * @return uint16_t
 *
 * size of the data to be sent, busy or an error code
 *          1..FOE_MAXBUSY-101 (size of data to be sent)
 *          FOE_MAXBUSY-100 (0%)    (busy)
 *          FOE_MAXBUSY (100%) (busy)
 *          ECAT_FOE_ERRCODE_NOTDEFINED (error)
 *          ECAT_FOE_ERRCODE_NOTFOUND (error)
 *          ECAT_FOE_ERRCODE_ACCESS    (error)
 *          ECAT_FOE_ERRCODE_DISKFULL (error)
 *          ECAT_FOE_ERRCODE_ILLEGAL (error)
 *          ECAT_FOE_ERRCODE_PACKENO (error)
 *          ECAT_FOE_ERRCODE_EXISTS    (error)
 *          ECAT_FOE_ERRCODE_NOUSER    (error)
 */
uint16_t AX58400_FoeRead(uint16_t MBXMEM *pName, uint16_t nameSize,
                         uint32_t password, uint16_t maxBlockSize,
                         uint16_t *pData) {
    uint16_t size = 0;
    uint16_t i = 0;
    CHAR aReadFileName[MAX_FILE_NAME_SIZE];

    /* ECATCHANGE_START(V5.11) FOE2*/
    if ((nameSize + 1) > MAX_FILE_NAME_SIZE) {
        return ECAT_FOE_ERRCODE_DISKFULL;
    }

    /* Read requested file name to endianess conversion if required */
    MBXSTRCPY(aReadFileName, pName, nameSize);
    aReadFileName[nameSize] = '\0';

    /* ECATCHANGE_END(V5.11) FOE2*/
    {
        /* for test only the written file name can be read */
        for (i = 0; i < nameSize; i++) {
            if (aReadFileName[i] != aFileName[i]) {
                /* file name not found */
                return ECAT_FOE_ERRCODE_NOTFOUND;
            }
        }

        if (nFileSize >=
            (u16SendMbxSize - SIZEOF(TFOEHEADER) - MBX_HEADER_SIZE)) {
            size = (u16SendMbxSize - SIZEOF(TFOEHEADER) - MBX_HEADER_SIZE);
        } else {
            size = (unsigned short)nFileSize;
        }
        MBXMEMCPY(pData, aFileData, size);
    }
    return size;
}

/**
 * @brief The function starts a file writing
 *
 * @param pName     : Pointer to the name of the file
 * @param nameSize  : Length of the file name
 * @param password  : Password for the file read
 * @return uint16_t
 *
 * okay, busy or an error code
 *          0 (okay)
 *          ECAT_FOE_ERRCODE_NOTDEFINED (error)
 *          ECAT_FOE_ERRCODE_NOTFOUND (error)
 *          ECAT_FOE_ERRCODE_ACCESS    (error)
 *          ECAT_FOE_ERRCODE_DISKFULL (error)
 *          ECAT_FOE_ERRCODE_ILLEGAL (error)
 *          ECAT_FOE_ERRCODE_PACKENO (error)
 *          ECAT_FOE_ERRCODE_EXISTS    (error)
 *          ECAT_FOE_ERRCODE_NOUSER    (error)
 *
 *          (no busy response shall be returned by this function.
 *          If the slave stack requires some time to handle the incoming data
 *          the function FOE_Data() should return busy)
 */
uint16_t AX58400_FoeWrite(uint16_t MBXMEM *pName, uint16_t nameSize,
                          uint32_t password) {
    if ((nameSize >= SIZEOF(aFirmwareDownloadHeader)) &&
        (pName[0] == aFirmwareDownloadHeader[0]) &&
        (pName[1] == aFirmwareDownloadHeader[1]) &&
        (pName[2] == aFirmwareDownloadHeader[2]) &&
        (pName[3] == aFirmwareDownloadHeader[3])) {
        if (bBootMode) {
            BL_StartDownload(password);
            return 0;
        } else {
            return ECAT_FOE_ERRCODE_BOOTSTRAPONLY;
        }
    } else if (bBootMode) {
        return ECAT_FOE_ERRCODE_NOTINBOOTSTRAP;
    } else if (nameSize < MAX_FILE_NAME_SIZE) {
        /* for test every file name can be written */
        MBXSTRCPY(aFileName, pName, nameSize);
        MBXSTRCPY(aFileName + nameSize, "\0", 1);  // string termination

        nFileWriteOffset = 0;
        nFileSize = 0;
        return 0;
    }

    return ECAT_FOE_ERRCODE_DISKFULL;
}

/**
 * @brief The function is called to write the next part of a file
 *
 * @param pData : Received file data
 * @param Size  : Length of received file data
 * @param bDataFollowing
 * @return uint16_t
 *
 * okay, busy or an error code
 *          0 (okay)
 *          FOE_MAXBUSY-100 (0%)    (busy)
 *          FOE_MAXBUSY (100%) (busy)
 *          ECAT_FOE_ERRCODE_NOTDEFINED (error)
 *          ECAT_FOE_ERRCODE_NOTFOUND (error)
 *          ECAT_FOE_ERRCODE_ACCESS    (error)
 *          ECAT_FOE_ERRCODE_DISKFULL (error)
 *          ECAT_FOE_ERRCODE_ILLEGAL (error)
 *          ECAT_FOE_ERRCODE_PACKENO (error)
 *          ECAT_FOE_ERRCODE_EXISTS    (error)
 *          ECAT_FOE_ERRCODE_NOUSER    (error)
 */
uint16_t AX58400_FoeWriteData(uint16_t MBXMEM *pData, uint16_t Size,
                              BOOL bDataFollowing) {
    if (bBootMode) {
        return BL_Data(pData, Size);
    } else if ((nFileWriteOffset + Size) > MAX_FILE_SIZE) {
        return ECAT_FOE_ERRCODE_DISKFULL;
    }

    if (Size) {
        MBXMEMCPY(&aFileData[(nFileWriteOffset >> 1)], pData, Size);
    }

    if (Size == (u16ReceiveMbxSize - MBX_HEADER_SIZE - FOE_HEADER_SIZE)) {
        /* FoE-Data services will follow */
        nFileWriteOffset += Size;
        return 0;
    } else {
        /* last part of the file is written */
        nFileSize = nFileWriteOffset + Size;
        nFileWriteOffset = 0;
        return FOE_ACKFINISHED;
    }
}

/**
 * @brief The function is called when the reading of a part of a file is
 acknowledged
 *
 * @param offset    : Offset of the next file data to be sent
 * @param maxBlockSize
 * @param pData     : Buffer for file data to be sent
 * @return uint16_t
 *
 * size of the data to be sent, busy or an error code
  *          0 (all data was sent before)
  *          1..MAX_FILE_SIZE (size of data to be sent)
  *          FOE_MAXBUSY-100 (0%)    (busy)
  *          FOE_MAXBUSY (100%) (busy)
  *          ECAT_FOE_ERRCODE_NOTDEFINED (error)
  *          ECAT_FOE_ERRCODE_NOTFOUND (error)
  *          ECAT_FOE_ERRCODE_ACCESS    (error)
  *          ECAT_FOE_ERRCODE_DISKFULL (error)
  *          ECAT_FOE_ERRCODE_ILLEGAL (error)
  *          ECAT_FOE_ERRCODE_PACKENO (error)
  *          ECAT_FOE_ERRCODE_EXISTS    (error)
  *          ECAT_FOE_ERRCODE_NOUSER    (error)
 */
uint16_t AX58400_FoeReadData(uint32_t offset, uint16_t maxBlockSize,
                             uint16_t *pData) {
    if (offset < nFileSize) {
        /* send next part of the file */
        uint32_t size;
        uint32_t sendSize = nFileSize - offset;

        if (sendSize >=
            (u16SendMbxSize - SIZEOF(TFOEHEADER) - MBX_HEADER_SIZE)) {
            size = (u16SendMbxSize - SIZEOF(TFOEHEADER) - MBX_HEADER_SIZE);
        } else {
            size = sendSize;
        }

        MBXMEMCPY(pData, &aFileData[(offset >> 1)], size);

        return ((uint16_t)size);
    } else if (offset == nFileSize) {
        /* file transfer is finished */
        return 0;  // size = 0
    }
    return ECAT_FOE_ERRCODE_ILLEGAL;
}

/**
 * @brief The function is called when a file transfer is aborted from the other
 * station
 *
 * @param errorCode
 */
void AX58400_FoeError(uint32_t errorCode) {
    if (nFileWriteOffset) {
        /* no file is stored */
        memset(aFileName, 0, MAX_FILE_NAME_SIZE);
        nFileWriteOffset = 0;
        nFileSize = 0;
    }
}

/**
 * @brief FoE Init Entry Point
 *
 */
    /* Assign related foe function pointers */
void AX58400_FoeInit(void) {
    pAPPL_FoeRead = AX58400_FoeRead;
    pAPPL_FoeReadData = AX58400_FoeReadData;
    pAPPL_FoeError = AX58400_FoeError;
    pAPPL_FoeWrite = AX58400_FoeWrite;
    pAPPL_FoeWriteData = AX58400_FoeWriteData;
}
