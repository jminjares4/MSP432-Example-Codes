/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will demonstrate how to set-up Port 2 as a PWM output to move a Servo Motor
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright Copyright (c) 2021
 *
 * Positions for the Servo Motor
 * (-90) = 1ms
 * (0) = 1.5ms
 * (90) = 2ms
 */
#include "msp.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer
	// Enable Port 2 Bit 4 as an output pin
	P2->DIR |= BIT4;	 // Bit set Port 2: Bit 4
	P2->OUT |= BIT4;	 // Bit set Port 2: Bit 4
	P2->SEL0 |= BIT4;	 // Bit set Port 2: Bit 4 to use Special Functions
	P2->SEL1 &= ~(BIT4); // Bit Clear SEL1
	// Enable PWM using TimerA
	// TASSEL_2 = SMCLOCK MC_1 = Up mode
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1;
	TIMER_A0->CCR[0] = 60000 - 1;				// Select period for the SMClock
	TIMER_A0->CCR[1] = 3000 - 1;				// Select Duty Cycle for the PWM Output
	TIMER_A0->CCTL[1] = TIMER_A_CCTLN_OUTMOD_7; // Reset/set for PWM

	// TIMER_A0->CCR[1] = 3000-1; set position for servo motor at -90 degrees
	// TIMER_A0->CCR[1] = 4500-1; set position for servo motor at 0 degrees
	// TIMER_A0->CCR[1] = 6000-1; set position for servo motor at 90 degrees
	while (1)
	{
		__delay_cycles(10000);
		TIMER_A0->CCR[1] += 1500 - 1; // add percentage to duty cycle in order to
		if (TIMER_A0->CCR[1] > 6000)
		{								 // check if the duty cycle is greater than the period
			TIMER_A0->CCR[1] = 3000 - 1; // if so, reset the duty cycle to position -90 degrees
		}
	}
}
