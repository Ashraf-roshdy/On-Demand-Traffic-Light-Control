/*
 * dio.c
 * Created: 10/10/2022
 * Author : Ashraf Roshdy
 */
/*
#define F_CPU 1000000UL
#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Timer Driver/timer.h"



#define Number_of_overflows 61
uint8_t OverFlow_Counter = 0;

/ *TIMER0 Function Prototypes

EN_Timer0_Error_t Timer0_init(uint8_t timer_Mode, uint32_t timer_init_value);

EN_Timer0_Error_t Timer0_start(uint8_t timer_Prescaler);

void Timer0_stop(void);* /

//FCPU = 1MHZ=1000000
//Required Delay = 1 Sec
//used Pre_scaler 64
//T-tick = Pre_scaler / FCPU = 0.000046
//Timer(Max Delay) = T-tick * 256 #8-bits Timer = 0.016384
//Number of over flows = Required Delay / Timer(Max Delay) = 61 over flow

int main (void){
	
	Timer0_init(Normal,0);         
	
	DIO_init(0,PORT_A,OUT);
	
	while(1)
	 {
		
		DIO_toggle(0,PORT_A);
	
		Timer0_start(prescaler_64);   
		
		while( OverFlow_Counter < Number_of_overflows)
		{
		
		// wait until the overflow flag to be set
		while((TIFR & (1<<TOV0)) == 0);
		
		// Clear the overflow flag
		TIFR |= (1<<TOV0);
		
		OverFlow_Counter++;
		
		}
	
		OverFlow_Counter = 0;
	
		Timer0_stop();
	 }
	return 0;
}*/
