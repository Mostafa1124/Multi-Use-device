/*
 * Intr.h
 *
 *  Created on: Sep 2, 2023
 *      Author: 12 VOLT
 */

#ifndef HAL_KEYBAD_INTR_H_
#define HAL_KEYBAD_INTR_H_

#define Keypad_port  DIO_PORTB

#define Keypad_Row0  DIO_PIN0
#define Keypad_Row1  DIO_PIN1
#define Keypad_Row2  DIO_PIN2
#define Keypad_Row3  DIO_PIN3

#define Keypad_Clmn0  DIO_PIN4
#define Keypad_Clmn1  DIO_PIN5
#define Keypad_Clmn2  DIO_PIN6
#define Keypad_Clmn3  DIO_PIN7

void Keypad_Inti(void);
u8 keypad_GetVal(void);



#endif /* HAL_KEYBAD_INTR_H_ */
