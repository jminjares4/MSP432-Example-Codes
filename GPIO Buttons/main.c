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
	P6->OUT &= ~(BIT0);
	P6->SEL0 &= ~(BIT0);
	P6->SEL1 &= ~(BIT0);
	P6->REN |= BIT0;

	//pull-up setup
	P4->DIR &= ~(BIT0);
	P4->OUT |= BIT0;
	P4->SEL0 &= ~(BIT0);
	P4->SEL1 &= ~(BIT0);
	P4->REN |= BIT0;
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