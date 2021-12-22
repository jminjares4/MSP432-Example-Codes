/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Simple example of how to use pulse width modulation with the MSP432
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Output
	P2->DIR |= BIT4;	 // set BIT4 as OUTPUT
	P2->OUT |= BIT4;	 // set BIT4 as HIGH!! we want it on
	P2->SEL0 |= BIT4;	 // enable select 0 for PWM
	P2->SEL1 &= ~(BIT4); // disable select 1

	// TIMER_A0 configuration
	TIMER_A0->CTL |= TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1; // smclk, up-mode
	TIMER_A0->CCR[0] = 6000 - 1;							  //  500hz period
	// TA0.1 -> P2.4
	TIMER_A0->CCR[1] = 300 - 1;					// set 5% duty cycle
	TIMER_A0->CCTL[1] = TIMER_A_CCTLN_OUTMOD_7; // enable pwm

	while (1)
	{
		__delay_cycles(1000000);	 // small delay
		TIMER_A0->CCR[1] += 300 - 1; // increase pwm output by 5%
		if (TIMER_A0->CCR[1] > 6000) // check if we exceed our threshold
		{						  
			TIMER_A0->CCR[1] = 0; // reset register
		}
	}
}
