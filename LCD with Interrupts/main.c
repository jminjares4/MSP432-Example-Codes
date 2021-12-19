#include "msp.h"
#include "lcdLib.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	lcdInit();
	lcdClear();

	P2->DIR |= 0x07;
	P2->DIR &= ~(0xF0);
	P2->OUT &= ~(0xF7);
	P2->REN |= 0xF0;
	P2->SEL0 &= ~(0xF7);
	P2->SEL1 &= ~(0xF7);


	P2->IE |= 0xF0;
	P2->IES &= ~(0xF0);
	P2->IFG &= ~(0xF0);

	NVIC->ISER[1] = 1 << ((PORT2_IRQn) & 31);

	__enable_irq();

	lcdSetText("Led Controller",0,0);
	while(1){}
}
void PORT2_IRQHandler(void){
    if(P2->IFG & BIT4){
        lcdSetText("Led Red on   ",0,1);
        P2->OUT = BIT0;
    }
    if(P2->IFG & BIT5){
        lcdSetText("Led Green on ",0,1);
        P2->OUT = BIT1;
    }
    if(P2->IFG & BIT6){
        lcdSetText("Led Blue on  ",0,1);
        P2->OUT = BIT2;
    }
    if(P2->IFG & BIT7){
        lcdSetText("Led off       ",0,1);
        P2->OUT &= ~(0x07);
    }
    P2->IFG &= ~(0xF0);
}
