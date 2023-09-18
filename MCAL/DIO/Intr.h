/*
 * Intr.h
 *
 *  Created on: Aug 26, 2023
 *      Author: 12 VOLT
 */

#ifndef MCAL_DIO_INTR_H_
#define MCAL_DIO_INTR_H_


#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3

#define  PORT_In    0x00
#define  PORT_OUT   0xff

#define  PORT_LOW   0x00
#define  PORT_HIGH  0xff

#define PIN_OUT		1
#define PIN_IN		0

#define PIN_HIGH		1
#define PIN_LOW			0

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

void SetPort_Dir(u8 port,u8 dir);
void SetPort_Val(u8 port,u8 val);

void SetPin_Dir(u8 port,u8 pin,u8 dir);
void SetPin_Val(u8 port,u8 pin,u8 val);

void Tog_Pin(u8 port , u8 pin);

u8 Get_PinVal(u8 port,u8 pin);
void Pin_pullUp(u8 port,u8 pin);

u8 seg(u8 n);


#endif /* MCAL_DIO_INTR_H_ */
