/*
 * dio.c
 * Created: 10/10/2022
 * Author : Ashraf Roshdy
 */
/*

#define F_CPU 1000000UL
#include "../ECUAL/LED Driver/led.h"
#include <util/delay.h>

/ *LED Function Prototypes
void LED_init(uint8_t ledpinNumber, uint8_t ledportNumber);

void LED_ON(uint8_t ledpinNumber, uint8_t ledportNumber);

void LED_OFF(uint8_t ledpinNumber, uint8_t ledportNumber);

void LED_toggle(uint8_t ledpinNumber, uint8_t ledportNumber);* /



int main (void){
	
	LED_init(0,PORT_A);   //initialize Pin 0 Port A
	LED_init(1,PORT_A);   //initialize Pin 1 Port A
	LED_init(2,PORT_A);   //initialize Pin 2 Port A
	
	while(1) {
		
	LED_ON(0,PORT_A);		//turn on led at Pin 0 Port A
	
	LED_OFF(1,PORT_A);		//turn OFF led at Pin 1 Port A
	
	LED_toggle(2,PORT_A);	//Toggle led at Pin 2 Port A
	_delay_ms(1000);
	
	}
	return 0;
}*/

