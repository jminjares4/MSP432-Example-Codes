#include "msp.h"
uint8_t tic = 0;
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer


	P2->DIR |= BIT2;
	P2->OUT &= ~(BIT2);
	P2->SEL0 &=~(BIT2);
	P2->SEL1 &= ~(BIT2);

	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1;// SMCLK, UP-mode
	TIMER_A0->CCR[0] = 60000 - 1;// period, N-1 3Mhz/60k - > 50 tics
	TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; //enable interrupt

	NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);

	__enable_irq();

	while(1){
	}
}

void TA0_0_IRQHandler(void){

    if(tic++ >= 50){
        P2->OUT ^= BIT2;
        tic = 0;
    }
    TIMER_A0->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG); //clear flag
}
