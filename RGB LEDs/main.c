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
//
//typedef enum{
//OFF = 0x00,
//RED = 0x01,
//GREEN = 0x02,
//YELLOW = 0x03,
//BLUE = 0x04,
//PURPLE = 0x05,
//TURQUOISE = 0x06,
//WHITE = 0x07,
//}color_t;

int colors[] = {OFF,RED, GREEN, YELLOW, BLUE, PURPLE, TURQUOISE, WHITE};

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

//	color_t color = OFF;
	P2->DIR |= BIT0|BIT1|BIT2; //all outputs

	P2->OUT &= ~(BIT0|BIT1|BIT2);
    while(1){
        int i;
        for(i = 0; i < 8; i++){
            P2->OUT = colors[i];
            __delay_cycles(500000);
        }
//            color = (color_t)i;
//            P2->OUT = color;
//            __delay_cycles(1000000);
//        }
    }
}
