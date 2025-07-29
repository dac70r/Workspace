#ifndef _AX58400_FOE_APPL_H_
#define _AX58400_FOE_APPL_H_

#include <stdlib.h>
#include <string.h>

#include "ecat_def.h"
#include "ecatappl.h"
#include "ecatslv.h"
#include "esc.h"
#include "objdef.h"

/*ECATCHANGE_START(V5.12) FOE1*/
#include "foeappl.h"
/*ECATCHANGE_END(V5.12) FOE1*/

#endif /*#ifndef _AX58400_FOE_APPL_H_*/

#ifndef MAX_FILE_SIZE
#define MAX_FILE_SIZE 0x180
#endif

extern uint16_t AX58400_FoeRead(uint16_t MBXMEM *pName, uint16_t nameSize,
                                uint32_t password, uint16_t maxBlockSize,
                                uint16_t *pData);
extern uint16_t AX58400_FoeReadData(uint32_t offset, uint16_t maxBlockSize,
                                    uint16_t *pData);
extern void AX58400_FoeError(uint32_t errorCode);
extern uint16_t AX58400_FoeWrite(uint16_t MBXMEM *pName, uint16_t nameSize,
                                 uint32_t password);
extern uint16_t AX58400_FoeWriteData(uint16_t MBXMEM *pData, uint16_t Size,
                                     BOOL bDataFollowing);
extern void AX58400_FoeInit(void);
