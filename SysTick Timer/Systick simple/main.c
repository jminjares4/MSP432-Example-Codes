/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Demostrate how to use SysTick to create periodic tasks
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

// global variable
uint8_t tic = 0; // will control the total cpu clock cylces

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Output
	P1->DIR |= BIT0;	// set BIT0 as OUTPUT
	P1->OUT &= ~(BIT0); // clear BIT0 to LOW
	// clear secondary flags
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);

	// Output
	P2->DIR |= BIT2;	// set BIT2 as OUTPUT
	P2->OUT &= ~(BIT2); // clear BIT2 to LOW
	// clear secondary flags
	P2->SEL0 &= ~(BIT2);
	P2->SEL1 &= ~(BIT2);

	// SysTick Configuration
	// CLKSRC|TICKINT|ENABLE
	SysTick->CTRL = 0x07;	// 1       1       1    ->  0x07, start timer
	SysTick->VAL = 1 - 1;	// set 0 to the value
	SysTick->LOAD = 300000; // 300000/3MHz - > 0.1s -> 100ms

	// enable global interrupts
	__enable_irq();

	while (1)
	{
		P2->OUT ^= BIT2;
		__delay_cycles(5000000);
	}
}

void SysTick_Handler(void)
{
	// every tic is 100ms therefore, 50 * 100ms -> 5 secs
	if (tic++ > 5 * 10) // check if 5 sec have passed
	{
		P1->OUT ^= BIT0; // toggle led
		tic = 0;		 // clear tic
	}
}
