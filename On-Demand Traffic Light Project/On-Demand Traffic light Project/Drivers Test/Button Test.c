/*
 * dio.c
 * Created: 10/10/2022
 * Author : Ashraf Roshdy
 */
/*

#define F_CPU 1000000UL
#include "../MCAL/DIO Driver/dio.h"
#include "../ECUAL/Button Driver/button.h"


/ *Button Function Prototypes
void BUTTON_init(uint8_t ButtonpinNumber, uint8_t buttonportNumber);

void BUTTON_read(uint8_t ButtonpinNumber, uint8_t buttonportNumber, uint8_t *pinValue);* /

uint8_t testpinValue = 0;

int main (void){
	
	BUTTON_init(0,PORT_A);   //initialize Pin 0 Port A
	DIO_init(1,PORT_A,OUT);  //test Button read
	

	while(1) {
		
	BUTTON_read(0,PORT_A,&testpinValue); //read button press at Pin 0, Port A Value
	
	DIO_Write(1,PORT_A,testpinValue);	 //Write button Pin 0, Port A Value	
	
	}
	return 0;
}
*/

