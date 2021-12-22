#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P2->DIR |= BIT4;
	P2->OUT |= BIT4; //set bit high
	P2->SEL0 |= BIT4;
	P2->SEL1 &= ~(BIT4);

	TIMER_A0->CTL |= TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1; // smclk, up-mode
	TIMER_A0->CCR[0] = 6000 - 1; //  500hz period
	TIMER_A0->CCR[1] = 300 - 1; // 5% duty cycle
	TIMER_A0->CCTL[1] = TIMER_A_CCTLN_OUTMOD_7; //enable pwm

	while(1){
	    __delay_cycles(1000000);
	    TIMER_A0->CCR[1] += 300 - 1;
	    if(TIMER_A0->CCR[1] > 6000){
	        TIMER_A0->CCR[1] = 0;
	    }
	}

}
