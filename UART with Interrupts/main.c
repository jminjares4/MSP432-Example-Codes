/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Use UART interrupt to trigger different subroutine based on the recieved data
 * @version 0.1
 * @date 2021-12-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "msp.h"

/**
 * @brief Send a string via UART0
 *
 * @param str String that will be sent through serial interface
 */
void sendString(char *str);
/**
 * @brief Send a character via UART0
 *
 * @param s character that will be sent through serial interface
 */
void sendChar(char s);
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

    // Error LED
    P1->DIR |= BIT0;    // set BIT0 as OUTPUT
    P1->OUT &= ~(BIT0); // set BIT0 as LOW
    // clear secondary functions
    P1->SEL0 &= ~(BIT0);
    P1->SEL1 &= ~(BIT0);

    // RGB LEDs
    P2->DIR |= BIT0 | BIT1 | BIT2;    // set BIT0,1,2 as OUTPUTs
    P2->OUT &= ~(BIT0 | BIT1 | BIT2); // set BIT0,1,2 as LOW
    // clear secondary functions
    P2->SEL0 &= ~(BIT0 | BIT1 | BIT2);
    P2->SEL1 &= ~(BIT0 | BIT1 | BIT2);

    // Enable UART0 Pins
    // P1.2->RX
    // P1.3->TX
    P1->SEL0 |= BIT2 | BIT3;
    P1->SEL1 &= ~(BIT2 | BIT3);

    // UART0 Configuration
    // Enhanced Universal Serial Control Interface = EUSCI
    EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST;                               // Clear previous configuration of UART
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SSEL__SMCLK;                        // Select SMClock, no parity, 1 stop bit, 8 bits, LSB
    EUSCI_A0->BRW = 19;                                                  // Baudrate width, SMClock/16/DR -> 3000000/16/9600 = 19.53125
    EUSCI_A0->MCTLW = (9 << EUSCI_A_MCTLW_BRF_OFS | EUSCI_A_MCTLW_OS16); // // 19.53125 - 19 = 0.53125 * 16 = 8.5, round up to 9
    EUSCI_A0->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST);                           // clear reset bit
    // enable UART interrupt
    EUSCI_A0->IE |= EUSCI_A_IE_RXIE;     // enable receiver interrupt
    EUSCI_A0->IFG &= ~(EUSCI_A_IE_RXIE); // clear interrupt flag

    // enable NVIC for UART0
    NVIC->ISER[0] = 1 << (EUSCIA0_IRQn & 31);

    // enable global interrupts
    __enable_irq();

    sendString("Enter r for red, g for green, b for blue!\r\n"); // send message

    while (1)
    {
    }
}

void EUSCIA0_IRQHandler(void)
{
    if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG) // recieve interrupt
    {                             
        char c = EUSCI_A0->RXBUF; // store data into character buffer, and clear flag
        sendChar(c);              // display character through the SERIAL port
        sendString("\r\n");       // send carriage return and new line
        // check the recieved character
        if (c == 'b')
        {
            P2->OUT = BIT2; // turn blue led
        }
        else if (c == 'g')
        {
            P2->OUT = BIT1; // turn green led
        }
        else if (c == 'r')
        {
            P2->OUT = BIT0; // turn red led
        }
        else
        {
            int i = 0; // create iterator variable
            for (; i < 4; i++)
            {                            // toggle twice
                P1->OUT ^= BIT0;         // toggle the led
                __delay_cycles(1000000); // small delay
            }
            P1->OUT &= ~(BIT0); // clear the led
        }
    }
}

/**
 * @brief Send a string via UART0
 *
 * @param str String that will be sent through serial interface
 */
void sendString(char *str)
{
    int i;                           // create variable
    for (i = 0; str[i] != '\0'; i++) // iterate over the end of the string
    {
        while (!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG)); // wait until is ready to transmit
        EUSCI_A0->TXBUF = str[i]; // send character through buffer
    }
}
/**
 * @brief Send a character via UART0
 *
 * @param s Character that will be sent through serial interface
 */
void sendChar(char s)
{
    while (!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG)); // wait until is ready to transmit
    EUSCI_A0->TXBUF = s; // send character through buffer
}
