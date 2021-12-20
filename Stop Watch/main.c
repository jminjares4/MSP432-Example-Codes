/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Create a stop watch using SysTick, Interrupts and display the time with the LCD
 * @version 0.1
 * @date 2021-12-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "msp.h"
#include "lcdLib.h"

//Custom structure 
typedef struct {
    uint16_t millisec; //hold the milliseconds 
    uint8_t sec; //hold the seconds 
    uint8_t min; // holds the minutes 
    uint8_t hour; // holds the hours 
}StopWatch_t;

// set intial values
StopWatch_t myWatch = {.millisec = 0, .sec = 0, .min = 0, .hour = 0};

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    //Initialize the LCD 
    lcdInit();
    lcdClear();

    //Input 
    P5->DIR &= ~(BIT0|BIT1|BIT2); //set 0x07 as INPUTs 
    P5->OUT &= ~(BIT0|BIT1|BIT2); //set 0x07 as pull-down
    P5->REN |= BIT0|BIT1|BIT2; // enable resistors 
    //clear secondary functions
    P5->SEL0 &= ~(BIT0|BIT1|BIT2);
    P5->SEL1 &= ~(BIT0|BIT1|BIT2);
    //Interrupt Configuration
    P5->IE |= BIT0|BIT1|BIT2; //enable 0x07 as interrupts 
    P5->IES &= ~(BIT0|BIT1|BIT2); // enable 0x07 as rising edges 
    P5->IFG &= ~(BIT0|BIT1|BIT2); // clear all bits from the flag

    //SysTick Configuration
    SysTick->CTRL = 0x05; // CLKSRC | ENABLE, interrupt disable 
    SysTick->VAL = 1 - 1; // clear value register 
    SysTick->LOAD = 3000 - 1; // set at 1ms 

    //Enable NVIC
    NVIC->ISER[1] = 1 << ((PORT5_IRQn)&31);
    //Enable global interrupts
    __enable_irq();

    lcdSetText("Stopwatch      ",5,0);
    //infinite loop for embedded system
    while(1){
        //set custom text
        char buffer[16];
        sprintf(buffer, "%2u:%2u:%2u:%2u",myWatch.hour,myWatch.min,myWatch.sec,myWatch.millisec);
        lcdSetText(buffer,1,1);
    }
}

void SysTick_Handler(void){
    if(myWatch.millisec++ >= 999){ //check after 1 second 
        myWatch.millisec = 0; //clear millisecond
        if(myWatch.sec++ >= 59){ //check after a minute 
            myWatch.sec = 0; // clear seconds 
            if(myWatch.min++ >= 59){ //check after an hour 
                myWatch.min = 0; // clear minutes 
                if(myWatch.hour++ >= 23){ //check after 24
                    myWatch.hour = 0; //clear hours 
                }
            }
        }
    }
}
void PORT5_IRQHandler(void){
    uint8_t result = P5->IFG; //store the P5->IFG 
    if(result & BIT0){ //Start stop-watch
        SysTick->CTRL &= ~(0x02); //disable interrupt, stop timer
    }
    if(result & BIT1){//Stop stop-watch
        SysTick->CTRL |= 0x02; //enable interrupt, start timer
    }
    if(result & BIT2){//Reset stop-watch
        //clear data structure
        myWatch.millisec = 0, myWatch.sec = 0, myWatch.min = 0,  myWatch.hour = 0;
        lcdClear();
        lcdSetText("Stopwatch      ",5,0);
    }
    P5->IFG &= ~(result); //clear flag
}
