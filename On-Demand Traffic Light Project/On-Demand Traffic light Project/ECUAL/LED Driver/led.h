/*
 * led.h
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"

/*--------------------------LED Function Prototypes-----------------------------*/	
void LED_init(uint8_t ledpinNumber, uint8_t ledportNumber);

void LED_ON(uint8_t ledpinNumber, uint8_t ledportNumber);

void LED_OFF(uint8_t ledpinNumber, uint8_t ledportNumber);

void LED_toggle(uint8_t ledpinNumber, uint8_t ledportNumber);

#endif /* LED_H_ */