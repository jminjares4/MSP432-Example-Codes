/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will demostrate how to use external GPIOs as interrupts
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

// MACROs for all onboard leds
#define RED   0x01   // BIT0
#define GREEN 0x02 // BIT1
#define BLUE  0x04  // BIT2
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Set RGB LEDS
	P2->DIR |= (0x07);	 // Bit Set:Port 2: BIT0|BIT1|BIT2
	P2->OUT &= ~(0x07);	 // Bit clear Port 2
	P2->SEL0 &= ~(0x07); // Bit Clear SEL0
	P2->SEL1 &= ~(0x07); // Bit Clear SEl1

	// Set Interupts using pull down setup: 0->1
	P4->DIR &= ~(0x0F);	 // Bit set: Port 4: Bit0|BIT1|BIT2|BIT3
	P4->OUT &= ~(0x0F);	 // Bit clear port 4
	P4->REN |= 0x0F;	 // Activate internal resistor for port 4, bit: 0,1,2,3
	P4->SEL0 &= ~(0x0F); // Bit clear SEL0
	P4->SEL1 &= ~(0x0F); // bit clear SEL1

	P4->IE |= 0x0F;		// Enable interrupts for bit 0,1,2,3
	P4->IES &= ~(0x0F); // Bit clear for pull-down
	P4->IFG &= ~(0x0F); // Enable flag for interrupts

	//enable NVIC for port 4
	NVIC->ISER[1] = 1 << ((PORT4_IRQn)&31); //see NVIC table, all PORTx go in ISER[1]

	__enable_irq(); // enable global interrupts
	while (1)//empty loop as every will be control by the Port Interrupt
	{
	}
}

void PORT4_IRQHandler(void)
{
	if (P4->IFG & BIT0)
	{						// check bit 0
		P2->OUT &= ~(0x0F); // clear all bits
	}
	if (P4->IFG & BIT1)
	{					// check bit 1
		P2->OUT |= RED; // set RED led
	}
	if (P4->IFG & BIT2)
	{					  // check bit 2
		P2->OUT |= GREEN; // set GREEN led
	}
	if (P4->IFG & BIT3)
	{					 // check bit 3
		P2->OUT |= BLUE; // set BLUE led
	}
	P4->IFG &= ~(0x0F); // clear all bits on the interrupt flag
}
