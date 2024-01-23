#ifndef LIGHTCONTROL_H_
#define LIGHTCONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

//Constants
#define LUX_THRESHOLD                           	 900
#define NUMBER_OF_SAMPLES                          5
#define INDEX_INITIAL                              0
#define SAMPLING_TIME                              0.5

//Front/Back Light status
#define LIGHT_STATUS_OFF                           0x00
#define LIGHT_STATUS_ON                            0x01
#define LIGHT_STATUS_INITIAL                       0x00

//Light operation mode
#define LIGHT_MODE_AUTO                            0x00
#define LIGHT_MODE_OFF                             0x01
#define LIGHT_MODE_ON                              0x02
#define LIGHT_MODE_INITIAL                         0x00

//Activate light 
#define ACTIVATE_LIGHT_ON                          0x01
#define ACTIVATE_LIGHT_OFF                         0x00

void light_on_Init(void);
//void printing(void);
//void print_light_on();
uint8_t light_status_indicator(uint8_t, uint16_t*);
uint8_t light_on_array(uint16_t);
uint8_t light_decide(uint16_t );

#ifdef __cplusplus
}
#endif

#endif /* LIGHTCONTROL_H_ */