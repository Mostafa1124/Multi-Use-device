/*
 * prog.c
 *
 *  Created on: Sep 14, 2023
 *      Author: 12 VOLT
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/Bit_Math.h"
#include "../LIB/Types.h"
#include "../MCAL/DIO/Intr.h"
#include "../HAL/LCD/Intr.h"
#include "../HAL/KEYBAD/Intr.h"
u8 Set_hour(void)
{u8 hour_1=0;
	LCD_SendString("hour....");
		LCD_GoTO(2, 14);
		while(1)
		{
			u8 tmp =keypad_GetVal();
				if(tmp!=0)
				{
					if(tmp>='0'&&tmp<='9')
					{
						LCD_SendChar(tmp);
						hour_1=hour_1*10;
						hour_1=hour_1+(tmp-'0');
						tmp=0;
						if(hour_1>12)
						{
							LCD_Clear();
							LCD_SendString("wrong");
							_delay_ms(1000);
							LCD_Clear();
							LCD_SendString("hour....");
							LCD_GoTO(2, 14);
							tmp=0;
							hour_1=0;
						}


					}
					else if(tmp=='='&&hour_1!=0)
					{
						LCD_Clear();
						break;

					}
					else
					{
						LCD_Clear();
						LCD_SendString("wrong");
						_delay_ms(1000);
						LCD_Clear();
						LCD_SendString("hour....");
						LCD_GoTO(2, 14);
						tmp=0;
						hour_1=0;

					}
				}
		}

	return hour_1;

}

u8 Set_minute(void)
{
	u8 minute_1=0;

	LCD_SendString("minute....");
	LCD_GoTO(2, 14);
	while(1)
		{
			u8 tmp =keypad_GetVal();
				if(tmp!=0)
				{
					if(tmp>='0'&&tmp<='9')
					{
						LCD_SendChar(tmp);
						minute_1=minute_1*10;
						minute_1=minute_1+(tmp-'0');
						tmp=0;
						if(minute_1>59)
						{
							LCD_Clear();
							LCD_SendString("wrong");
							_delay_ms(1000);
							LCD_Clear();
							LCD_SendString("minute....");
							LCD_GoTO(2, 14);
							tmp=0;
							minute_1=0;
						}


					}
					else if(tmp=='=')
					{
						LCD_Clear();
						break;

					}
					else
					{
						LCD_Clear();
						LCD_SendString("wrong");
						_delay_ms(1000);
						LCD_Clear();
						LCD_SendString("minute....");
						LCD_GoTO(2, 14);
						tmp=0;
						minute_1=0;

					}
				}
		}
	return minute_1;

}
u8 Set_second(void)
{
	u8 second_1=0;
	LCD_SendString("second....");
		LCD_GoTO(2, 14);
		while(1)
				{
					u8 tmp =keypad_GetVal();
						if(tmp!=0)
						{
							if(tmp>='0'&&tmp<='9')
							{
								LCD_SendChar(tmp);
								second_1=second_1*10;
								second_1=second_1+(tmp-'0');
								tmp=0;
								if(second_1>59)
								{
									LCD_Clear();
									LCD_SendString("wrong");
									_delay_ms(1000);
									LCD_Clear();
									LCD_SendString("second....");
									LCD_GoTO(2, 14);
									tmp=0;
									second_1=0;
								}


							}
							else if(tmp=='=')
							{
								LCD_Clear();
								break;

							}
							else
							{
								LCD_Clear();
								LCD_SendString("wrong");
								_delay_ms(1000);
								LCD_Clear();
								LCD_SendString("second....");
								LCD_GoTO(2, 14);
								tmp=0;
								second_1=0;

							}
						}
				}
		return second_1;


}

