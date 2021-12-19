#include "msp.h"


/**
 * main.c
 */
#define OFF 0x00
#define RED 0x01
#define GREEN 0x02
#define YELLOW 0x03
#define BLUE 0x04
#define PURPLE 0x05
#define TURQUOISE 0x06
#define WHITE 0x07


int index = 1;

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P2->DIR |= 0x07;//Bit set: Port 2: Bit:0,1,2
	P2->OUT &= ~(0x07);//Bit clear: Port 2: Bit 0,1,2
	P2->SEL0 &= ~(0x07);//Bit clear Port 2, SEL0
	P2->SEL1 &= ~(0x07);//Bit clear Port 2, SEL1

	//Pull-up Set up
	P4->DIR &= ~(0x07);//Bit Clear: Port 4: Bit 0,1,2
	P4->OUT |= 0x07;//Bit set: Port 4: Bit 0,1,2
	P4->REN |= 0x07;//Active internal Resistors for Port 4: Bit: 0,1,2
	P4->SEL0 &= ~(0x07);//Bit clear Port 4, SEL0
	P4->SEL1 &= ~(0x07);//Bit clear Port 4, SEL1

	P4->IE  |= (0x07); //interrupt enable bits
	P4->IES |= 0x07; //pull-up
	P4->IFG &= ~(0x07); //clear the flags?

	NVIC->ISER[1] = 1<< ((PORT4_IRQn)&31);

	__enable_irq();

	//Global array
	int colors[] = {OFF, RED, GREEN, YELLOW, BLUE, PURPLE, TURQUOISE, WHITE};


	while(1){
	    P2->OUT = colors[index];
	    __delay_cycles(100000);
	}
}
void PORT4_IRQHandler(void){
    if(P4->IFG & BIT0){
        index = 0;
        P1->OUT &= ~(BIT0);
    }
    if(P4->IFG & BIT1)
        if(index-- <= 1) index = 1;
    if(P4->IFG & BIT2)
        if(index++ >= 7) index = 7;

    P4->IFG &= ~(0x07);
}
