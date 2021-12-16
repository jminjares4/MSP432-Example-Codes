/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will demostrate how to use external GPIOs to create a lightshow.
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "msp.h"

/**
 * @brief Custom enumeration for LED lightshow selection.
 */
typedef enum {
    LED_CHASER_UP = 0,
    LED_CHASER_DOWN = 1,
    LED_SWEEPER_UP = 2,
    LED_SWEEPER_DOWN = 3,
    LED_TOGGLE = 4,
    LED_OFF = 5,
}lightshow_t;

/**
 * @brief lightShow() will iterate over all the BITs in P4 and display various led control.
 * 
 * @param myLight lightshow_t enum for led selection
 */
void lightShow(lightshow_t myLight){
    int i; //for the loop
    if(myLight == LED_TOGGLE){ //check if LED_TOGGLE
       P4->OUT ^= 0xFF; // toggle all LEDs 
    }else if(myLight == LED_OFF){ // check if LED_OFF
        P4->OUT &= ~(0xFF); //bit clear all LEDs 
    }else{
        for(i = 0; i < 8; i++){ //iterate over all the BITs or pins
             switch(myLight){ //check the input of myLight 
                 case LED_CHASER_UP: 
                     P4->OUT = BIT0 << i; // left bit shift 
                     break;
                 case LED_CHASER_DOWN:
                     P4->OUT = BIT7 >> i; // right bit shift 
                     break;
                 case LED_SWEEPER_UP:
                     P4->OUT |= BIT0 << i; // left bit shift with bit set
                     break;
                 case LED_SWEEPER_DOWN:
                     P4->OUT |= BIT7 >> i; // right bit shift with bit set 
                     break;
                 default:
                     break;
             }
           __delay_cycles(250000); // small delay to viusalize the changes 
         }
    }
    __delay_cycles(250000); //small delay
}

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
    // enable the bits that are going to be used 
	P4->DIR |= 0xFF;
    // clear all the pins 
	P4->OUT &= ~(0xFF);
    // clear all secondary function 
	P4->SEL0 &= ~(0xFF);
	P4->SEL1 &= ~(0xFF);

	while(1){ //loop
	    int i; //create a varaible i
        //call all the different led enumeration to generate a custom light show!
	    lightShow((lightshow_t)LED_CHASER_UP);
	    lightShow((lightshow_t)LED_CHASER_DOWN);
	    lightShow((lightshow_t)LED_SWEEPER_UP);
	    lightShow((lightshow_t)LED_SWEEPER_DOWN);
	    for(i =0; i < 2 * 3; i++){
	        lightShow((lightshow_t)LED_TOGGLE);  //toggle the LEDs 
            __delay_cycles(100000); //small delay
	    }
	    lightShow((lightshow_t)LED_CHASER_UP);
	    lightShow((lightshow_t)LED_SWEEPER_UP);
	    lightShow((lightshow_t)LED_CHASER_DOWN);
	    lightShow((lightshow_t)LED_SWEEPER_DOWN);
	    lightShow((lightshow_t)LED_OFF);
	}
}
