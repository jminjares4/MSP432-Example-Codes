/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Simple example of how to use multiple pulse width modulation output
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

	// Enable PWM pins
	// Outputs
	P2->DIR |= (BIT4 | BIT5 | BIT6 | BIT7);	  // enable 0xF0 as output
	P2->OUT |= (BIT4 | BIT5 | BIT6 | BIT7);	  // set 0xF0 as high
	P2->SEL0 |= (BIT4 | BIT5 | BIT6 | BIT7);  // enable select 0 for pwm configuration
	P2->SEL1 &= ~(BIT4 | BIT5 | BIT6 | BIT7); // disable select 1

	// TIMER_A0 configuration
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1; // smclk, up-mode
	TIMER_A0->CCR[0] = 60000 - 1;							 // 3Mhz/60k - > 50hz or 20 ms
	TIMER_A0->CCR[1] = 60000 - 1;							 // set @ 60k or 100% duty cycle
	TIMER_A0->CCR[2] = 45000 - 1;							 // set @ 45k or 75% duty cycle
	TIMER_A0->CCR[3] = 30000 - 1;							 // set @ 30k or 50% duty cylce
	TIMER_A0->CCR[4] = 15000 - 1;							 // set @ 15k or 25% duty cycle
	// enable PWM
	TIMER_A0->CCTL[1] = TIMER_A_CCTLN_OUTMOD_7;
	TIMER_A0->CCTL[2] = TIMER_A_CCTLN_OUTMOD_7;
	TIMER_A0->CCTL[3] = TIMER_A_CCTLN_OUTMOD_7;
	TIMER_A0->CCTL[4] = TIMER_A_CCTLN_OUTMOD_7;

	while (1)
		; // infinite loop
}
