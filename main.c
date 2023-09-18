/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: 12 VOLT
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LIB/Bit_Math.h"
#include "LIB/Types.h"
#include "MCAL/DIO/Intr.h"
#include "MCAL/timer/Intr.h"
#include "HAL/LCD/Intr.h"
#include "HAL/KEYBAD/Intr.h"
#include "Clock/Intr.h"


void main (void)
{

Keypad_Inti();
LCD_INTI();
u32 password=1;
u8 data;
u8 mode;


/************************************************************************************************
*************************************************************************************************
***************************************------(PASSWORD)-----*************************************
*************************************************************************************************
*************************************************************************************************
*************************************************************************************************/


LCD_SendString("Enter password");
	LCD_GoTO(2, 0);
	while(1)
		{
			u8 tmp =keypad_GetVal();
				if(tmp!=0)
				{
					if(tmp>='0'&&tmp<='9')
					{
						LCD_SendChar('*');
						password=password*10;
						password=password+(tmp-'0');
						tmp=0;

					}
					else if(tmp=='=')
					{
						if(password==10123456)
						{
						LCD_Clear();
						break;
						}

						else
						{
							LCD_Clear();
							LCD_SendString("wrong password");
							_delay_ms(1000);
							LCD_Clear();
							LCD_SendString("Enter password");
							LCD_GoTO(2, 0);
							tmp=0;
							password=1;
						}

					}
					else
					{
						LCD_Clear();
						LCD_SendString("wrong ");
						_delay_ms(1000);
						LCD_Clear();
						LCD_SendString("Enter password");
						LCD_GoTO(2, 0);
						tmp=0;
						password=1;

					}
				}
		}

	/************************************************************************************************
	*************************************************************************************************
	**************************************------(SELECT_MODE)-----***********************************
	*************************************************************************************************
	*************************************************************************************************
	*************************************************************************************************/

LCD_SendString("1-clock 2-stop w");
LCD_GoTO(2, 0);
LCD_SendString("3-timer 4-calc");
LCD_GoTO(2, 14);
while (1)
{
	data =keypad_GetVal();
	if (data!=0)
	{
		LCD_SendChar(data);
		mode=data-'0';
		_delay_ms(500);
		if(mode==1||mode==2||mode==3||mode==4)
		{
		LCD_Clear();
		break;
		}
		else
		{
			LCD_Clear();
			LCD_SendString("wrong....");
			_delay_ms(1000);
			LCD_Clear();
			LCD_SendString("1-clock 2-stop w");
			LCD_GoTO(2, 0);
			LCD_SendString("3-timer 4-calc");
			LCD_GoTO(2, 14);

		}
	}

}



/************************************************************************************************
*************************************************************************************************
***************************************------(cLOCK)-----****************************************
*************************************************************************************************
*************************************************************************************************
*************************************************************************************************/


if (mode==1)
{
	while(1)
	{
		LCD_Clear();
		Keypad_Inti();
	SetPort_Dir(DIO_PORTA, PORT_OUT);
	SetPort_Dir(DIO_PORTC, PORT_OUT);
	SetPort_Dir(DIO_PORTD, PORT_OUT);
	u8 hour_1=Set_hour();
	u8 minute_1=Set_minute();
	u8 second_1=Set_second();

	LCD_SendString("to set clock ");
	LCD_GoTO(2, 0);
	LCD_SendString("press button(1) :) ");

	while(1)
		{
		for(u8 hour =hour_1;(hour<=12)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;hour++)
			{
			for( u8 minute =minute_1;(minute<60)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;minute++)
				{
				for( u8 second =second_1;(second<60)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;second++)
					{
							int n=20;
								while (n--)
								{
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_LOW);
									PORTA=seg(second%10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_LOW);
									PORTA=seg(second/10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_LOW);
									PORTA=seg(minute%10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_LOW);
									PORTA=seg(minute/10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_LOW);
									PORTA=seg(hour%10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_LOW);
									PORTA=seg(hour/10);
									_delay_ms(50/6);


										}
								second_1=0;

							}
						minute_1=0;
						}

					}
		hour_1=1;


		if (Get_PinVal(DIO_PORTB, DIO_PIN0)==0)
		{
			LCD_Clear();
			LCD_SendString("loading...");
			_delay_ms(2000);
			break;
		}



		}
}
}





/************************************************************************************************
*************************************************************************************************
***************************************------(stop watch)-----************************************
*************************************************************************************************
*************************************************************************************************
*************************************************************************************************/
if (mode==2)
{
	while(1)
	{
		LCD_Clear();
		Keypad_Inti();
	SetPort_Dir(DIO_PORTA, PORT_OUT);
	SetPort_Dir(DIO_PORTC, PORT_OUT);
	SetPort_Dir(DIO_PORTD, PORT_OUT);

	LCD_SendString("reset(1) pause(2) ");
	LCD_GoTO(2, 0);
	LCD_SendString("resume(3)");

	while(1)
		{
		for(u8 hour =0;(hour<=12)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;hour++)
			{
			for( u8 minute =0;(minute<60)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;minute++)
				{
				for( u8 second =0;(second<60)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;second++)
					{
							int n=20;

								while (n--)
								{
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_LOW);
									PORTA=seg(second%10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_LOW);
									PORTA=seg(second/10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_LOW);
									PORTA=seg(minute%10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_LOW);
									PORTA=seg(minute/10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_LOW);
									PORTA=seg(hour%10);
									_delay_ms(50/6);
									SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
									SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_LOW);
									PORTA=seg(hour/10);
									_delay_ms(50/6);


										}
								if(Get_PinVal(DIO_PORTB, DIO_PIN1)==0)
								{
									while(Get_PinVal(DIO_PORTB, DIO_PIN2)!=0)
										{
											SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_LOW);
											PORTA=seg(second%10);
											_delay_ms(50/6);
											SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_LOW);
											PORTA=seg(second/10);
											_delay_ms(50/6);
											SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_LOW);
											PORTA=seg(minute%10);
											_delay_ms(50/6);
											SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_LOW);
											PORTA=seg(minute/10);
											_delay_ms(50/6);
											SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_LOW);
											PORTA=seg(hour%10);
											_delay_ms(50/6);
											SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
											SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_LOW);
											PORTA=seg(hour/10);
											_delay_ms(50/6);

																}

															}


							}

						}

					}



		if (Get_PinVal(DIO_PORTB, DIO_PIN0)==0)
		{
			LCD_Clear();
			break;
		}



		}
}
}







/************************************************************************************************
*************************************************************************************************
***************************************------(TIMER)-----****************************************
*************************************************************************************************
*************************************************************************************************
*************************************************************************************************/








else if (mode==3)
{
	while(1)
	{

			Keypad_Inti();
		SetPort_Dir(DIO_PORTA, PORT_OUT);
		SetPort_Dir(DIO_PORTC, PORT_OUT);
		SetPort_Dir(DIO_PORTD, PORT_OUT);
		u8 minute_1=Set_minute();
		u8 second_1=Set_second();
		u8 second_2=59;
		LCD_SendString("please press ");
		LCD_GoTO(2, 0);
		LCD_SendString("button (4) ");
		_delay_ms(4000);
		LCD_Clear();
		LCD_SendString("to set timer ");
		LCD_GoTO(2, 0);
		LCD_SendString("press button-> 1 ");

		while(1)
		{
			for( u8 minute =0;(minute<=minute_1)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;minute++)
							{
								if (minute==minute_1)
								{
									second_2=second_1;
								}
							for( u8 second =0;(second<=second_2)&&Get_PinVal(DIO_PORTB, DIO_PIN0)!=0;second++)
								{
										int n=20;
											while (n--)
											{
												SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_LOW);
												PORTA=seg(second%10);
												_delay_ms(50/4);
												SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_LOW);
												PORTA=seg(second/10);
												_delay_ms(50/4);
												SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_LOW);
												PORTA=seg(minute%10);
												_delay_ms(50/4);
												SetPin_Val(DIO_PORTD, DIO_PIN2, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN3, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN4, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN6, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN7, PIN_HIGH);
												SetPin_Val(DIO_PORTD, DIO_PIN5, PIN_LOW);
												PORTA=seg(minute/10);
												_delay_ms(50/4);


													}


										}

									}
			if (Get_PinVal(DIO_PORTB, DIO_PIN0)==0)
					{
						LCD_Clear();
						LCD_SendString("loading");
						LCD_GoTO(2, 0);
						LCD_SendString("press button(4");
						_delay_ms(4000);
						LCD_Clear();
						break;
					}

			LCD_Clear();
			LCD_SendString("press button(4)");
			LCD_GoTO(2, 0);
			_delay_ms(4000);
			break;



		}



	}




}





/************************************************************************************************
*************************************************************************************************
***************************************------(calculator)-----************************************
*************************************************************************************************
*************************************************************************************************
*************************************************************************************************/
else if(mode==4)
{
LCD_INTI();
Keypad_Inti();
u32 var1=0;
u32 var2=0;
u8 test=5;
u8 op;
s32 result=0;

		while(1)
		{
			u8 tmp= keypad_GetVal();
			if(tmp!=0)
			{
				if(tmp>='0'&&tmp<='9'&&test==5)
				{
					LCD_SendChar(tmp);
					var1=var1*10;
					var1=var1+(tmp-'0');
					tmp = 0;
				}
				else if((tmp=='+'||tmp=='*'||tmp=='-'||tmp=='/')&&test==5)
				{
					LCD_SendChar(tmp);
					switch(tmp)
					{
					case '+':op=0;break;
					case '-':op=1;break;
					case '*':op=2;break;
					case '/':op=3;break;
					}
					test=20;
					tmp = 0;
				}
				else if (tmp>='0'&&tmp<='9'&&test==20)
				{
					LCD_SendChar(tmp);
					var2=var2*10;
					var2=var2+(tmp-'0');
					tmp = 0;

				}
				else if(tmp=='=')
				{
					LCD_SendChar(tmp);
					switch(op)
					{
						case 0:result=var1+var2;break;
						case 1:result=var1-var2;break;
						case 3:if(var2==0)
						{
							result='a';
							break;
						}
							result=var1/var2;break;
							case 2:result=var1*var2;break;

					}
					if(result!='a')
					{
					Lcd_IntToChar(result);
					tmp = 0;
					}
					else
					{
					LCD_Clear();
					LCD_SendString("un known");

					}

				}
				else if (tmp=='n')
					{
						LCD_Clear();
						test=5;
						var1=0;
						var2=0;



				}
			}



		}


}



}
