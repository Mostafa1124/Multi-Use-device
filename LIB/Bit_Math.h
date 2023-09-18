/*
 * LIB.h
 *
 *  Created on: Aug 25, 2023
 *      Author: 12 VOLT
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define Set_Bit(reg,bit)    (reg |=  (1<<bit))
#define Clr_Bit(reg,bit)    (reg &=~ (1<<bit))
#define toggle_Bit(reg,bit) (reg ^=  (1<<bit))
#define get_Bit(reg,bit)    ((reg>>bit) & 0x01)


#endif
