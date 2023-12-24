#include "array.h"

static uint8_t light_on[NUMBER_OF_SAMPLES] = {};            //light_on array
static uint8_t light_on_initial[NUMBER_OF_SAMPLES] = {};    //light_on array (init values)
static uint8_t sum_of_light_on[NUMBER_OF_SAMPLES] = {};     //array with N number of ones used for matrix multiplication
//uint8_t dummy[NUMBER_OF_SAMPLES] = {1, 0, 1, 0, 0};       //dummy array for testing
//uint8_t* pdummy = &dummy;
//static uint16_t lux_array[NUMBER_OF_SAMPLES] = {};
//uint8_t Sum_Light_On = 0;                                 //used to compare with 5 or 0
//uint8_t lux_instant = 0;                                  //register for lux
uint8_t index_number = 0;                                   //index 
uint8_t light_status = LIGHT_STATUS_INITIAL;                //default light status


void light_on_Init()
{
    for (uint8_t i = 0; i<NUMBER_OF_SAMPLES; i++)
        {
            light_on_initial[i] = 0;            //Light_on_initial = {0, 0, 0, 0, 0, 0....0, 0}
            light_on[i] = light_on_initial[i];  //Light_on = Light_on_initial
            sum_of_light_on[i] = 1;             //Array with all 1's {1, 1, 1, 1, 1, 1....1, 1}
        }
    //printf("%d"*pdummy);
}


/*
void print_light_on()
{
    for (int i = 0; i<NUMBER_OF_SAMPLES; i++)
        {
            printf("%d\n",light_on[i]);
            
        }

    printf("Light on initial\n");

    for (int i = 0; i<NUMBER_OF_SAMPLES; i++)
        {
            
            printf("%d\n",light_on_initial[i]);
        }

    printf("Sum of Light on\n");

    for (int i = 0; i<NUMBER_OF_SAMPLES; i++)
        {
            
            printf("%d\n",sum_of_light_on[i]);
        }          
}
*/


uint8_t light_on_array(uint16_t lux_instant)
{
    if(lux_instant <= LUX_THRESHOLD)
        {
            //printf("Light_on[%d], lux: %d, light_on is 1\n", index_number, lux_instant);
            light_on[index_number] = 1;
        }
    else
    {
        //printf("Light_on[%d], lux: %d, light_on is 0\n", index_number,lux_instant);
        light_on[index_number] = 0;
    }

    index_number++; 
    return light_on[index_number];
}


uint8_t light_decide(uint16_t lux_instant)
{
	uint8_t index = 0;
    if(lux_instant <= LUX_THRESHOLD)
        {
            index = 1;
        }
    else
    {
			index = 0;
    }

    index_number++; 
    return index;
}


uint8_t light_status_indicator(uint8_t light_mode, uint16_t* lux_array)
{   
    uint8_t activate_light = 0;
    uint8_t Sum_Light_On = 0;
    switch(light_mode)
    {
        case LIGHT_MODE_AUTO:
            //printf("-------------------------------------------------------Now in auto mode\n");
            /* Part 1: Determine array for light on */
            for (int x=0; x<NUMBER_OF_SAMPLES; x++)
            {
                //light_on_array(lux_array[x]);
                Sum_Light_On = Sum_Light_On + lux_array[x];  
            }
            //printf("Sum_light_on: %d\n",Sum_Light_On);

            /* Part 2: Determine the light activate flag on/off */
            //printf("Before......................\n");
            //printf("light_status: %d, activate_light: %d, index_number: %d\n", light_status, activate_light, index_number);
            if (Sum_Light_On == 0){activate_light = ACTIVATE_LIGHT_OFF;}
            else if (Sum_Light_On == NUMBER_OF_SAMPLES){activate_light = ACTIVATE_LIGHT_ON;}
            else{activate_light = light_status;}
            //printf("After......................\n");
            //printf("light_status: %d, activate_light: %d, index_number: %d\n", light_status, activate_light, index_number);

            /* Part 3: */
            if (light_status != activate_light){light_status = activate_light;}
            if (index_number >= NUMBER_OF_SAMPLES){index_number = INDEX_INITIAL;}
            //printf("Carry over....................\n");
            //printf("light_status: %d, activate_light: %d, index_number: %d\n", light_status, activate_light, index_number);
            return activate_light; 

        break;

        case LIGHT_MODE_ON:
            //printf("-------------------------------------------------------Now in on mode\n");
            //printf("Before............light status = %d\n",light_status);
            if(light_status == LIGHT_STATUS_OFF) {light_status = LIGHT_STATUS_ON;}
            for (int i = 0; i<NUMBER_OF_SAMPLES; i++)
                {
                    light_on_initial[i] = 0;            //Light_on_initial = {1, 1, 1, 1, 1, 1....1, 1}
                    light_on[i] = light_on_initial[i];  
                }
            //printf("After............light status = %d\n",light_status);
            return activate_light; 

        break;

        case LIGHT_MODE_OFF:
            //printf("-------------------------------------------------------Now in off mode\n");
            //printf("Before............light status = %d\n",light_status);
            if(light_status == LIGHT_STATUS_ON) {light_status = LIGHT_STATUS_OFF;}
            for (int i = 0; i<NUMBER_OF_SAMPLES; i++)
                {
                    light_on_initial[i] = 1;            //Light_on_initial = {1, 1, 1, 1, 1, 1....1, 1}
                    light_on[i] = light_on_initial[i];  
                }
            //printf("After............light status = %d\n",light_status);
            return activate_light; 
        break;

        default:
						return 0;
            //printf("Error detected!");
    }

    
}





