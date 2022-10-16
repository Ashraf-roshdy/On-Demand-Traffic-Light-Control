/*
 * interrupt.h
 * Created: 9/28/2022
 * Author : Ashraf Roshdy
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*------------------------------Interrupt Register Macros--------------------------------*/
//MCUCR MCU Control Register Macros.
#define ISC00	0
#define ISC01	1

//TIFR The Timer/Counter Interrupt Flag Register Macros.
#define TOV0	0

//TIMSK The Timer/Counter Interrupt Mask Register Macros.
#define TOIE0	0

//GIFR General Interrupt Flag Register Macros.
#define INTF0	6

//GICR General Interrupt Control Register Macros.
#define INT0	6

/*------------------------------Interrupt Vectors--------------------------------*/
#define EXT_INT_0	__vector_1
#define TIMER0_OVF	__vector_11

/*----------------------------Enable Global Interrupt----------------------------*/
#define sei() __asm__ __volatile__("sei" ::: "memory")

/*-----------------------------Clear Global Interrupt----------------------------*/
#define cli() __asm__ __volatile__("cli" ::: "memory")

/*--------------------------------ISR Definition---------------------------------*/
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#endif /* INTERRUPT_H_ */