/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will toggle various onboard leds with the intention of
 * 		  demostrating how to use OUTPUTs.
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "msp.h"

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Initialze P1.0 as output
	P1->DIR |= BIT0;
	// clear BIT0
	P1->OUT &= ~(BIT0);
	// Clear secondary functions
	P1->SEL1 &= ~(BIT0);
	P1->SEL2 &= ~(BIT0);

	while (1)
	{
		P1->OUT = BIT0; // set BIT0 as high!
		__delay_cycles(500000);
		P1->OUT &= ~(BIT0);		// set BIT0 to low!
		__delay_cycles(500000); // set BIT0 as low!
	}
}
