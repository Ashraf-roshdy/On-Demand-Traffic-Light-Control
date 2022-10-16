/*
 * app.h
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */

#ifndef APP_H_
#define APP_H_

#include "../MCAL/Timer Driver/timer.h"
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include "../Utilites/interrupt.h"

/*------------------------------APP Macros--------------------------------*/
//Car's Traffic light Macros
#define CAR_PORT	PORT_A
#define CAR_G_Pin   0
#define CAR_Y_Pin   1
#define CAR_R_Pin   2

//Pedestrian's Traffic light Macros
#define PED_PORT	PORT_B
#define PED_G_Pin   0
#define PED_Y_Pin   1
#define PED_R_Pin   2

//Pedestrian's Button Macros
#define BTN_PORT	PORT_D
#define PED_BTN_Pin 2

//Car Mode Macros
#define CAR_GREEN			0 //Green then yellow
#define CAR_YELLOW_RED		1 //yellow then red
#define CAR_RED				2 //red then yellow
#define CAR_YELLOW_Green	3 //yellow then green
#define Car_LED_Repeat		4 //jump to CAR_GREEN

//Pedestrian Mode Macros
#define PED_RED				0 //red then yellow
#define PED_YELLOW_Green	1 //yellow then green
#define PED_GREEN			2 //Green then yellow
#define PED_YELLOW_RED		3 //yellow then red
#define PED_LED_Repeat		4 //jump to PED_RED

// Timer0 Macros For switching between LEDS (5 sec)		
	//FCPU = 1MHZ=1000000
	//Required Delay = 5 Sec
	//used Pre_scaler 1024
	//T-tick = Pre_scaler / FCPU = 0.001024
	//Timer(Max Delay) = T-tick * 256 #8-bits Timer = 0.262144
	//Number of over flows = Required Delay / Timer(Max Delay) = 19.0734 == 19 over flows
	//Timer Initial Value= 256 - ((Required Delay / T-tick) / Number of over flows)=12	
#define Timer0_NumberofOverFlows			19
#define Timer0_InitialValue					12

// Timer0 Macros For Yellow LED Toggling.
#define Timer0_NumberofOverFlows_toggle 	2

/*--------------------------APP Function Prototypes-----------------------*/
void app_init(void);

void app_start(void);

#endif /* APP_H_ */