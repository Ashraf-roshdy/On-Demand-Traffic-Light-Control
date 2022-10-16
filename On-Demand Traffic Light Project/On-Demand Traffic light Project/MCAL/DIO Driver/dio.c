/*
 * dio.c
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */
#include "dio.h"



/*-------------------------------DIO Function --------------------------------*/

/*
 Function    : DIO_init. 
 Type	     : Value-Returning function.
 Description : Set (pin Number, port Number and pin Direction) and check there validity.
 Inputs	     : pinNumber && portNumber && pinDirection.
 Returns     : DIO_OK || WRONG_PinNumber || WRONG_PortNumber || WRONG_PinDirection.
 */
EN_DIOError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection)
{
	if ( pinNumber>7 || pinNumber<0 ) //Check if Pin Number is within the valid range from 0 to 7, if not return WRONG_PinNumber.
	{
		return WRONG_PinNumber;
	}
	else
	{
		switch(portNumber) //Switch between Port Numbers (Port A, Port B, Port C, Port D).
		{
			case PORT_A:
				if(pinDirection ==IN)
				{
					DDRA &= ~(1<<pinNumber); //Pin Direction = Input
				}
				else if(pinDirection ==OUT)
				{
					DDRA |= (1<<pinNumber); //Pin Direction = Output
				}
				else
				{
					return WRONG_PinDirection; //if Pin Direction != (Input || Output), return WRONG_PinDirection.
				}		
				break;
				
			case PORT_B:
				if(pinDirection ==IN)
				{
					DDRB &= ~(1<<pinNumber); //Pin Direction = Input
				}
				else if(pinDirection ==OUT)
				{
					DDRB |= (1<<pinNumber); //Pin Direction = Output
				}
				else
				{
					return WRONG_PinDirection; //if Pin Direction != (Input || Output), return WRONG_PinDirection.
				}
				break;
				
			case PORT_C:
				if(pinDirection ==IN)
				{
					DDRC &= ~(1<<pinNumber); //Pin Direction = Input
				}
				else if(pinDirection ==OUT)
				{
					DDRC |= (1<<pinNumber); //Pin Direction = Output
				}
				else
				{
					return WRONG_PinDirection; //if Pin Direction != (Input || Output), return WRONG_PinDirection.
				}
				break;
				
			case PORT_D:
				if(pinDirection ==IN)
				{
					DDRD &= ~(1<<pinNumber); //Pin Direction = Input
				}
				else if(pinDirection ==OUT)
				{
					DDRD |= (1<<pinNumber); //Pin Direction = Output
				}
				else
				{
					return WRONG_PinDirection; //if Pin Direction != (Input || Output), return WRONG_PinDirection.
				}
				break;
				
			default:
				return WRONG_PortNumber; //if Port Number != (Port A || Port B || Port C || Port D), return WRONG_PortNumber.
		}
		return DIO_OK; //if all the previous inputs are valid, return DIO_OK.
	}
}

/*
 Function    : DIO_Write. 
 Type	     : Value-Returning function.
 Description : Set (pin Number, port Number and pin Value) and check there validity.
 Inputs	     : pinNumber && portNumber && pinValue.
 Returns     : DIO_OK || WRONG_PinNumber || WRONG_PortNumber || WRONG_PinValue.
 */
EN_DIOError_t DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t pinValue)
{
	if ( pinNumber>7 || pinNumber<0 ) //Check if Pin Number is within the valid range from 0 to 7, if not return WRONG_PinNumber.
	{
		return WRONG_PinNumber;
	}
	else
	{
		switch(portNumber) //Switch between Port Numbers (Port A, Port B, Port C, Port D).
		{
			case PORT_A:
				if(pinValue ==LOW)
				{
					PORTA &=~ (1<<pinNumber); //Write 0 to the targeted Pin Number.
				}
				else if(pinValue ==High)
				{
					PORTA |= (1<<pinNumber); //Write 1 to the targeted Pin Number.
				}
				else
				{
					return WRONG_PinValue; //if Pin Value != (Low || High), return WRONG_PinValue.
				}
				break;
			
			case PORT_B:
				if(pinValue ==LOW)
				{
					PORTB &=~ (1<<pinNumber); //Write 0 to the targeted Pin Number.
				}
				else if(pinValue ==High)
				{
					PORTB |= (1<<pinNumber); //Write 1 to the targeted Pin Number.
				}
				else
				{
					return WRONG_PinValue; //if Pin Value != (Low || High), return WRONG_PinValue.
				}
				break;
			
			case PORT_C:
				if(pinValue ==LOW)
				{
					PORTC &=~ (1<<pinNumber); //Write 0 to the targeted Pin Number.
				}
				else if(pinValue ==High)
				{
					PORTC |= (1<<pinNumber); //Write 1 to the targeted Pin Number.
				}
				else
				{
					return WRONG_PinValue; //if Pin Value != (Low || High), return WRONG_PinValue.
				}
				break;
			
			case PORT_D:
				if(pinValue ==LOW)
				{
					PORTD &=~ (1<<pinNumber); //Write 0 to the targeted Pin Number.
				}
				else if(pinValue ==High)
				{
					PORTD |= (1<<pinNumber); //Write 1 to the targeted Pin Number.
				}
				else
				{
					return WRONG_PinValue; //if Pin Value != (Low || High), return WRONG_PinValue.
				}
				break;
				
			default:
				return WRONG_PortNumber; //if Port Number != (Port A || Port B || Port C || Port D), return WRONG_PortNumber.
		}
		return DIO_OK; //if all the previous inputs are valid, return DIO_OK.
	}
}

/*
 Function    : DIO_read. 
 Type	     : Value-Returning function.
 Description : Set (pin Number, port Number) and check there validity then read the Pin Value.
 Inputs	     : pinNumber && portNumber.
 Returns     : DIO_OK || WRONG_PinNumber || WRONG_PortNumber.
 */
EN_DIOError_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *pinValue)
{
	if ( pinNumber>7 || pinNumber<0 ) //Check if Pin Number is within the valid range from 0 to 7, if not return WRONG_PinNumber.
	{
		return WRONG_PinNumber;
	}
	else
	{
		switch(portNumber) //Switch between Port Numbers (Port A, Port B, Port C, Port D).
		{
			case PORT_A:
				*pinValue = (PINA & (1<<pinNumber)) >> pinNumber; //read Pin Value.
				break;
				
			case PORT_B:
				*pinValue = (PINB & (1<<pinNumber)) >> pinNumber; //read Pin Value.
				break;
				
			case PORT_C:
				*pinValue = (PINC & (1<<pinNumber)) >> pinNumber; //read Pin Value.
				break;
				
			case PORT_D:
				*pinValue = (PIND & (1<<pinNumber)) >> pinNumber; //read Pin Value.
				break;
				
			default:
				return WRONG_PortNumber; //if Port Number != (Port A || Port B || Port C || Port D), return WRONG_PortNumber.
		}
		return DIO_OK; //if all the previous inputs are valid, return DIO_OK.
	}
}

/*
 Function    : DIO_toggle. 
 Type	     : Value-Returning function.
 Description : Set (pin Number, port Number) and check there validity then Toggle the Pin.
 Inputs	     : pinNumber && portNumber.
 Returns     : DIO_OK || WRONG_PinNumber || WRONG_PortNumber.
 */
EN_DIOError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	if ( pinNumber>7 || pinNumber<0 ) //Check if Pin Number is within the valid range from 0 to 7, if not return WRONG_PinNumber.
	{
		return WRONG_PinNumber;
	}
	else
	{
		switch(portNumber) //Switch between Port Numbers (Port A, Port B, Port C, Port D).
		{
			case PORT_A:
				PORTA ^= (1<<pinNumber); //toggle Pin.
				break;
				
			case PORT_B:
				PORTB  ^= (1<<pinNumber); //toggle Pin.
				break;
				
			case PORT_C:
				PORTC ^= (1<<pinNumber); //toggle Pin.
				break;
				
			case PORT_D:
				PORTD ^= (1<<pinNumber); //toggle Pin.
				break;
				
			default:
				return WRONG_PortNumber; //if Port Number != (Port A || Port B || Port C || Port D), return WRONG_PortNumber
		}
		return DIO_OK; //if all the previous inputs are valid, return DIO_OK.
	}
}