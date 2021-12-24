#include <lcdLib.h>

#define	LOWNIB(x)	P4->OUT = (P4->OUT & 0xF0) + (x & 0x0F)

void lcdInit() {
	delay_ms(100);
	// Wait for 100ms after power is applied.

	P4->DIR = EN | RS | DATA;  // Make pins outputs
	P4->OUT = 0x03;  // Start LCD (send 0x03)

	lcdTriggerEN(); // Send 0x03 3 times at 5ms then 100 us
	delay_ms(5);
	lcdTriggerEN();
	delay_ms(5);
	lcdTriggerEN();
	delay_ms(5);

	P4->OUT = 0x02; // Switch to 4-bit mode
	lcdTriggerEN();
	delay_ms(5);

	lcdWriteCmd(0x28); // 4-bit, 2 line, 5x8
	lcdWriteCmd(0x08); // Instruction Flow
	lcdWriteCmd(0x01); // Clear LCD
	lcdWriteCmd(0x06); // Auto-Increment
	lcdWriteCmd(0x0C); // Display On, No blink
}

void lcdTriggerEN() {
	P4->OUT |= EN;
	P4->OUT &= ~EN;
}

void lcdWriteData(unsigned char data) {
	P4->OUT |= RS; // Set RS to Data
	LOWNIB(data >> 4); // Upper nibble
	lcdTriggerEN();
	LOWNIB(data); // Lower nibble
	lcdTriggerEN();
	delay_us(50); // Delay > 47 us
}

void lcdWriteCmd(unsigned char cmd) {
	P4->OUT &= ~RS; // Set RS to Data
	LOWNIB(cmd >> 4); // Upper nibble
	lcdTriggerEN();
	LOWNIB(cmd); // Lower nibble
	lcdTriggerEN();
	delay_ms(5); // Delay > 1.5ms
}

void lcdSetText(char* text, int x, int y) {
	int i;
	if (x < 16) {
		x |= 0x80; // Set LCD for first line write
		switch (y){
		case 1:
			x |= 0x40; // Set LCD for second line write
			break;
		case 2:
			x |= 0x60; // Set LCD for first line write reverse
			break;
		case 3:
			x |= 0x20; // Set LCD for second line write reverse
			break;
		}
		lcdWriteCmd(x);
	}
	i = 0;

	while (text[i] != '\0') {
		lcdWriteData(text[i]);
		i++;
	}
}

void lcdSetInt(int val, int x, int y){
	char number_string[16];
	sprintf(number_string, "%d", val); // Convert the integer to character string
	lcdSetText(number_string, x, y);
}

void lcdClear() {
	lcdWriteCmd(CLEAR);
}
