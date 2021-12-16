#include "msp.h"

typedef enum {
    LED_CHASER_UP = 0,
    LED_CHASER_DOWN = 1,
    LED_SWEEPER_UP = 2,
    LED_SWEEPER_DOWN = 3,
    LED_TOGGLE = 4,
    LED_OFF = 5,
}lightshow_t;

void lightShow(lightshow_t myLight){
    int i;
    if(myLight == LED_TOGGLE){
       P4->OUT ^= 0xFF;
    }else if(myLight == LED_OFF){
        P4->OUT &= ~(0xFF);
    }else{
        for(i = 0; i < 8; i++){
             switch(myLight){
                 case LED_CHASER_UP:
                     P4->OUT = BIT0 << i;
                     break;
                 case LED_CHASER_DOWN:
                     P4->OUT = BIT7 >> i;
                     break;
                 case LED_SWEEPER_UP:
                     P4->OUT |= BIT0 << i;
                     break;
                 case LED_SWEEPER_DOWN:
                     P4->OUT |= BIT7 >> i;
                     break;
                 default:
                     break;
             }
           __delay_cycles(250000);
         }
    }
    __delay_cycles(250000);
}

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P4->DIR |= 0xFF; //0x0F = BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7
	P4->OUT &= ~(0xFF);
	P4->SEL0 &= ~(0xFF);
	P4->SEL1 &= ~(0xFF);

	while(1){
	    int i;
	    lightShow((lightshow_t)LED_CHASER_UP);
	    lightShow((lightshow_t)LED_CHASER_DOWN);
	    lightShow((lightshow_t)LED_SWEEPER_UP);
	    lightShow((lightshow_t)LED_SWEEPER_DOWN);
	    for(i =0; i < 2 * 3; i++){
	        lightShow((lightshow_t)LED_TOGGLE);
	    }
	    lightShow((lightshow_t)LED_CHASER_UP);
	    lightShow((lightshow_t)LED_SWEEPER_UP);
	    lightShow((lightshow_t)LED_CHASER_DOWN);
	    lightShow((lightshow_t)LED_SWEEPER_DOWN);
	    lightShow((lightshow_t)LED_OFF);
	}

}
