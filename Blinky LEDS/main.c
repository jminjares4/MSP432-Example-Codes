#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1->DIR |= BIT0;
	P1->OUT &= ~(BIT0);



	while(1){
	    P1->OUT = BIT0;
	    __delay_cycles(500000);
	    P1->OUT &= ~(BIT0);
	    __delay_cycles(500000);
	}
}
