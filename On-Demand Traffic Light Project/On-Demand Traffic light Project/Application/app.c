/*
 * app.c
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */
#define F_CPU 1000000UL
#include "app.h"

uint8_t CAR_Mode		= 0;
uint8_t PED_Mode		= 0;
uint8_t Timer0_OverFlow_5sec = 0; 
uint8_t Timer0_OverFlow_Car_Toggle = 0;
uint8_t Timer0_OverFlow_PED_Toggle = 0;

/*
 Function    : app_init.
 Type	     : Non_value Returning function.
 Description : Initialize (Car and Pedestrian LEDs && Button), Enable Interrupts, set INT0 sensing, Initialize and Start Timer0.
 Returns     : No Return.
 */
 void app_init()
{
	//Set car's LEDs Pin Number/Port Number/Pin Direction.
	DIO_init(CAR_G_Pin,	CAR_PORT, OUT);
	DIO_init(CAR_Y_Pin,	CAR_PORT, OUT);
	DIO_init(CAR_R_Pin,	CAR_PORT, OUT);
		
	//Set Pedestrian's LEDs Pin Number/Port Number/Pin Direction.
	DIO_init(PED_G_Pin, PED_PORT, OUT);
	DIO_init(PED_Y_Pin,	PED_PORT, OUT);
	DIO_init(PED_R_Pin,	PED_PORT, OUT);
		
	//Set Pedestrian's Button Pin Number/Port Number.	
	BUTTON_init(PED_BTN_Pin, BTN_PORT);
		
	//Enable Global Interrupts.		
	sei();
		
	//Enable Timer 0 Overflow Interrupt.
	TIMSK |= (1<<TOIE0);
	
	//Set INT0 to Sense on Falling edge.
	MCUCR &=~ (1<<ISC00);  //ISC00 = 0
	MCUCR |= (1<<ISC01);   //ISC01 = 1
		
	// Enable External Interrupt-INT0.
	GICR |= (1<<INT0);
		
	//Initialize Timer0 in Normal Mode and set the initial value.
	Timer0_init	(Normal,Timer0_InitialValue);
	
	// Start Timer With Pre_scaler 1024.
	Timer0_start(prescaler_1024);
}

/*
 Function    : app_start.
 Type	     : Non_value Returning function.
 Description : Switch cases for the transition for both Car and Pedestrian Modes
 Returns     : No Return.
 */
 void app_start()
{	
	while(1)
	{
		switch(CAR_Mode)
			{//Car Mode Sequence Green -> Yellow_Red -> Red -> Yellow-Green and Repeat. 
				case CAR_GREEN:
					LED_ON (CAR_G_Pin,CAR_PORT);		//Turn On Car GREEN lED.
					LED_OFF(CAR_Y_Pin, CAR_PORT);
					LED_OFF(CAR_R_Pin, CAR_PORT);
					break;	
					
				case CAR_YELLOW_RED:
					LED_OFF(CAR_G_Pin,CAR_PORT);
					if (Timer0_OverFlow_Car_Toggle > Timer0_NumberofOverFlows_toggle)
					{
						LED_toggle(CAR_Y_Pin,CAR_PORT);	//Toggle Car Yellow lED.
						Timer0_OverFlow_Car_Toggle =0 ;
					}
					LED_OFF(CAR_R_Pin, CAR_PORT);
					break;
					
				case CAR_RED:
					LED_OFF(CAR_G_Pin,CAR_PORT);
					LED_OFF(CAR_Y_Pin, CAR_PORT);
					LED_ON (CAR_R_Pin, CAR_PORT);		//Turn On Car RED lED.
					break;
			
				case CAR_YELLOW_Green:
					LED_OFF(CAR_G_Pin,CAR_PORT);
					if (Timer0_OverFlow_Car_Toggle > Timer0_NumberofOverFlows_toggle)
					{
						LED_toggle(CAR_Y_Pin,CAR_PORT);	//Toggle Car Yellow lED.
						Timer0_OverFlow_Car_Toggle =0 ;
					}
					LED_OFF(CAR_R_Pin, CAR_PORT);
					break;
			
				case Car_LED_Repeat:
					CAR_Mode=CAR_GREEN;					//Repeat Car Mode.
					break;
			}
				
		switch(PED_Mode)
			{//Pedestrian Mode Sequence Red -> Yellow-Green -> Green -> Yellow-Red and Repeat.
				case PED_RED:
					LED_OFF(PED_G_Pin,PED_PORT);	
					LED_OFF(PED_Y_Pin,PED_PORT);
					LED_ON (PED_R_Pin,PED_PORT);		//Turn On Pedestrian RED led.
					break;
					
				case PED_YELLOW_Green:
					LED_OFF(PED_G_Pin,PED_PORT);
					if (Timer0_OverFlow_PED_Toggle > Timer0_NumberofOverFlows_toggle)
					{
						LED_toggle(PED_Y_Pin,PED_PORT);	//Toggle Pedestrian Yellow lED.
						Timer0_OverFlow_PED_Toggle =0 ;
					}
					LED_OFF(PED_R_Pin,PED_PORT);
					break;
					
				case PED_GREEN:
					LED_ON (PED_G_Pin,PED_PORT); 		// Turn On Pedestrian Green led.
					LED_OFF(PED_Y_Pin,PED_PORT);
					LED_OFF(PED_R_Pin,PED_PORT);
				break;
					
				case PED_YELLOW_RED:
					LED_OFF(PED_G_Pin,PED_PORT);
					LED_OFF(PED_R_Pin,PED_PORT);
					if (Timer0_OverFlow_PED_Toggle > Timer0_NumberofOverFlows_toggle)
					{
						LED_toggle(PED_Y_Pin,PED_PORT);	//Toggle Pedestrian Yellow lED.
						Timer0_OverFlow_PED_Toggle =0 ;
					}
					break;
					
				case PED_LED_Repeat:
					PED_Mode=PED_RED;					//Repeat Pedestrian Mode.
					break;
			}			
	}
}

ISR(TIMER0_OVF)
{
	//increment the 5 sec counter.
	Timer0_OverFlow_5sec++;
	
	if (Timer0_OverFlow_5sec < Timer0_NumberofOverFlows)
		{	//if the 5 sec counter is less than the total number of over flow and Yellow LEDs was ON, Then increment the toggle Counter.
			if (CAR_Mode==CAR_YELLOW_RED || CAR_Mode==CAR_YELLOW_Green)
				{//increment both Yellow toggle counters.
					Timer0_OverFlow_Car_Toggle++;	
					Timer0_OverFlow_PED_Toggle++;
				}
		}
	
	if (Timer0_OverFlow_5sec >= Timer0_NumberofOverFlows)
		{	//Check if the 5 sec counter is bigger than or equal the total number of over flow, Then go to next Case.
			CAR_Mode++;
			PED_Mode++;
			//clear all the Counters.
			Timer0_OverFlow_5sec = 0;
			Timer0_OverFlow_Car_Toggle = 0;
			Timer0_OverFlow_PED_Toggle = 0;
			}
}




ISR(EXT_INT_0)
{
	//if external interrupt detected a falling edge,Then the upcoming function will take place.
		if (CAR_Mode==CAR_GREEN || CAR_Mode==CAR_YELLOW_Green)
		{//if Car Mode = Green or Yellow->Green then both of Yellow LEDs with Toggle For 5 Sec then Car Mode=Red & PED Mode=Green.
			CAR_Mode=CAR_YELLOW_RED;
			PED_Mode=PED_YELLOW_Green;
			//Clear all Counters.
			Timer0_OverFlow_5sec =0;
			Timer0_OverFlow_Car_Toggle =0;
			Timer0_OverFlow_PED_Toggle =0;
		}	
		if (CAR_Mode==CAR_RED)
		{//if Car Mode = Red then the count will start all over again.
			CAR_Mode=CAR_RED;
			PED_Mode=PED_GREEN;
			//Clear all Counters.
			Timer0_OverFlow_5sec =0;
			Timer0_OverFlow_Car_Toggle =0;
			Timer0_OverFlow_PED_Toggle =0;
		}
		if (CAR_Mode==CAR_YELLOW_RED)
		{
			//if Car Mode = YELLOW->RED, then do nothing.
		}
}
