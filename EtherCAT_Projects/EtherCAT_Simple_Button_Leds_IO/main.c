/*
 * main.c
 *
 *  Created on: 2024 Apr 06 09:54:18
 *  Author: denni
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "SSC/Src/XMC_ESCObjects.h"

#define P_LED1 P1_14
#define P_LED2 P0_14
#define P_LED3 P3_14
#define P_LED4 P0_15
#define P_LED5 P1_2
#define P_LED6 P3_13
#define P_LED7 P5_3
#define P_LED8 P3_11

#define MAP2LEVEL(x) ((x==0)?XMC_GPIO_OUTPUT_LEVEL_HIGH:XMC_GPIO_OUTPUT_LEVEL_LOW)

void Init_ECAT_Adapt_LED ()
{
  /* Set mode of all LED ports to push-pull and output level to low*/
  XMC_GPIO_SetMode(P_LED1, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED1);
  XMC_GPIO_SetMode(P_LED2, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED2);
  XMC_GPIO_SetMode(P_LED3, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED3);
  XMC_GPIO_SetMode(P_LED4, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED4);
  XMC_GPIO_SetMode(P_LED5, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED5);
  XMC_GPIO_SetMode(P_LED6, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED6);
  XMC_GPIO_SetMode(P_LED7, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED7);
  XMC_GPIO_SetMode(P_LED8, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED8);
}

void Init_Relax_Button ()
{
  /* INITIALIZE BUTTON1 ON PORT 5.13 FOR INPUT */
  /* Set mode to input tristate */
  XMC_GPIO_SetMode(P15_13, XMC_GPIO_MODE_INPUT_TRISTATE);
  /* Enable digital input. Only needed because P15.13 is an analog port */
  XMC_GPIO_EnableDigitalInput(P15_13);

  /* INITIALIZE BUTTON2 ON PORT 5.12 FOR INPUT */
  /* Set mode to input tristate */
  XMC_GPIO_SetMode(P15_12, XMC_GPIO_MODE_INPUT_TRISTATE);
  /* Enable digital input. Only needed because P15.12 is an analog port */
  XMC_GPIO_EnableDigitalInput(P15_12);
}

void process_app(TOBJ7000 *OUT_GENERIC, TOBJ6000 *IN_GENERIC)
{
  /* OUTPUT PROCESSING */
  /* Check bitfield set by master OUT_GEN_Bit1..8 and set LEDs accordingly */
  XMC_GPIO_SetOutputLevel(P_LED1, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit1));
  XMC_GPIO_SetOutputLevel(P_LED2, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit2));
  XMC_GPIO_SetOutputLevel(P_LED3, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit3));
  XMC_GPIO_SetOutputLevel(P_LED4, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit4));
  XMC_GPIO_SetOutputLevel(P_LED5, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit5));
  XMC_GPIO_SetOutputLevel(P_LED6, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit6));
  XMC_GPIO_SetOutputLevel(P_LED7, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit7));
  XMC_GPIO_SetOutputLevel(P_LED8, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit8));

  /* Check integer set by Master OUT_GEN_INT1 and set duty cycle of PWM driving LED 2 accordingly */
  //PWM_CCU8_SetDutyCycleSymmetric(&PWM_CCU8_0, XMC_CCU8_SLICE_COMPARE_CHANNEL_1,
//		  6000+((uint32_t)4000*(uint32_t)OUT_GENERIC->OUT_GEN_INT1)/65535);

  /* INPUT PROCESSING */
  /*Check Button 1 and set IN_GEN_Bit1 which is sent to master accordingly*/
  if (XMC_GPIO_GetInput(P15_13))
    IN_GENERIC->IN_GEN_Bit1 = 1;
  else
    IN_GENERIC->IN_GEN_Bit1 = 0;

  /*Check Button 2 and set IN_GEN_Bit2 which is sent to master accordingly*/
  if (XMC_GPIO_GetInput(P15_12))
    IN_GENERIC->IN_GEN_Bit2 = 1;
  else
    IN_GENERIC->IN_GEN_Bit2 = 0;
}
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;
  uint32_t timer =0;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  Init_ECAT_Adapt_LED ();                   /* Initialize the ports which drive LEDs on EtherCat shield*/
  Init_Relax_Button();                      /* Initialize buttons on XMC4800 */


  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  MainLoop();
  }
}
