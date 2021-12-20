/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This program will demostrate how to use external GPIOs as interrupts in a pull-up configuration
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

// MACROs for different states of onboard LEDs 
#define OFF 0x00
#define RED 0x01
#define GREEN 0x02
#define YELLOW 0x03
#define BLUE 0x04
#define PURPLE 0x05
#define TURQUOISE 0x06
#define WHITE 0x07

//global variable 
int index = 1;
//Global array
int colors[] = {OFF, RED, GREEN, YELLOW, BLUE, PURPLE, TURQUOISE, WHITE};

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Outputs
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
	//Interrupt Configuration
	P4->IE  |= (0x07); //interrupt enable bits
	P4->IES |= 0x07; //pull-up
	P4->IFG &= ~(0x07); //clear the flags?

	//enable NVIC for Port 4
	NVIC->ISER[1] = 1<< ((PORT4_IRQn)&31);

	//enable global interrupts
	__enable_irq();

	while(1){
	    P2->OUT = colors[index]; //output the current index 
	    __delay_cycles(100000); //small delay
	}
}
void PORT4_IRQHandler(void){
	uint8_t result = P4->IFG; //store P4->IFG
    if(result & BIT0){ //check for bit 0
        index = 0; //set index for OFF
    }
    if(result & BIT1) //check for bit 1
        if(index-- <= 1) index = 1; //check boundary
    if(result & BIT2) //check for bit 2
        if(index++ >= 7) index = 7; // check boundary
	//clear all the bits in the flag
    P4->IFG &= ~(result);
}
