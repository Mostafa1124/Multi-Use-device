/*
 * prog.c
 *
 *  Created on: Sep 13, 2023
 *      Author: 12 VOLT
 */
#include <avr/io.h>
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Types.h"
#include "../../MCAL/DIO/Intr.h"

u32 ovf_numbers   = 0;
u32 initial_value = 0;

void Timer0_Inti(void)
{
	//normal mode
	Clr_Bit(TCCR0 , 3);
	Clr_Bit(TCCR0 , 6);
	//GIE
	Set_Bit(SREG , 7);
	//PIE
	Set_Bit(TIMSK , 0);

}


void Timer0_Start(void)
{
	//prescaller 1024
		Set_Bit(TCCR0 , 0);
		Clr_Bit(TCCR0 , 1);
		Set_Bit(TCCR0 , 2);
}
void Timer0_Stop(void)
{

		Clr_Bit(TCCR0 , 0);
		Clr_Bit(TCCR0 , 1);
		Set_Bit(TCCR0 , 2);

}
void TImer0_delay_ms(u32 desired_time)
{
	u32 tick_time = (1024 / 8) ;   // us
	u32 ticks_no  =  (desired_time *1000) / tick_time ; // 256

	// Calculate number of ovf interrupt
	ovf_numbers = ticks_no / 256 ;   //1
		// preloa
	initial_value = 256 - (ticks_no % 256);  // 256 -0
	TCNT0 = initial_value;
	ovf_numbers++; //2

}
