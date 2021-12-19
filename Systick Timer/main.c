#include "msp.h"

uint8_t tic = 0;

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1->DIR |= BIT0;
	P1->OUT &= ~(BIT0);
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);

	P2->DIR |= BIT2;
	P2->OUT &= ~(BIT2);
	P2->SEL0 &= ~(BIT2);
	P2->SEL1 &= ~(BIT2);

	SysTick->CTRL = 0x07; //start timer
	SysTick->VAL = 1 - 1;
	SysTick->LOAD = 300000; //100ms

	__enable_irq();
	while(1){
	    P2->OUT ^= BIT2;
	    __delay_cycles(5000000);
	}
}

void SysTick_Handler(void){
    if(tic++ > 5*10){ //toggle every 5 seconds
        P1->OUT ^= BIT0;
        tic = 0;
    }
}
