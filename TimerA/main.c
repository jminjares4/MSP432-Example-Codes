/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Simple demostration how to use TIMER_A to create periodic tasks
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "msp.h"

//global variable 
uint8_t tic = 0; //count total ticks

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Output
	P2->DIR |= BIT2; // set BIT2 as OUTPUT
	P2->OUT &= ~(BIT2); // set BIT2 as LOW
	//clear secondary functions
	P2->SEL0 &=~(BIT2); 
	P2->SEL1 &= ~(BIT2);

	//TIMER_A0 Configurations
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1; // SMCLK, UP-mode
	TIMER_A0->CCR[0] = 60000 - 1;// period, N-1 3Mhz/60k - > 50 tics
	TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; //enable interrupt

	//enable NVIC for TA0_0
	NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);

	//enable global interrupts
	__enable_irq();

	while(1){ //empty loop
	}
}

void TA0_0_IRQHandler(void){
	// 3Mhz/60k -> 50 hz or 1/50 seconds = 0.02
	// 0.02 seconds * 50 -> 1 second
    if(tic++ >= 50){ //check if a second has passed 
        P2->OUT ^= BIT2; //toggle 
        tic = 0; // reset tic 
    }
    TIMER_A0->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG); //clear flag
}
