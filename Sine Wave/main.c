#include "msp.h"


uint16_t sineWave[] = {1,12000,24000,36000,48000,60000,48000,36000,24000,12000,1};

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P2->DIR |= BIT6;
	P2->OUT |= (BIT6);
	P2->SEL0 |= BIT6;
	P2->SEL1 &= ~(BIT6);


	TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2|TIMER_A_CTL_MC_1;
	TIMER_A0->CCR[0] = 60000-1;
	TIMER_A0->CCR[3] = 1-1;
	TIMER_A0->CCTL[3] = TIMER_A_CCTLN_OUTMOD_7;

	uint8_t i;
	while(1){
	   for(i = 0; i < sizeof(sineWave)/sizeof(uint16_t); i++){
	       __delay_cycles(100000);
	       TIMER_A0->CCR[3] = sineWave[i]-1;
	   }
	}
