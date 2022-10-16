/*
 * button.h
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"

/*--------------------------Button Function Prototypes-----------------------------*/
void BUTTON_init(uint8_t ButtonpinNumber, uint8_t buttonportNumber);

void BUTTON_read(uint8_t ButtonpinNumber, uint8_t buttonportNumber, uint8_t *pinValue);

#endif /* BUTTON_H_ */