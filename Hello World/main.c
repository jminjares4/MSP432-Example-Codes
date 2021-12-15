/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4) 
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This is a simple hello world! Typically 'Hello World' is use when starting any
 * 		  programming language. However, in embedded we turn an LED!
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "msp.h"
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Initialze P1.0 as output
	P1->DIR |= BIT0; 
	//clear BIT0
	P1->OUT &= ~(BIT0); 
	//Clear secondary functions
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);

	while(1){ //infinite loop, to avoid WDT
		P1->OUT = BIT0; //set BIT0 as high!
		__delay_cycles(1000000); //add a delay in MCU
	}
}
