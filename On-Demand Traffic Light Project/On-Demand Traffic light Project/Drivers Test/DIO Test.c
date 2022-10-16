/*
 * dio.c
 * Created: 10/10/2022
 * Author : Ashraf Roshdy
 */
/*
#define F_CPU 1000000UL
#include "../MCAL/DIO Driver/dio.h"
#include <util/delay.h>

uint8_t testpinValue = 0;

/ * DIO Function Prototypes
EN_DIOError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection);

EN_DIOError_t DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t pinValue);

EN_DIOError_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *pinValue);

EN_DIOError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);* /



int main (void){
	
	DIO_init(0,PORT_A,OUT);   //test DIO Write_High
	DIO_init(1,PORT_A,OUT);   //test DIO Write_Low
	DIO_init(2,PORT_A,IN);    //test DIO Read
	DIO_init(3,PORT_A,OUT);   //test DIO Read using LED
	DIO_init(4,PORT_A,OUT);   //test DIO Toggle
	

	while(1) {
	DIO_Write(0,PORT_A,High); //Write_High in Pin 0, Port A
	DIO_Write(1,PORT_A,LOW);  //Write_Low in Pin 1, Port A
		
	DIO_read(2,PORT_A,&testpinValue);//read Pin 2, Port A Value
	DIO_Write(3,PORT_A,testpinValue);//Write Pin 2, Port A Value	
	
	DIO_toggle(4,PORT_A);//toggle Pin 4, Port A
	_delay_ms(1000);
				
	}
	return 0;
}
*/
