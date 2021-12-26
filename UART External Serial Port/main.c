#include "msp.h"

void sendString(char *str);
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P3->SEL0 |= BIT2|BIT3;
	P3->SEL1 &= ~(BIT2|BIT3);

	EUSCI_A2->CTLW0 = EUSCI_A_CTLW0_SWRST; //Clear previous configuration of UART
	EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK; // Select SMClock
	EUSCI_A2->BRW = 19; //Baudrate width, SMClo/16/DR -> 3000000/16/9600 = 19.53125
	EUSCI_A2->MCTLW = (9 << EUSCI_A_MCTLW_BRF_OFS | EUSCI_A_MCTLW_OS16); // 19.53125 - 19 = 0.53125 * 16 = 8.5, round up to 0
	EUSCI_A2->CTLW0 &= ~EUSCI_A_CTLW0_SWRST;

	while(1){
	    sendString("Using P3.2 to send data\r\n");
	    __delay_cycles(1000000);
	}
}
void sendString(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        while(!(EUSCI_A2->IFG & EUSCI_A_IFG_TXIFG)); //wait until is ready to transmit
                EUSCI_A2->TXBUF = str[i];
    }
}
