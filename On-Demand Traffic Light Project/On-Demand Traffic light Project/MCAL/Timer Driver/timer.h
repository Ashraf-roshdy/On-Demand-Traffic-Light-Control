/*
 * timer.h
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilites/types.h"
#include "../../Utilites/registers.h"
#include "../../Utilites/interrupt.h"

/*------------------------------TIMER0 Macros--------------------------------*/
//TCCR0 Timer0 control register Macros.
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM00	6
#define WGM01	3

//TIMER0 Mode Macros.
#define Normal		0
#define PWM			1
#define CTC			2
#define FAST_PWM	3

//Timer0 Pre_scaler Macros.
#define No_prescaling	0
#define prescaler_8		1
#define prescaler_64	2
#define prescaler_256	3
#define prescaler_1024	4

/*----------------------------TIMER0 Typedefs-------------------------------*/
typedef enum EN_Timer0_Error_t
	{
	Timer0_OK,				//NO errors.
	WRONG_Timer0_Mode,		//Wrong Timer0 Mode.
	WRONG_Timer0_Prescaler	//Wrong Timer0 Pre_scaler.
	}EN_Timer0_Error_t;

/*----------------------TIMER0 Function Prototypes--------------------------*/
EN_Timer0_Error_t Timer0_init(uint8_t timer_Mode, uint32_t timer_init_value);

EN_Timer0_Error_t Timer0_start(uint8_t timer_Prescaler);

void Timer0_stop(void);

#endif /*TIMER_H_*/