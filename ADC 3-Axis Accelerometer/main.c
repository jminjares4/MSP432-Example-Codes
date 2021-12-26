/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief This is a simple input code to demostrate how to create pull-up or pull-down buttons.
 * @version 0.1
 * @date 2021-12-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"
#include "lcdLib.h"
#include <stdlib.h>

#define DATA_SIZE 5 // Create MACRO for array
uint8_t index = 0;
uint16_t data[DATA_SIZE]; // Create array for data gathered from ADC

typedef struct
{
    uint32_t x_axis[DATA_SIZE]; // array for data gather from ADC corresponding for x-axis
    uint32_t y_axis[DATA_SIZE]; // array for data gather from ADC corresponding for x-axis
    uint32_t z_axis[DATA_SIZE]; // array for data gather from ADC corresponding for x-axis
} ADXL335_t;                    // Structure for accelometer's axies

ADXL335_t sensor;

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer
    // Configure P5.0 and P5.1 as ADC input Channels
    P5->SEL0 |= (BIT0 | BIT1 | BIT2);
    P5->SEL1 |= (BIT0 | BIT1 | BIT2);
    // x = bit 0, y = bit 1, z = bit 2
    lcdInit();  // Initiate LCD screen
    lcdClear(); // Clear previous LCD Configuration

    lcdSetText("ADC 3-Axis CH", 0, 0); // Set text for LCD

    // SHP = using signal from sampling timer,
    // CONSEQ = enable conversion of sequence channels
    // ON = turn ADC on
    ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_CONSEQ_1 | ADC14_CTL0_MSC | ADC14_CTL0_ON;
    ADC14->MCTL[0] |= ADC14_MCTLN_INCH_5;                   // Select P5.0 as ADC Channel
    ADC14->MCTL[1] |= ADC14_MCTLN_INCH_4;                   // Select P5.1 as ADC Channel
    ADC14->MCTL[2] |= ADC14_MCTLN_INCH_3 | ADC14_MCTLN_EOS; // Select P5.2 as ADC Channel
    ADC14->CTL1 |= ADC14_CTL1_RES__14BIT;                   // Select bit resolution
    ADC14->IER0 |= ADC14_IER0_IE2;                          // Enable interrupt for mem 0

    NVIC->ISER[0] = 1 << ((ADC14_IRQn)&31); // enable NVIC for ADC
    __enable_irq();                         // enable global interrupts
    while (1)
    {
        __delay_cycles(500000);
        ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC; // Enable ADC conversion and Start Conversion
    }
}

void ADC14_IRQHandler(void)
{
    if (ADC14->IFGR0 & ADC14_IFGR0_IFG2)
    { // check if MEM2 has been trigger
        // capture data and store into data structure
        sensor.x_axis[index] = ADC14->MEM[0];
        sensor.y_axis[index] = ADC14->MEM[1];
        sensor.z_axis[index++] = ADC14->MEM[2]; // post increment index counter

        if (index > DATA_SIZE)
        { // check if index is reached threshold

            uint32_t axis_data[3] = {0, 0, 0}; // create temp variable

            int i;
            for (i = 0; i < DATA_SIZE; i++)
            { // iterate over the data structure axis readings
                // store in temp
                axis_data[0] += sensor.x_axis[i];
                axis_data[1] += sensor.y_axis[i];
                axis_data[2] += sensor.z_axis[i];
            }
            // get the average reading of the axis data
            axis_data[0] /= DATA_SIZE;
            axis_data[1] /= DATA_SIZE;
            axis_data[2] /= DATA_SIZE;

            // display data
            lcdSetText("ADC 3-Axis CH", 0, 0);
            lcdSetText("                ", 0, 1);
            lcdSetInt(axis_data[0], 0, 1);
            lcdSetInt(axis_data[1], 6, 1);
            lcdSetInt(axis_data[2], 12, 1);
            index = 0;
        }
    }
}
