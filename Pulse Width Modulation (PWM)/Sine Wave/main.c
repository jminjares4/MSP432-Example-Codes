/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will demonstrate a Sine Wave using LEDs and PWM
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright Copyright (c) 2021
 */

#include "msp.h"

// Sine Wave array, the percentages for PWM
uint16_t sineWave[] = {1, 12000, 24000, 36000, 48000, 60000, 48000, 36000, 24000, 12000, 1};

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Enable Port 2: BIT 6 as output port
	P2->DIR |= BIT6;	 // Bit Set Port 2: BIT6
	P2->SEL0 |= BIT6;	 // Bit Set Port 2: BIT6 for special functions
	P2->SEL1 &= ~(BIT6); // Bit Clear Port 2: BIT6 SEL1

	// Enable PWM using Timer A
	// TASSEL_2 = SMCLOCK, MC_1 = UP-mode
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1;
	TIMER_A0->CCR[0] = 60000 - 1;				// Select period for SMClock
	TIMER_A0->CCR[3] = 1 - 1;					// Select Duty cycle for PWM Output
	TIMER_A0->CCTL[3] = TIMER_A_CCTLN_OUTMOD_7; // Reset/set for PWM

	while (1)
	{
		uint8_t i; // declare int i for for-loop
		for (i = 0; i < sizeof(sineWave) / sizeof(uint16_t); i++)
		{
			__delay_cycles(1000000);
			TIMER_A0->CCR[3] = sineWave[i] - 1; // using for-loop to switch the duty-cycle for PWM Output
		}
	}
}
