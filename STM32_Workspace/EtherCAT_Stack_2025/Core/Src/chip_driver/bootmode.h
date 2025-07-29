#include "ecat_def.h"

#ifndef _BOOTMODE_H_
#define _BOOTMODE_H_

#endif  //_BOOTMODE_H_

#if defined(_BOOTMODE_) && (_BOOTMODE_ == 1)
#define PROTO
#else
#define PROTO extern
#endif

typedef enum {
    BL_STATE_IDLE = 0,
    BL_STATE_START,
    BL_STATE_START_DOWNLOAD,
    BL_STATE_DATA,
    BL_STATE_FW_TRANSMIT_DONE,
} BL_STATE;

PROTO void BL_Start(uint8_t State);
PROTO void BL_Stop(void);
PROTO void BL_StartDownload(uint32_t password);
PROTO uint16_t BL_Data(uint16_t *pData, uint16_t Size);
PROTO void BL_Init(void);
PROTO void BL_Reboot(void);

#undef PROTO
