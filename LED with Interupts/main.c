#include "msp.h"


/**
 * main.c
 */
#define RED 0x01
#define GREEN 0x02
#define BLUE 0x04
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Set RGB LEDS
	P2->DIR |= (0x07); //Bit Set:Port 2: BIT0|BIT1|BIT2
	P2->OUT &= ~(0x07);//Bit clear Port 2
	P2->SEL0 &= ~(0x07);//Bit Clear SEL0
	P2->SEL1 &= ~(0x07);//Bit Clear SEl1

	//Set Interupts using pull down setup: 0->1
	P4->DIR &= ~(0x0F);//Bit set: Port 4: Bit0|BIT1|BIT2|BIT3
	P4->OUT &= ~(0x0F);//Bit clear port 4
	P4->REN |= 0x0F; //Activate internal resistor for port 4, bit: 0,1,2,3
	P4->SEL0 &= ~(0x0F);//Bit clear SEL0
	P4->SEL1 &= ~(0x0F);//bit clear SEL1

	P4->IE |= 0x0F; //Enable interrupts for bit 0,1,2,3
	P4->IES &= ~(0x0F);//Bit clear for pull-down
	P4->IFG &= ~(0x0F); //Enable flag for interrupts

	NVIC->ISER[1] = 1 << ((PORT4_IRQn) & 31);

	__enable_irq();
	while(1){}
}

void PORT4_IRQHandler(void){
    if(P4->IFG & BIT0){
        P2->OUT &= ~(0x0F);
    }
    if(P4->IFG & BIT1){
        P2->OUT |= RED;
    }
    if(P4->IFG & BIT2){
        P2->OUT |= GREEN;
    }
    if(P4->IFG & BIT3){
        P2->OUT |= BLUE;
    }
    P4->IFG &= ~(0x0F);
}

