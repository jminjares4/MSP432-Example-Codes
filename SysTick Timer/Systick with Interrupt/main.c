/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Demostrate how to use SysTick to create periodic tasks and control the SysTick with
 * 		  interrupts.
 * @version 0.1
 * @date 2021-12-20
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
	// Output
	P2->DIR |= BIT2;	// set BIT2 as OUTPUT
	P2->OUT &= ~(BIT2); // set BIT2 as LOW
	// clear secondary functions
	P2->SEL0 &= ~(BIT2);
	P2->SEL1 &= ~(BIT2);

	// Inputs
	P4->DIR &= ~(BIT0 | BIT1); // set BIT0 and BIT1 as inputs
	P4->OUT &= ~(BIT0);		   // set BIT0 as Pull-down
	P4->OUT |= BIT1;		   // Pull up set up using port 4 bit 1
	P4->REN |= BIT0 | BIT1;	   // enable resistors
	// Bit clear sel0 and sel1 for port 4
	P4->SEL0 &= ~(BIT0 | BIT1);
	P4->SEL1 &= ~(BIT0 | BIT1);
	// Interrupt Configuration
	P4->IE |= BIT0 | BIT1;	   // enable BIT0 and BIT1
	P4->IES &= ~(BIT0);		   // set bit 0 IES as rising edge
	P4->IES |= BIT1;		   // set bit 1 IES as falling edge
	P4->IFG &= ~(BIT0 | BIT1); // set Interrupt flag as 0

	// SysTick Configuration
	//  CLKSRC|TICKINT|ENABLE
	SysTick->CTRL = 0x05;		//   1       0       1    ->  0x05, disable interrupt
	SysTick->VAL = 1 - 1;		//
	SysTick->LOAD = 300000 - 1; // 30000/3Mhz -> .1sec -> 100ms

	// Enable NVIC
	NVIC->ISER[1] = 1 << ((PORT4_IRQn)&31);

	// Enable global interrupts
	__enable_irq();

	// infinite loop for embedded system
	while (1);
}

void SysTick_Handler(void)
{
	// 100ms * 5 -> .5 seconds
	if (tic++ > 5)
	{					 // check if .5 seconds have passed
		P2->OUT ^= BIT2; // toggle led
		tic = 0;		 // reset counter
	}
}

void PORT4_IRQHandler(void)
{
	uint8_t result = P4->IFG; // store P4->IFG
	if (result & BIT0)
	{						   // check for BIT0
		SysTick->CTRL |= 0x02; // enable SysTick Interrupt
	}
	if (result & BIT1)
	{							  // check for BIT1
		SysTick->CTRL &= ~(0x02); // disable SysTick Interrupt
	}
	P4->IFG &= ~(result); // clear bits of interrupt flag
}
