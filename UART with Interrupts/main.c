/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This is a simple input code to demostrate the use of UART with interrupts.
 * @version 0.1
 * @date 2021-12-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "msp.h"

void sendString(char *str);
void sendChar(char s);
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1->SEL0 |= BIT2|BIT3;
	P1->SEL1 &= ~(BIT2|BIT3);
 //Enhanced Universal Serial Control Interface = EUSCI
	EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST; //Clear previous configuration of UART
	EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;
	EUSCI_A0->BRW = 19; //Baudrate width, SMClock/16/DR -> 3000000/16/9600 = 19.53125
	EUSCI_A0->MCTLW = (9 << EUSCI_A_MCTLW_BRF_OFS | EUSCI_A_MCTLW_OS16);
	EUSCI_A0->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST);
	//enable UART interrupt
	EUSCI_A0->IE |= EUSCI_A_IE_RXIE; // enable receiver interrupt
	EUSCI_A0->IFG &= ~(EUSCI_A_IE_RXIE); //clear interrupt flag
	NVIC->ISER[0] = 1 << (EUSCIA0_IRQn & 31);

	sendString("Enter r for red, g for green, b for blue!\r\n");

	P1->DIR |= BIT0;
	P1->OUT &= ~(BIT0);
	P1->SEL0 &= ~(BIT0);
	P1->SEL1 &= ~(BIT0);

	P2->DIR |= BIT0|BIT1|BIT2;
	P2->OUT &= ~(BIT0|BIT1|BIT2);
	P2->SEL0 &= ~(BIT0|BIT1|BIT2);
	P2->SEL1 &= ~(BIT0|BIT1|BIT2);

	__enable_irq(); //enable global interrupts
	while(1){

	}
}


void EUSCIA0_IRQHandler(void){

    if(EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG){ //recieve interrupt
        char c = EUSCI_A0->RXBUF; //store data into character buffer, and clear flag
        sendChar(c);
        sendString("\r\n");
        if(c == 'b'){
            //turn blue led
            P2->OUT = BIT2;
        }else if(c == 'g'){
            //turn green led
            P2->OUT = BIT1;
        }else if(c == 'r'){
            //turn red led
            P2->OUT = BIT0;
        }
        else{
            int i = 0;
            for( ; i < 6; i++){
                P1->OUT ^= BIT0;
                __delay_cycles(1000000);
            }
            P1->OUT &= ~(BIT0);
            //toggle error
        }
    }

}

void sendString(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG)); //wait until is ready to transmit
        EUSCI_A0->TXBUF = str[i];
    }
}

void sendChar(char s){
    while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG)); //wait until is ready to transmit
    EUSCI_A0->TXBUF = s;
}
