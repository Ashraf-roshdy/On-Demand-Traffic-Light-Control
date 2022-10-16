/*
 * dio.h
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */

#ifndef DIO_H_
#define DIO_H_
#include "../../Utilites/registers.h"

/*------------------------------DIO Macros--------------------------------*/
//Port Number Macros.
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Pin Direction Macros.
#define IN		0
#define OUT		1

//Pin Value Macros.
#define LOW		0
#define High	1

/*-----------------------------DIO Typedefs-------------------------------*/
typedef enum EN_DIOError_t
	{
	DIO_OK,				//NO errors.
	WRONG_PortNumber,   //Wrong port number.
	WRONG_PinNumber,    //Wrong pin number.
	WRONG_PinDirection, //Wrong direction.
	WRONG_PinValue      //Wrong Pin Value.
	}EN_DIOError_t;

/*--------------------------DIO Function Prototypes-------------------------*/
EN_DIOError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection);

EN_DIOError_t DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t pinValue);

EN_DIOError_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *pinValue);

EN_DIOError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);

#endif /* DIO_H_ */