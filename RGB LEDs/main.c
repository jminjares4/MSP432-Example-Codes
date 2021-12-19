/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This code toggles use all the possible comnbinations of hte `on-board LEDs` to generate various colors.
 * @version 0.1
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

//Combination of MACROs for the onboard leds
#define OFF 0x00
#define RED 0x01
#define GREEN 0x02
#define YELLOW 0x03
#define BLUE 0x04
#define PURPLE 0x05
#define TURQUOISE 0x06
#define WHITE 0x07

//Global array
int colors[] = {OFF, RED, GREEN, YELLOW, BLUE, PURPLE, TURQUOISE, WHITE};

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

    //Set all onboard LEDs as outputs
    P2->DIR |= BIT0 | BIT1 | BIT2; // all outputs
    //Clear all onbaard LEDs 
    P2->OUT &= ~(BIT0 | BIT1 | BIT2);
    //Clear all secondary funcitons pins
    P2->SEL0 &= ~(BIT0 | BIT1 | BIT2);
    P2->SEL1 &= ~(BIT0 | BIT1 | BIT2);

    while (1) //all embedded system must have an infinite loop
    {
        int i; //create an variable name i 
        //iterate over the length of the colors array
        for (i = 0; i < sizeof(colors) / sizeof(int); i++)
        {
            P2->OUT = colors[i]; //update OUTPUT with the array index 
            __delay_cycles(500000); //small delay to be able to visualize the changes 
        }
        __delay_cycles(500000); //small delay
    }
}
