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
	//
	P2->DIR |= BIT0|BIT1|BIT2;
	P2->OUT &= ~(BIT0|BIT1|BIT2);
	P2->SEL0 &= ~(BIT0|BIT1|BIT2);
	P2->SEL1 &= ~(BIT0|BIT1|BIT2);


	//Pull-down setp up DIR REN OUT : 0 1 0
	P5->DIR &= ~(BIT0|BIT1|BIT2);
	P5->REN |= BIT0|BIT1|BIT2;
	P5->OUT &= ~(BIT0|BIT1|BIT2);
	P5->SEL0 &= ~(BIT0|BIT1|BIT2);
	P5->SEL1 &= ~(BIT0|BIT1|BIT2);
	//interrupt setup
	P5->IE |= BIT0|BIT1|BIT2;
	P5->IES &= ~(BIT0|BIT1|BIT2);
	P5->IFG &= ~(BIT0|BIT1|BIT2);

	NVIC->ISER[1] = 1 << ((PORT5_IRQn) & 31);

	__enable_irq();

	lcdSetText("Led Controller",0,0);
	while(1){
	    __delay_cycles(100000);
	}
}
void PORT5_IRQHandler(void){
    uint8_t result = P5->IFG;
    if(result & BIT0){
        lcdSetText("Led Red on   ",0,1);
        P2->OUT = BIT0;
    }
    if(result & BIT1){
        lcdSetText("Led Green on ",0,1);
        P2->OUT = BIT1;
    }
    if(result & BIT2){
        lcdSetText("Led off         ",0,1);
        P2->OUT &= ~(BIT0|BIT1|BIT2);
    }
    P5->IFG &= ~(result);
}
