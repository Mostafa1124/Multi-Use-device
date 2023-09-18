/*
 * Intr.h
 *
 *  Created on: Sep 13, 2023
 *      Author: 12 VOLT
 */

#ifndef MCAL_TIMER_INTR_H_
#define MCAL_TIMER_INTR_H_

void Timer0_Inti(void);
void Timer0_Start(void);
void Timer0_Stop(void);
void TImer0_delay_ms(u32 desired_time);

#endif /* MCAL_TIMER_INTR_H_ */
