/*
 * Prog.c
 *
 *  Created on: Aug 26, 2023
 *      Author: 12 VOLT
 */
#include <avr/io.h>
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Types.h"
#include "Intr.h"
void SetPort_Dir(u8 port,u8 dir)
{
	switch (port)
	{
	case DIO_PORTA :DDRA=dir;  break;
	case DIO_PORTB :DDRB=dir;  break;
	case DIO_PORTC :DDRC=dir;  break;
	case DIO_PORTD :DDRD=dir;  break;

	}

}
void SetPort_Val(u8 port,u8 val)
{
	switch (port)
	{
	case DIO_PORTA :PORTA=val ;  break;
	case DIO_PORTB :PORTB=val ;  break;
	case DIO_PORTC :PORTC=val ;  break;
	case DIO_PORTD :PORTD=val ;  break;

	}

}
void SetPin_Dir(u8 port,u8 pin,u8 dir)
{
	switch (dir)
	{
	case PIN_OUT :
		switch(port)
		{
		case DIO_PORTA : Set_Bit(DDRA,pin);break;
		case DIO_PORTB : Set_Bit(DDRB,pin);break;
		case DIO_PORTC : Set_Bit(DDRC,pin);break;
		case DIO_PORTD : Set_Bit(DDRD,pin);break;
		}
		break;
	case PIN_IN :
		switch(port)
		{
		case DIO_PORTA : Clr_Bit(DDRA,pin);break;
		case DIO_PORTB : Clr_Bit(DDRB,pin);break;
		case DIO_PORTC : Clr_Bit(DDRC,pin);break;
		case DIO_PORTD : Clr_Bit(DDRD,pin);break;
		}
		break;
	}

}
void SetPin_Val(u8 port,u8 pin,u8 val)
{
	switch (val)
	{
	case PIN_HIGH :
		switch(port)
		{
		case DIO_PORTA : Set_Bit(PORTA,pin);break;
		case DIO_PORTB : Set_Bit(PORTB,pin);break;
		case DIO_PORTC : Set_Bit(PORTC,pin);break;
		case DIO_PORTD : Set_Bit(PORTD,pin);break;
		}
		break;
	case PIN_LOW :
		switch(port)
		{
		case DIO_PORTA : Clr_Bit(PORTA,pin);break;
		case DIO_PORTB : Clr_Bit(PORTB,pin);break;
		case DIO_PORTC : Clr_Bit(PORTC,pin);break;
		case DIO_PORTD : Clr_Bit(PORTD,pin);break;
		}
		break;
	}

}
u8 Get_PinVal(u8 port,u8 pin)
{
	switch(port)
	{
	case DIO_PORTA : return get_Bit(PINA,pin);
	case DIO_PORTB : return get_Bit(PINB,pin);
	case DIO_PORTC : return get_Bit(PINC,pin);
	case DIO_PORTD : return get_Bit(PIND,pin);
	}
}
void Pin_pullUp(u8 port,u8 pin)
{
	switch(port)
		{
		case DIO_PORTA : Set_Bit(PORTA,pin);break;
		case DIO_PORTB : Set_Bit(PORTB,pin);break;
		case DIO_PORTC : Set_Bit(PORTC,pin);break;
		case DIO_PORTD : Set_Bit(PORTD,pin);break;
		}
}
void Tog_Pin(u8 port , u8 pin)
{
	switch(port)
	{
	case DIO_PORTA : toggle_Bit(PORTA , pin);	break;
	case DIO_PORTB : toggle_Bit(PORTB , pin);	break;
	case DIO_PORTC : toggle_Bit(PORTC , pin);	break;
	case DIO_PORTD : toggle_Bit(PORTD , pin);	break;
	}
}


u8 seg(u8 n)
{
	switch(n)
		{
		case 0:return 0b00111111;
		case 1:return 0b00000110;
		case 2:return 0b01011011;
		case 3:return 0b01001111;
		case 4:return 0b01100110;
		case 5:return 0b01101101;
		case 6:return 0b01111101;
		case 7:return 0b00000111;
		case 8:return 0b01111111;
		case 9:return 0b01101111;
		}


}

