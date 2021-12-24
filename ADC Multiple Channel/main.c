#include "msp.h"
#include "lcdLib.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//Configure P5.0 and P5.1 as ADC input Channels
	P5->SEL0 |= (BIT0|BIT1);
	P5->SEL1 |= (BIT0|BIT1);

	lcdInit();
	lcdClear();

	lcdSetText("ADC Multiple CH",0,0);


	//SHP = using signal from sampling timer,
	//CONSEQ = enable conversion of sequence channels
	//ON = turn ADC on
	ADC14->CTL0 |= ADC14_CTL0_SHP|ADC14_CTL0_CONSEQ_1| ADC14_CTL0_MSC | ADC14_CTL0_ON;
	ADC14->MCTL[0] |= ADC14_MCTLN_INCH_5; //Select P5.0 as ADC Channel
	ADC14->MCTL[1] |= ADC14_MCTLN_INCH_4 | ADC14_MCTLN_EOS; //Select P5.1 as ADC Channel
	ADC14->CTL1 |= ADC14_CTL1_RES__14BIT;// Select bit resolution
	ADC14->IER0 |= ADC14_IER0_IE1;//Enable interrupt for mem 0

	NVIC->ISER[0] = 1 << ((ADC14_IRQn) & 31);
	__enable_irq();
	while(1){
	    __delay_cycles(1500000);
	    ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC;//Enable ADC conversion and Start Conversion
	}
}


void ADC14_IRQHandler(void){
    if(ADC14->IFGR0 & ADC14_IFGR0_IFG1){
        //capture data
        uint16_t ch0 = ADC14->MEM[0];
        uint16_t ch1 = ADC14->MEM[1];

        //display data
        lcdSetText("ADC Multiple CH",0,0);
        lcdSetText("                ", 0, 1);
        lcdSetInt(ch0, 0, 1);
        lcdSetInt(ch1, 8, 1);
    }
}
