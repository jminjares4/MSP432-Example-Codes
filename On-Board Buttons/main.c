#include "msp.h"

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
    //Port 1         //             IIII IIIO
	P1->DIR |= BIT0; //onboard led, 0000 0001
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);
	P1->OUT &= ~(BIT0);

	//PullDown Method
	P6->DIR &= ~(BIT0);
	P6->REN |= BIT0;
	P6->OUT &= ~(BIT0);

	//PullUp Method
	P4->DIR &= ~(BIT0);
	P4->REN |= BIT0;
	P4->OUT |= BIT0;


	while(1){
	    if((P4->IN & BIT0) == 0){
	        P1->OUT |= BIT0;
//	        __delay_cycles(1000000); //debounce the button
	    }


	    P1->OUT &= ~(BIT0);
//	    __delay_cycles(100000); //debounce the button
	}

}
