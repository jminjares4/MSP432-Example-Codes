#include "msp.h"


/**
 * main.c
 */
#define BLUE 0x04
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	P1->DIR |= 0x01;
	P1->OUT &= ~(0x01);
	P1->SEL0 &= ~(0x01);
	P1->SEL1 &= ~(0x01);

	P2->DIR |= BLUE;
	P2->OUT &= ~(BLUE);
	P2->SEL0 &= ~(BLUE);
	P2->SEL1 &= ~(BLUE);

	//pull down, normal button setup
	P4->DIR &= ~(BIT0|BIT1);
	P4->OUT &= ~(BIT0|BIT1);
	P4->SEL0 &= ~(BIT0|BIT1);
	P4->SEL1 &= ~(BIT0|BIT1);
	P4->REN |= BIT0|BIT1;
	//intialize interrupt set up
	P4->IE |= BIT0|BIT1; //enable bit0 as interrupt
	P4->IES &= ~(BIT0|BIT1);
	P4->IFG &= ~(BIT0|BIT1); //clear interrupt flag

	NVIC->ISER[1] = 1 << ((PORT4_IRQn) & 31); // set NVIC

	__enable_irq(); //enables the global interrupts

    while(1){
        P1->OUT ^= 0x01;
        __delay_cycles(500000);
    }
}

// ISR!!!
void PORT4_IRQHandler(void){
    if(P4->IFG & BIT0){
        P2->OUT |= BLUE;
    }
    if(P4->IFG & BIT1){
        P2->OUT &= ~(BLUE);
    }
    P4->IFG &= ~(BIT0|BIT1);
}

