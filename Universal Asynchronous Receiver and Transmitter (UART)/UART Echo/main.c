/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Simple example of how to transmit characters or strings through UART
 * @version 0.1
 * @date 2021-12-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

void sendString(char *str);
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// enable UART pins
	P1->SEL0 |= BIT2 | BIT3;	// Enable SEL0 special functions for P1.2 and P1.3
	P1->SEL1 &= ~(BIT2 | BIT3); // Clear SEL1 special functions for P1.2 and P1.3

	// enable uart
	EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST;								 // Clear previous configuration of UART by setting reset
	EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;						 // Select SMClock, no parity, 1 stop bit, 8 bits, LSB
	EUSCI_A0->BRW = 19;													 // Baudrate width, SMClo/16/DR -> 3000000/16/9600 = 19.53125
	EUSCI_A0->MCTLW = (9 << EUSCI_A_MCTLW_BRF_OFS | EUSCI_A_MCTLW_OS16); // 19.53125 - 19 = 0.53125 * 16 = 8.5, round up to 9
	EUSCI_A0->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST);							 // clear reset bit

	while (1)
	{
		sendString("MSP432 ROCKS!!!\r\n");
		__delay_cycles(1000000);
	}
}
/**
 * @brief Send a string via UART2
 *
 * @param str String that will be sent through serial interface
 */
void sendString(char *str)
{
	int i; // create variable
	for (i = 0; str[i] != '\0'; i++)
	{ // iterate over the end of the string
		while (!(EUSCI_A2->IFG & EUSCI_A_IFG_TXIFG))
			;					  // wait until is ready to transmit
		EUSCI_A2->TXBUF = str[i]; // send character through buffer
	}
}