/*
 * timer.c
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */ 

#include "timer.h"

/*-------------------------------Timer0 Function --------------------------------*/

/*
 Function    : Timer0_init.
 Type	     : Value-Returning function.
 Description : Set and check (Timer0 Mode) and set Timer Initial Value.
 Inputs	     : Timer0 Mode && Timer Initial Value.
 Returns     : Timer0_OK || WRONG_Timer0_Mode.
 */
EN_Timer0_Error_t Timer0_init(uint8_t timer_Mode, uint32_t timer_init_value)
{
	switch(timer_Mode) //Switch between Timer0 Modes.
	{
		case Normal:
			TCCR0 &=~ (1<<WGM00); //Write 0 to WGM00.
			TCCR0 &=~ (1<<WGM01); //Write 0 to WGM01.
			break;
			
		case PWM:
			TCCR0 |= (1<<WGM00);  //Write 1 to WGM00.
			TCCR0 &=~ (1<<WGM01); //Write 0 to WGM01.
			break;
			
		case CTC:
			TCCR0 &=~ (1<<WGM00); //Write 0 to WGM00.
			TCCR0 |= (1<<WGM01);  //Write 1 to WGM01.
			break;
			
		case FAST_PWM:
			TCCR0 |= (1<<WGM00);  //Write 1 to WGM00.
			TCCR0 |= (1<<WGM01);  //Write 1 to WGM01.
			break;
			
		default:
			return WRONG_Timer0_Mode; //if Timer0 Mode != (Normal || PWM || CTC || FAST_PWM), return WRONG_Timer0_Mode.
	}
	
	//Set Timer Initial Value
	TCNT0 = timer_init_value;
		
	return Timer0_OK; //if all the previous inputs are valid, return Timer0_OK.
}

/*
 Function    : Timer0_start.
 Type	     : Value-Returning function.
 Description : Set and check (Timer0 Pre_scaler).
 Inputs	     : Timer0 Pre_scaler.
 Returns     : Timer0_OK || WRONG_Timer0_Prescaler.
 */
EN_Timer0_Error_t Timer0_start(uint8_t timer_Prescaler)
{
	switch(timer_Prescaler) //Switch between Timer0 Pre_scaler Modes.
	{
		case No_prescaling:
			TCCR0 |=  (1<<CS00); //Write 1 to CS00.
			TCCR0 &=~ (1<<CS01); //Write 0 to CS01.
			TCCR0 &=~ (1<<CS02); //Write 0 to CS02.
			break;
		case prescaler_8:
			TCCR0 &=~ (1<<CS00); //Write 0 to CS00.
			TCCR0 |=  (1<<CS01); //Write 1 to CS01.
			TCCR0 &=~ (1<<CS02); //Write 0 to CS02.
			break;
		case prescaler_64:
			TCCR0 |=  (1<<CS00); //Write 1 to CS00.
			TCCR0 |=  (1<<CS01); //Write 1 to CS01.
			TCCR0 &=~ (1<<CS02); //Write 0 to CS02.
			break;
		case prescaler_256:
			TCCR0 &=~ (1<<CS00); //Write 0 to CS00.
			TCCR0 &=~ (1<<CS01); //Write 0 to CS01.
			TCCR0 |=  (1<<CS02); //Write 1 to CS02.
			break;	
		case prescaler_1024:
			TCCR0 |=  (1<<CS00); //Write 1 to CS00.
			TCCR0 &=~ (1<<CS01); //Write 0 to CS01.
			TCCR0 |=  (1<<CS02); //Write 1 to CS02.
			break;
		default:
			return WRONG_Timer0_Prescaler; //if Timer0 Mode != (No_prescaling || prescaler_8 || prescaler_64 || prescaler_256 || prescaler_1024), return WRONG_Timer0_Prescaler.
	}
	
	return Timer0_OK; //if all the previous inputs are valid, return Timer0_OK.
}

/*
 Function    : Timer0_stop.
 Type	     : Non_value Returning function.
 Description : Stop Timer0 by clearing the control register. 
 Inputs	     : Void.
 Returns     : No Return.
 */
void Timer0_stop(void)
{
	TCCR0 = 0x00;
}
