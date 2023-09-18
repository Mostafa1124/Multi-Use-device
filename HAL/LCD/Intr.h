/*
 * Intr.h
 *
 *  Created on: Aug 30, 2023
 *      Author: 12 VOLT
 */

#ifndef HAL_LCD_INTR_H_
#define HAL_LCD_INTR_H_


#define LCD_Ctrl_Port	 DIO_PORTD
#define LCD_Data_Port	 DIO_PORTC


#define	LCD_Rs_Pin   	DIO_PIN0
#define LCD_Rw_Pin   	DIO_PIN1
#define LCD_Enable_Pin 	DIO_PIN7





void LCD_INTI(void);
void LCD_SendCMD(u8 cmd);
void LCD_SendChar(u8 data);
void LCD_SendString(u8 *str);
void LCD_Clear(void);
void LCD_GoTO(u8 row, u8 clm);
void Lcd_IntToChar(s32 inte);

#endif /* HAL_LCD_INTR_H_ */
