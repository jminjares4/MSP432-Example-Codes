/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Simple example of how to change the state of TIMER_A with interrupts
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "msp.h"

// global variable
uint8_t tic = 0;
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer
	// Enable on-board LED
	P2->DIR |= BIT2;	 // Bit Set: Port 2: BIT2
	P2->OUT &= ~(BIT2);	 // Bit Clear: Port 2: BIT2
	P2->REN |= BIT2;	 // Activate Internal Resistor for Port 2: BIT2
	P2->SEL0 &= ~(BIT2); // Bit Clear SEL0
	P2->SEL1 &= ~(BIT2); // Bit Clear SEL1

	// Declare Port 4 as interrupts using pull-down set-up
	P4->DIR &= ~(BIT0 | BIT1);	// Bit Set Port 4: BIT0|BIT1
	P4->REN |= (BIT0 | BIT1);	// Activated Internal Resistor for Port 4: BIT0|BIT1
	P4->OUT &= ~(BIT0 | BIT1);	// Bit Clear: Port 4: BIT0|BIT1
	P4->SEL0 &= ~(BIT0 | BIT1); // Bit Clear SEL0
	P4->SEL1 &= ~(BIT0 | BIT1); // BIT Clear SEL1
	P4->IE |= (BIT0 | BIT1);	// Enable Interrupts for Port 4: BIT0|BIT1
	P4->IES &= ~(BIT0 | BIT1);	// Bit Clear for pull-down set-up
	P4->IFG &= ~(BIT0 | BIT1);	// Enable flag for interrupts
	// Activate Timer A Tassel = SMClock MC = halted
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_0; // Modes which we use
	TIMER_A0->CCR[0] = 60000 - 1;							 // tics == 50, Compare and control Frequency
	TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE;					 // Compare and control enable
	// enable NVIC for Port 4 and TimerA
	NVIC->ISER[0] |= 1 << ((TA0_0_IRQn)&31);
	NVIC->ISER[1] |= 1 << ((PORT4_IRQn)&31);
	// Enable global Interrupts
	__enable_irq();
	// empty loop
	while (1);
}
void TA0_0_IRQHandler(void)
{
	// Toggle LED every second
	if (tic++ > 50)
	{
		P2->OUT ^= BIT2;
	}
	// Clear TIMER_A Interrupt Flag
	TIMER_A0->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG);
}
void PORT4_IRQHandler(void)
{
	uint8_t result = P4->IFG;
	// If BIT0 is activated,MC = halt the timer
	if (result & BIT0)
	{
		TIMER_A0->CTL &= ~(TIMER_A_CTL_MC_2);
	}
	// IF BIT1 is activated, MC = start timer
	if (result & BIT1)
	{
		TIMER_A0->CTL |= TIMER_A_CTL_MC_2;
	}
	// Bit Clear interrupt flag
	P4->IFG &= ~(result);
}
