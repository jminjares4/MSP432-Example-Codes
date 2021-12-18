/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This is a simple input code to demostrate how to create pull-up or pull-down buttons.
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

	//output setup
	P1->DIR |= BIT0;
	P1->OUT &= ~(BIT0);
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);

	//pull-down setup
	P6->DIR &= ~(BIT0);
	P6->OUT &= ~(BIT0); // for pull down, OUT register must be cleared 
	P6->SEL0 &= ~(BIT0);
	P6->SEL1 &= ~(BIT0);
	P6->REN |= BIT0; //enable resistor

	//pull-up setup
	P4->DIR &= ~(BIT0);
	P4->OUT |= BIT0; // for pull up, OUT register must be set as HIGH!
	P4->SEL0 &= ~(BIT0);
	P4->SEL1 &= ~(BIT0);
	P4->REN |= BIT0; //enable resistor

	//infinite loop
	while(1){ 
		if((P4->IN & BIT0) == 0x00){ // 1 -> 0
			P1->OUT = BIT0;	
		}else if((P6->IN & BIT0) == BIT0){ // 0 - > 1
			P1->OUT &= ~(BIT0);
		}else{
			__delay_cycles(10000); //small delay 
		}
		//debounce the button
		__delay_cycles(1000000);
	}
}