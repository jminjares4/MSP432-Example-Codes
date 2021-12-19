#include "msp.h"
#include <lcdLib.h>
#include <string.h>
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Initialize LCD driver
	lcdInit();
	//Clear previous data in LCD
	lcdClear();

	//Set Text
	lcdSetText("Hello World!", 0,0);
	//Set integer
	lcdSetInt(100, 13, 0);

	//Set custom text
	char buffer[16]; //lcd text length
	sprintf(buffer, "Custom: %.2lf", 98.2f);

	lcdSetText(buffer, 0,1); //set to bottom lien
	while(1);
}
