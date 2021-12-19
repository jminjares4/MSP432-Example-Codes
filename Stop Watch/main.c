#include "msp.h"
#include "lcdLib.h"

typedef struct {
    uint16_t millisec;
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
}StopWatch_t;

// set intial values
StopWatch_t myWatch = {.millisec = 0, .sec = 0, .min = 0, .hour = 0};

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    lcdInit();
    lcdClear();
    //Pull down set up using Port 4 bit 0
    P5->DIR &= ~(0x07);
    P5->OUT &= ~(0x07);
    P5->REN |= 0x07;
    //Pull up set up using port 4 bit 1
    //Bit clear sel0 and sel1 for port 4
    P5->SEL0 &= ~(0x07);
    P5->SEL1 &= ~(0x07);
    //enable interrupts for port 4
    P5->IE |= 0x07;
    //set bit 0 IES as rising edge
    P5->IES &= ~(0x07);
    //set Interrupt flag as 0
    P5->IFG &= ~(0x07);
    //SysTick bit 0: Enable SysTick and bit 2: Clock Source --
    //BIT0|BIT2 = 0x05
    SysTick->CTRL = 0x05;
    SysTick->VAL = 1 - 1;
    SysTick->LOAD = 3000;

    //Enable NVIC
    NVIC->ISER[1] = 1 << ((PORT5_IRQn)&31);
    //Enable global interrupts
    __enable_irq();

    lcdSetText("Stopwatch      ",5,0);
    //infinite loop for embedded system
    while(1){
    //    10:10:05:0000
        char buffer[16];
        sprintf(buffer, "%2u:%2u:%2u:%2u",myWatch.hour,myWatch.min,myWatch.sec,myWatch.millisec);
        lcdSetText(buffer,1,1);
    }
}
//
void SysTick_Handler(void){
    if(myWatch.millisec++ >= 999){
        myWatch.millisec = 0;
        if(myWatch.sec++ >= 59){
            myWatch.sec = 0;
            if(myWatch.min++ >= 59){
                myWatch.min = 0;
                if(myWatch.hour++ >= 23){
                    myWatch.hour = 0;
                }
            }
        }
    }
}
void PORT5_IRQHandler(void){
    if(P5->IFG & BIT0){ //Start stop-watch
        SysTick->CTRL &= ~(0x02);
    }
    if(P5->IFG & BIT1){//Stop stop-watch
        SysTick->CTRL |= 0x02;
    }
    if(P5->IFG & BIT2){//Reset stop-watch
        myWatch.millisec = 0, myWatch.sec = 0, myWatch.min = 0,  myWatch.hour = 0;
        lcdClear();
        lcdSetText("Stopwatch      ",5,0);
    }
    P5->IFG &= ~(0x07);
}
