/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will demostrate how to use interrupts
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Output
	P1->DIR |= BIT0;	// set BIT0 as OUTPUT
	P1->OUT &= ~(BIT0); // set BIT0 as LOW
	// clear secondary functions
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);
	// Output
	P2->DIR |= BIT2;	// set BIT2 as OUTPUT
	P2->OUT &= ~(BIT2); // set BIT2 as LOW
	// clear secondary functions
	P2->SEL0 &= ~(BIT2);
	P2->SEL1 &= ~(BIT2);

	// pull down, normal button setup
	P4->DIR &= ~(BIT0 | BIT1); // set BIT0 and BIT1 as inputs
	P4->OUT &= ~(BIT0 | BIT1); // set BIT0 and BIT1 as LOW for pull-down configuration
	P4->REN |= BIT0 | BIT1;	   // enable resistors
	// clear secondary functions
	P4->SEL0 &= ~(BIT0 | BIT1);
	P4->SEL1 &= ~(BIT0 | BIT1);
	// Interrupt Configuration
	P4->IE |= BIT0 | BIT1;	   // enable BIT0 and BIT1 as interrupts
	P4->IES &= ~(BIT0 | BIT1); // set BIT0 and BIT1 as rising edge, 0->1 or pull-down
	P4->IFG &= ~(BIT0 | BIT1); // clear interrupt flag

	// enable NVIC for Port 4
	NVIC->ISER[1] = 1 << ((PORT4_IRQn)&31);

	// enables the global interrupts
	__enable_irq();

	while (1)
	{
		P1->OUT ^= BIT0; //toggle the BIT0
		__delay_cycles(500000); //delay to see the changes
	}
}

void PORT4_IRQHandler(void)
{
	if (P4->IFG & BIT0) //check if BIT0 was trigger
	{
		P2->OUT |= BIT2; //set BIT2 on
	}
	if (P4->IFG & BIT1) //check if BIT1 was trigger
	{
		P2->OUT &= ~(BIT2); //clear BIT2
	}
	P4->IFG &= ~(BIT0|BIT1); //clear interrupts flags
}
