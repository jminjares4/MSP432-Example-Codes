#include "msp.h"

void sendString(char *str);
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//enable UART pins
	P1->SEL0 |= BIT2 | BIT3;
	P1->SEL1 &= ~(BIT2 | BIT3);

	//enable uart
	EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST;
	EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;
	EUSCI_A0->BRW = 19; //baudrate width, SMLCK/16/BR -> 3M/16/9600 = 19.53125
	EUSCI_A0->MCTLW = (9 << EUSCI_A_MCTLW_BRF_OFS | EUSCI_A_MCTLW_OS16); //19.53125 - 19 -> .53125 = 8.5, round up 9
	EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST;

	while(1){
	    sendString("Jorge->You Rock!!!\r\n");
        __delay_cycles(1000000);

	}
}
void sendString(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG)); //wait until is ready to transmit
                EUSCI_A0->TXBUF = str[i];
    }
}
