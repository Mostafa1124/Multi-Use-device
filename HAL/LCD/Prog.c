/*
 * Prog.c
 *
 *  Created on: Aug 30, 2023
 *      Author: 12 VOLT
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Types.h"
#include "../../MCAL/DIO/Intr.h"
#include "Intr.h"



void LCD_INTI(void)
{
SetPin_Dir(LCD_Ctrl_Port, LCD_Rs_Pin, PIN_OUT);
SetPin_Dir(LCD_Ctrl_Port, LCD_Rw_Pin, PIN_OUT);
SetPin_Dir(DIO_PORTA, LCD_Enable_Pin, PIN_OUT);

	_delay_ms(30);
SetPort_Dir(LCD_Data_Port, PORT_OUT);
LCD_SendCMD(0b00111100);
	_delay_ms(1);
LCD_SendCMD(0b00001111);
	_delay_ms(1);
LCD_SendCMD(0b00000001);
	_delay_ms(2);
LCD_SendCMD(0b00000110);

}
void LCD_SendCMD(u8 cmd)
{
	SetPin_Val(LCD_Ctrl_Port,LCD_Rs_Pin, PIN_LOW);
	SetPin_Val(LCD_Ctrl_Port,LCD_Rw_Pin, PIN_LOW);
	SetPort_Val(LCD_Data_Port, cmd);

	SetPin_Val(DIO_PORTA, LCD_Enable_Pin, PIN_HIGH );
	_delay_ms(1);
	SetPin_Val(DIO_PORTA , LCD_Enable_Pin , PIN_LOW);
	_delay_ms(1);

}
void LCD_SendChar(u8 data)
{
	SetPin_Val(LCD_Ctrl_Port,LCD_Rs_Pin, PIN_HIGH);
	SetPin_Val(LCD_Ctrl_Port,LCD_Rw_Pin, PIN_LOW);
	SetPort_Val(LCD_Data_Port, data);

	SetPin_Val(DIO_PORTA, LCD_Enable_Pin, PIN_HIGH );
		_delay_ms(1);
	SetPin_Val(DIO_PORTA , LCD_Enable_Pin , PIN_LOW);
		_delay_ms(1);

}
void LCD_SendString(u8 *str)
{
	while(*str !='\0')
	{
		LCD_SendChar(*str);
		str++;

	}


}


void LCD_Clear(void)
{
	LCD_SendCMD(0b00000001);
}
void LCD_GoTO(u8 row, u8 clm)
{
	switch(row)
	{
	case 1: LCD_SendCMD(128+clm);	break;
	case 2: LCD_SendCMD(192+clm);	break;
	}
}
void Lcd_IntToChar(s32 inte)
{
	if(inte<0)
	{
		LCD_SendChar('-');
		inte=inte*(-1);
	}

	u32 cha=0;
	u8 ZeroesNumber=0;
	while(inte%10==0&&inte!=0)
	{
		ZeroesNumber++;
		inte=inte/10;
	}
	while(inte)
	{
		cha=cha*10;
		cha=cha+(inte%10);
		inte=inte/10;
	}
	if (cha ==0)
	{
		LCD_SendChar('0');
	}
	while(cha)
	{
		LCD_SendChar((cha%10)+'0');
		cha=cha/10;

	}
	while(ZeroesNumber--)
	{
		LCD_SendChar('0');
	}

}



