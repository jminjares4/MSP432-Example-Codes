#include "msp.h"


/**
 * main.c
 */
uint8_t tic0 = 0;
uint8_t tic1 = 0;
uint8_t tic2 = 0;
uint8_t tic3 = 0;
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P4->DIR |= (BIT0|BIT1|BIT2|BIT3);
	P4->OUT &= ~(BIT0|BIT1|BIT2|BIT3);
	P4->SEL0 &= ~(BIT0|BIT1|BIT2|BIT3);
	P4->SEL1 &= ~(BIT0|BIT1|BIT2|BIT3);


	//TIMER 0
	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_3; // UP and DOWN
	TIMER_A0->CCR[0] = 60000 - 1; //tic0 == 50
	TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE;

	//TIMER 1
    TIMER_A1->CTL = TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1;
    TIMER_A1->CCR[0] = 60000 - 1 ; //tic1 == 50
    TIMER_A1->CCTL[0] = TIMER_A_CCTLN_CCIE;

    //TIMER 2
    TIMER_A2->CTL = TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1;
    TIMER_A2->CCR[0] = 60000 - 1; // tic2 == 25, .5 seconds
    TIMER_A2->CCTL[0] = TIMER_A_CCTLN_CCIE;

    //TIMER 3
    TIMER_A3->CTL = TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1;
    TIMER_A3->CCR[0] = 3000 - 1; //3M/3000 - > 1ms or 1000 tics
    TIMER_A3->CCTL[0] = TIMER_A_CCTLN_CCIE;

    NVIC->ISER[0] |= 1 << ((TA0_0_IRQn) & 31);
    NVIC->ISER[0] |= 1 << ((TA1_0_IRQn) & 31);
    NVIC->ISER[0] |= 1 << ((TA2_0_IRQn) & 31);
    NVIC->ISER[0] |= 1 << ((TA3_0_IRQn) & 31);
    __enable_irq();
    while(1){}
}
void TA0_0_IRQHandler(void){
    if(tic0++ >=50){ //2 sec
        P4->OUT ^= BIT0;
        tic0 = 0;
    }
    TIMER_A0->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG);
}
void TA1_0_IRQHandler(void){
    if(tic1++ >=50){// 1 sec
            P4->OUT ^= BIT1;
            tic1 = 0;
        }
    TIMER_A1->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG);
}
void TA2_0_IRQHandler(void){
    if(tic2++ >=25){ //0.5 sec
            P4->OUT ^= BIT2;
            tic2 = 0;
        }
        TIMER_A2->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG);
}
void TA3_0_IRQHandler(void){
    if(tic3++ >= 250){//0.25 sec
            P4->OUT ^= BIT3;
            tic3 = 0;
        }
    TIMER_A3->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG);
}
