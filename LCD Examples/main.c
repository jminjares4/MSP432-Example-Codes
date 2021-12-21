/**
 * @file main.c
 * @author Jesus Minjares (https://github.com/jminjares4)
 * @author Jorge Minjares (https://github.com/JorgeMinjares)
 * @brief Demostratation of how to use the LCD driver
 * @version 0.1
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "msp.h"
#include <lcdLib.h>
#include <string.h>

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	// Initialize LCD driver
	lcdInit();
	// Clear previous data in LCD
	lcdClear();

	// Set Text
	lcdSetText("Hello World!", 0, 0);
	// Set integer
	lcdSetInt(100, 13, 0);

	// Set custom text
	char buffer[16]; // lcd text length
	sprintf(buffer, "Custom: %.2lf", 98.2f);

	lcdSetText(buffer, 0, 1); // set to bottom line
	while (1)
		;
}
