/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Use the LCD to display which interrupt was trigger
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"
#include "lcdLib.h" //must include the library!

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Initialize the LCD
	lcdInit();
	lcdClear(); // clear previous store data

	// Output
	P2->DIR |= BIT0 | BIT1 | BIT2;	  // set 0x07 as OUTPUT
	P2->OUT &= ~(BIT0 | BIT1 | BIT2); // set 0x07 as LOW
	// clear the secondary functions
	P2->SEL0 &= ~(BIT0 | BIT1 | BIT2);
	P2->SEL1 &= ~(BIT0 | BIT1 | BIT2);

	// Input
	P5->DIR &= ~(BIT0 | BIT1 | BIT2); // clear 0x07 for INPUTs
	P5->REN |= BIT0 | BIT1 | BIT2;	  // enable resistors
	P5->OUT &= ~(BIT0 | BIT1 | BIT2); // set 0x07 as pull-down
	// clear the secondary functions
	P5->SEL0 &= ~(BIT0 | BIT1 | BIT2);
	P5->SEL1 &= ~(BIT0 | BIT1 | BIT2);
	// interrupt setup
	P5->IE |= BIT0 | BIT1 | BIT2;	  // enable 0x07 as interrupts
	P5->IES &= ~(BIT0 | BIT1 | BIT2); // set 0x07 as pull-down
	P5->IFG &= ~(BIT0 | BIT1 | BIT2); // clear flag for 0x07

	// enable NVIC for PORT 5
	NVIC->ISER[1] = 1 << ((PORT5_IRQn)&31);

	// enable global interrupts
	__enable_irq();

	while (1)
	{
		lcdSetText("Led Controller", 0, 0); // display in the first line
		__delay_cycles(100000);				// small delay
	}
}
void PORT5_IRQHandler(void)
{
	uint8_t result = P5->IFG; // store P5->IFG
	if (result & BIT0)
	{									   // check if BIT0
		lcdSetText("Led Red on   ", 0, 1); // update LCD
		P2->OUT = BIT0;					   // set BIT0 as HIGH
	}
	if (result & BIT1)
	{									   // check if BIT1
		lcdSetText("Led Green on ", 0, 1); // update LCD
		P2->OUT = BIT1;					   // set BIT1 as HIGH
	}
	if (result & BIT2)
	{										  // check if BIT1
		lcdSetText("Led off         ", 0, 1); // update LCD
		P2->OUT &= ~(BIT0 | BIT1 | BIT2);	  // clear all bits
	}
	P5->IFG &= ~(result); // clear flag
}
