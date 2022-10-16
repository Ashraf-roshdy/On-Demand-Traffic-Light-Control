/*
 * led.c
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */
#include "led.h"

/*-------------------------------LED Functions --------------------------------*/

/*
 Function    : LED_init.
 Type	     : Non_value Returning function.
 Description : Set (LED Pin Number, LED Port Number) then call DIO_init function and set the Pin Direction to Output. 
 Inputs	     : ledpinNumber && ledportNumber.
 Returns     : No Return.
 */
void LED_init(uint8_t ledpinNumber, uint8_t ledportNumber)
{
	DIO_init(ledpinNumber, ledportNumber, OUT);
}

/*
 Function    : LED_ON.
 Type	     : Non_value Returning function.
 Description : Set (LED Pin Number, LED Port Number) then call ledpinNumber function and set the Pin Value to High. 
 Inputs	     : ledpinNumber && ledportNumber.
 Returns     : No Return.
 */
void LED_ON(uint8_t ledpinNumber, uint8_t ledportNumber)
{
	DIO_Write(ledpinNumber, ledportNumber, High);
}

/*
 Function    : LED_OFF.
 Type	     : Non_value Returning function.
 Description : Set (LED Pin Number, LED Port Number) then call DIO_Write function and set the Pin Value to Low.
 Inputs	     : ledpinNumber && ledportNumber.
 Returns     : No Return.
 */
void LED_OFF(uint8_t ledpinNumber, uint8_t ledportNumber)
{
	DIO_Write(ledpinNumber, ledportNumber, LOW);
}

/*
 Function    : LED_toggle.
 Type	     : Non_value Returning function.
 Description : Set (LED Pin Number, LED Port Number) then call LED_toggle function and toggle the LED Pin. 
 Inputs	     : ledpinNumber && ledportNumber.
 Returns     : No Return.
 */
void LED_toggle(uint8_t ledpinNumber, uint8_t ledportNumber)
{
	DIO_toggle(ledpinNumber, ledportNumber);
}
