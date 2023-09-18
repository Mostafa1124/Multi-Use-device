/*
 * Prog.c
 *
 *  Created on: Sep 2, 2023
 *      Author: 12 VOLT
 */
#define F_CPU	8000000
#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Types.h"
#include "../../MCAL/DIO/Intr.h"
#include "Intr.h"

const u8 KeyPadVal[4][4] =
			{{'7','8','9','/'},
			 {'4','5','6','*'},
		   	 {'1','2','3','-'},
			 {'n','0','=','+'}
			};

void Keypad_Inti(void)
{
	SetPin_Dir(Keypad_port, Keypad_Row0, PIN_IN);
	SetPin_Dir(Keypad_port, Keypad_Row1, PIN_IN);
	SetPin_Dir(Keypad_port, Keypad_Row2, PIN_IN);
	SetPin_Dir(Keypad_port, Keypad_Row3, PIN_IN);

	SetPin_Dir(Keypad_port, Keypad_Clmn0, PIN_OUT);
	SetPin_Dir(Keypad_port, Keypad_Clmn1, PIN_OUT);
	SetPin_Dir(Keypad_port, Keypad_Clmn2, PIN_OUT);
	SetPin_Dir(Keypad_port, Keypad_Clmn3, PIN_OUT);

	SetPin_Val(Keypad_port, Keypad_Clmn0, PIN_HIGH);
	SetPin_Val(Keypad_port, Keypad_Clmn1, PIN_HIGH);
	SetPin_Val(Keypad_port, Keypad_Clmn2, PIN_HIGH);
	SetPin_Val(Keypad_port, Keypad_Clmn3, PIN_HIGH);

	Pin_pullUp(Keypad_port, Keypad_Row0);
	Pin_pullUp(Keypad_port, Keypad_Row1);
	Pin_pullUp(Keypad_port, Keypad_Row2);
	Pin_pullUp(Keypad_port, Keypad_Row3);



}
u8 keypad_GetVal(void)
{
	u8 val=0;
	for(int i=Keypad_Clmn0;i<=Keypad_Clmn3;i++)
	{
		SetPin_Val(Keypad_port,i, PIN_LOW);
		for(int j=Keypad_Row0;j<=Keypad_Row3;j++)
		{
			if(Get_PinVal(Keypad_port, j)==0)
			{
				val=KeyPadVal[j][i-4];
				while(Get_PinVal(Keypad_port, j)==0);
			}
			_delay_ms(10);

		}
		SetPin_Val(Keypad_port,i, PIN_HIGH);

	}


	return val;
}
