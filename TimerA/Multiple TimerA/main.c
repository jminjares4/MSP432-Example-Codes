/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief  Simple example of how to use various TIMER_Ax timers to toggle led at different rates
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"

// global variables, different counter for each timer to avoid race conditions
uint8_t tic0 = 0;
uint8_t tic1 = 0;
uint8_t tic2 = 0;
uint8_t tic3 = 0;
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer
    // Output
    P4->DIR |= (BIT0 | BIT1 | BIT2 | BIT3);  // Set 0x0F as OUTPUTs
    P4->OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3); // Set 0x0F as LOW
    // clear secondary functions
    P4->SEL0 &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    P4->SEL1 &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    // TIMER_A0 Configuration
    TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_3; // SMCLK , UP-DOWN mode
    TIMER_A0->CCR[0] = 60000 - 1;                            // 3Mhz/ 60k - > 50 hz or 20ms
    TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE;                  // enable interrupt

    // TIMER_A1 Configuration
    TIMER_A1->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1; // SMCLK, UP mode
    TIMER_A1->CCR[0] = 60000 - 1;                            // 3Mhz/ 60k - > 50 hz or 20ms
    TIMER_A1->CCTL[0] = TIMER_A_CCTLN_CCIE;                  // enable interrupt

    // TIMER_A2 Configuration
    TIMER_A2->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1;
    TIMER_A2->CCR[0] = 60000 - 1;           // 3Mhz/ 60k - > 50 hz or 20ms
    TIMER_A2->CCTL[0] = TIMER_A_CCTLN_CCIE; // enable interrupt

    // TIMER_A3 Configuration
    TIMER_A3->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC_1;
    TIMER_A3->CCR[0] = 3000 - 1;            // 3Mhz/ 3k - > 1000 hz or 1ms
    TIMER_A3->CCTL[0] = TIMER_A_CCTLN_CCIE; // enable interrupt

    // enable NVIC for all TIMER_Ax
    NVIC->ISER[0] |= 1 << ((TA0_0_IRQn)&31);
    NVIC->ISER[0] |= 1 << ((TA1_0_IRQn)&31);
    NVIC->ISER[0] |= 1 << ((TA2_0_IRQn)&31);
    NVIC->ISER[0] |= 1 << ((TA3_0_IRQn)&31);

    // enable global interrupts
    __enable_irq();
    while (1) // empty loop
    {
    }
}
void TA0_0_IRQHandler(void)
{
    // 3Mhz/ 60k - > 50 hz or 20ms
    // 20ms * 50 -> 1000ms or 1 second
    // TIMER_A0 is set to UP-DOWN mode therefore it will be 2 seconds
    if (tic0++ >= 50) // check if 2 seconds has passed
    {
        P4->OUT ^= BIT0; // toggle led
        tic0 = 0;        // reset to 0
    }
    TIMER_A0->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG); // clear flag
}
void TA1_0_IRQHandler(void)
{
    // 3Mhz/ 60k - > 50 hz or 20ms
    // 20ms * 50 -> 1000ms or 1 second
    // TIMER_A0 is set to UP- mode therefore it will be 1 seconds
    if (tic1++ >= 50) // check if 1 second has passed
    {
        P4->OUT ^= BIT1; // toggle led
        tic1 = 0;        // reset to 0
    }
    TIMER_A1->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG); // clear flag
}
void TA2_0_IRQHandler(void)
{
    // 3Mhz/ 60k - > 50 hz or 20ms
    // 20ms * 25 -> 500ms or .5 second
    // TIMER_A0 is set to UP- mode therefore it will be 1 seconds
    if (tic2++ >= 25) // check if .5 seconds has passed
    {
        P4->OUT ^= BIT2; // toggle led
        tic2 = 0;        // reset to 0
    }
    TIMER_A2->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG); // clear flag
}
void TA3_0_IRQHandler(void)
{
    // 3Mhz/ 3k - > 1000 hz or 1ms
    // 1ms * 250 -> 250 ms or .25 second or 1/4 second
    // TIMER_A0 is set to UP-mode therefore it will be .25 seconds
    if (tic3++ >= 250) // check if .25 has passed
    {
        P4->OUT ^= BIT3; // toggle led
        tic3 = 0;        // reset to 0
    }
    TIMER_A3->CCTL[0] &= ~(TIMER_A_CCTLN_CCIFG); // clear flag
}
