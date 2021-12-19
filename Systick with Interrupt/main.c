#include "msp.h"


/**
 * main.c
 */

//toggle every 3 seconds
uint8_t tic = 0;
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//Enable on-board LED
	P2->DIR |= BIT2;
	P2->OUT &= ~(BIT2);
	P2->SEL0 &= ~(BIT2);
	P2->SEL1 &= ~(BIT2);

	//Pull down set up using Port 4 bit 0
	P4->DIR &= ~(BIT0|BIT1);
	P4->OUT &= ~(BIT0);
	P4->REN |= BIT0|BIT1;
	//Pull up set up using port 4 bit 1
	P4->OUT |= BIT1;
	//Bit clear sel0 and sel1 for port 4
	P4->SEL0 &= ~(BIT0|BIT1);
	P4->SEL1 &= ~(BIT0|BIT1);
	//enable interrupts for port 4
	P4->IE |= BIT0|BIT1;
	//set bit 0 IES as rising edge
	P4->IES &= ~(BIT0);
	//set bit 1 IES as falling edge
	P4->IES |= BIT1;
	//set Interrupt flag as 0
	P4->IFG &= ~(BIT0|BIT1);
	//SysTick bit 0: Enable SysTick and bit 2: Clock Source --
	//BIT0|BIT2 = 0x05
	SysTick->CTRL = 0x05;
	SysTick->VAL = 1 - 1;
	SysTick->LOAD = 300000;

	//Enable NVIC
	NVIC->ISER[1] = 1 << ((PORT4_IRQn)&31);
	//Enable global interrupts
	__enable_irq();


	//infinite loop for embedded system
	while(1){}
}
//
void SysTick_Handler(void){
    if(tic++ > 5){
        P2->OUT ^= BIT2;
        tic = 0;
    }
}
void PORT4_IRQHandler(void){
    if(P4->IFG & BIT0){
        SysTick->CTRL |= 0x02;
    }
    if(P4->IFG & BIT1){
        SysTick->CTRL &= ~(0x02);
    }
    P4->IFG &= ~(BIT0|BIT1);
}
