/*
 * button.c
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */
#include "button.h"

/*-------------------------------Button Functions --------------------------------*/

/*
 Function    : BUTTON_init.
 Type	     : Non_value Returning function.
 Description : Set (Button Pin Number, Button Port Number) then call DIO_init function and set the Pin Direction to Input. 
 Inputs	     : ButtonpinNumber && buttonportNumber.
 Returns     : No Return.
 */
void BUTTON_init(uint8_t ButtonpinNumber, uint8_t buttonportNumber)
{
	DIO_init(ButtonpinNumber, buttonportNumber,IN);
}

/*
 Function    : BUTTON_read.
 Type	     : Non_value Returning function.
 Description : Set (Button Pin Number, Button Port Number) then call DIO_read function and get the Pin Value. 
 Inputs	     : ButtonpinNumber && buttonportNumber.
 Returns     : No Return.
 */
void BUTTON_read(uint8_t ButtonpinNumber, uint8_t buttonportNumber, uint8_t *pinValue)
{
	DIO_read(ButtonpinNumber, buttonportNumber, pinValue);
}
