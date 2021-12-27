# **Analog-to-Digital Converter (ADC) :zap:**

## **Description**
This program will demostrate how to set up ADC using multiple channels. Using ADC the program store the information from P5.0 and P5.1 and displays their memory onto an Liquid Crystal display(LCD).

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## **MSP432 ADC Configuration Table 1- Turning on ADC14**
| **Bit**  | **Name**              | **Descriptions** |
| :---: | :---:            | :--- |        
|    31-30    | ADC14PDIV | ADC14 predivider. These bits pre-divide the selected ADC14 clock source. Can be modified only when ADC14ENC = 0. <br> 00b = Predivide by 1. <br>01b = Predivide by 4<br>10b = Predivded by 32<br>11b = Predivide by 64 |  
|    29-27    | ADC14SHSx | ADC14 sample-and-hold source select.<br>Can be modified only when ADC14ENC = 0. <br>000b = ADC14SC bit.<br>001b = TA0_C1 <br>010b = TA0_C2<br>011b = TA1_C1<br>100b = TA1_C2<br>101b = TA2_C1<br>110b = TA2_C2<br>111b = TA3_C1 | 
|    26       | ADC14SHP | ADC14 sample-and-hold pulse-mode select. This bit selects the source of the sampling signal (SAMPCON) to be either the output of the sampling timer or the sample-input signal directly. <br>Can be modified only when ADC14ENC = 0.<br>0b = SAMPCON signal is sourced from the sample-input signal.<br>1b = SAMPCON signal is sourced from the sampling timer.|
|    25       |ADCUSSH| ADC14 invert signal sample-and-hold. <br> Can be modified only when ADC14ENC = 0. <br> 0b = The sample-input signal is not inverted. <br>1b = The sample-input signal is inverted.<br>Setting ADC14ISSH = 1 and triggering a conversion using ADC14SC is not recommended. ADC14SC bit gets reset to 0 automatically at the end of conversion and if ADC14ISSH = 1, the 1->0 transition on ADC14SC will trigger another conversion.|
|    24-22    | ADC14DIVx |ADC14 clock divider.<br>Can be modified only when ADC14ENC = 0. <br>000b = /1 <br>001b = /2<br>010b = /3<br>011b = /4<br>100b = /5<br>101b = /6<br>110b = /7<br>111b = /8|
|    21-19    | ADCSSELx |ADC14 clock source select.<br> Can be modified only when ADC14ENC = 0.<br>000b = MODCLK<br>001b = SYSCLK<br>010b = ACLK<br>011b = MCLK<br>100b = SMCLK<br>101b = HSMCLK<br>110b = Reserved<br>111b = Reserved| 
|    18-17    | ADC14CONSEQx |ADC14 conversion sequence mode select.<br>Can be modifided only when ADC14ENC = 0.<br>00b = Single-channel, single-conversion<br>01b = Sequence-of-channels<br>10b = Repeat-single-channel<br>11b = Repeat-sequence-of-channels|
|    16       | ADC14BUSY |ADC14 busy. This bit indicates an active sample or conversion operation.<br>0b = No operation is active.<br>1b = A sequence, sample, or conversion is active|
|    15-12    | ADC14SHT1x |ADC14 sample-and-hold time. These bits define the number of ADC14CLk cycles in the sampling period for registers ADC14MEM8 to ADC14MEM23.<br>Can be modified only when ADC14ENC = 0.<br>0000b = 4<br>0001b = 8<br>0010b = 16<br>0011b = 32<br>0100b = 64<br>0101b = 96<br>0110b = 128<br>0111b = 192|
|    11-8     | ADC14SHT0x |ADC14 sample-and-hold time. These bits define the number of ADC14CLK cycles in the sampling period for registers ADC14MEM0 to ADC14MEM7 and ADC14MEM24 to ADCMEM31. <br> Can be modified only when ADC14ENC = 0. <br>0000b = 4<br>0001b = 8<br>0010b = 16<br>0011b = 32<br>0100b = 64<br>0101b = 96<br>0110b = 128<br>0111b = 192<br>1000b to 1111b = Reserved|
|    7        | ADC14MSC |ADC14 multiple sample and conversion. Valid only for sequence or repeated modes.<br>0b = The sampling timer requires a rising edge of the SHI signal to trigger each sample-and-convert.<br>1b = The first rising edge of the SHI signal triggers the sampling timer, but further sample-and-conversions are performed automatically as soon as the prior conversion is completed. |
|    6-5      | RESERVED |Reserved. Always reads as 0.|
|    4        | ADC14ON |ADC14 on<br>0b = ADC14 off<br>1b = ADC14 on. ADC core is ready to power up when a valid conversion is triggered.|
|    3-2      | RESERVED |Reserved. Always reads as 0.|
|    1        | ADC14ENC |ADC14 enable conversion<br>0b = ADC14 disabled<br>1b = ADC14 enabled<br>ADC14ENC low pulse width must be at-least 3 ADC14CLK cycles.|
|    0        | ADC14SC |ADC14 start conversion. Software-controlled sample-and-conversion start.<br>ADC14SC and ADC14ENC may be set together with one instruction.<br>0b = No sample-and-conversion-start<br>1b = Satart sample-and-conversion|
## **MS432 ADC Conversion Memory Control (ADC14MCTL0) Table**
| **Bit**  | **Name**              | **Descriptions** |
| :---: | :---:            | :--- |        
| 13 | ADC14DIF | Differential mode (0 = single-ended, 1 = Differential) | 
| 11-18 | ADCVRSEL | ADC Vref selection. <br>0000 = Vref+= AVCC(analog VCC) and Vref-=AVSS<br>1110 = Vref+= External Source connected to pin 5.6<br>   Vref-=External Source connected to pin 5.7 |
| 4-0 | ADC14INCH | ADC14 input channel: The field selects the input channel. When DIFF = 0 (single-ended mode), values 0 to 23 choose between 24 ADC input channels. WhenDIFF = 1(Differential mode), values 0 to 15 select between the 12 differential channels. See the referance manual for more information.<br>00000 = A0<br>00001 = A1 <br>00010 = A2 <br>00011 = A3<br>00100 = A4<br>00101 = A5<br>00110 = A6<br>00111 = A7 <br>01000 = A8<br>01001 = A9 <br>01010 = A10 <br>01011 = A11 <br>01100 = A12 <br>01101 = A13 <br>01110 = A14 <br>01111 = A15<br>10000 = A16<br>10001 = A17<br>10010 = A18 <br>10011 = A19<br>10100 = A20 <br>10101 = A21 <br>10110 = A22<br>10111 = A23|
    * ADC14->MCTL[x]

## **MSP432 ADC Channels Tables**
|**Pin Function**|**ADC Channel Input**|**Pin Name**|**PxSEL1 : PxSEL0**|
| :--- | :---| :--- | :--- |   
|A0|ADC input 0|P5.5|PSSEL0 = 00100000 = 0x20<br>PSSEL1 = 00100000 = 0x20|
|A1|ADC input 1|P5.4|PSSEL0 = 00010000 = 0x10<br>PSSEL1 = 00010000 = 0x10|
|A2|ADC input 2|P5.3|PSSEL0 = 00001000 = 0x08<br>PSSEL1 = 00001000 = 0x08|
|A3|ADC input 3|P5.2|PSSEL0 = 00000100 = 0x04<br>PSSEL1 = 00000100 = 0x04|
|A4|ADC input 4|P5.1|PSSEL0 = 00000010 = 0x02<br>PSSEL1 = 00000010 = 0x02|
|A5|ADC input 5|P5.0|PSSEL0 = 00000001 = 0x01<br>PSSEL1 = 00000001 = 0x01|
|A6|ADC input 6|P4.7|PSSEL0 = 10000000 = 0x80<br>PSSEL1 = 10000000 = 0x80|
|A7|ADC input 7|P4.6|PSSEL0 = 01000000 = 0x40<br>PSSEL1 = 01000000 = 0x40|
|A8|ADC input 8|P4.5|PSSEL0 = 00100000 = 0x20<br>PSSEL1 = 00100000 = 0x20|
|A9|ADC input 9|P4.4|PSSEL0 = 00010000 = 0x10<br>PSSEL1 = 00010000 = 0x10|
|A10|ADC input 10|P4.3|PSSEL0 = 00001000 = 0x08<br>PSSEL1 = 00010000 = 0x08|
|A11|ADC input 11|P4.2|PSSEL0 = 00000100 = 0x04<br>PSSEL1 = 00000100 = 0x04|
|A12|ADC input 12|P4.1|PSSEL0 = 00000010 = 0x02<br>PSSEL1 = 00000010 = 0x02|
|A13|ADC input 13|P4.0|PSSEL0 = 00000001 = 0x01<br>PSSEL1 = 00000001 = 0x01|
|A14|ADC input 14|P6.1|PSSEL0 = 00000010 = 0x02<br>PSSEL1 = 00000010 = 0x02|
|A15|ADC input 15|P6.0|PSSEL0 = 00000001 = 0x01<br>PSSEL1 = 00000001 = 0x01|
|A16|ADC input 16|P9.1|PSSEL0 = 00000010 = 0x02<br>PSSEL1 = 00000010 = 0x02|
|A17|ADC input 17|P9.0|PSSEL0 = 00000001 = 0x01<br>PSSEL1 = 00000001 = 0x01|
|A18|ADC input 18|P8.7|PSSEL0 = 10000000 = 0x80<br>PSSEL1 = 10000000 = 0x80|
|A19|ADC input 19|P8.6|PSSEL0 = 01000000 = 0x40<br>PSSEL1 = 01000000 = 0x40|
|A20|ADC input 20|P8.5|PSSEL0 = 00100000 = 0x20<br>PSSEL1 = 00100000 = 0x20|
|A21|ADC input 21|P8.4|PSSEL0 = 00010000 = 0x10<br>PSSEL1 = 00010000 = 0x10|
|A22|ADC input 22|P8.3|PSSEL0 = 00001000 = 0x08<br>PSSEL1 = 00001000 = 0x08|
|A23|ADC input 23|P8.2|PSSEL0 = 00000100 = 0x04<br>PSSEL1 = 00000100 = 0x04|

## **MSP432 Selecting Bit Resolution (ADC14CTL1)**
| **Bit**  | **Name**              | **Descriptions** |
| :---: | :---:            | :--- | 
|31-28|Reserved|Reserved|
|27|ADC14CH3MAP|0b = ADC input channel internal 3 is not selected<br>1b = ADC input channel internal 3 is selected for ADC input channel MAX-5|
|26|ADC14CH2MAP|0b = ADC input channel internal 2 is not selected<br> 1b = ADC input channel internal 2 is selected for ADC input channel MAX-4|
|25|ADC14CH1MAP|0b = ADC input channel internal 1 is not selected<br> 1b = ADC input channel internal 1 is selected for ADC input channel MAX-3|
|24|ADC14CH0MAP|0b = ADC input channel internal 0 is not selected<br> 1b = ADC input channel internal 0 is selected for ADC input channel MAX-2|
|23|ADC14TCMAP|0b = ADC internal temperature sensor channel is not selected for ADC<br> 1b = ADC internal temperature sensor channel is selected for ADC input channel|
|22|ADC14BATMAP|0b = ADC internal 1/2x AVCC channel is not selected for ADC<br>1b = ADC internal 1/2 x AVCC channel is selected for ADC input channel MAX|
|21|Reserved|Reserved|
|20-16|ADC14CSTARTADDx|0h to 1Fh, corresponding to ADC14MEM0 to ADC14MEM31|
|15-6|Reserved|Reserved|
|5-4|ADC14RES|00b = 8 bit(9 clock cycle conversion time)<br>01b = 10 bit(11 clock cycle conversion time)<br>10b = 12 bit(14 clock cycle conversion time)<br>11b = 14 bit(16 clock cycle conversion time)|
|3|ADC14DF|0b = Binary unsigned. Theoretically, for ADC14DIF = 0 and 14-bit mode, the analog input voltage -V(REF) results in 0000h, and the analog input voltage +V(REF) results in 3FFFh. <br>1b = Signed binary (2s complement), left aligned. Theoretically, for ADC14DIF = 0 and 14-bit mode, the analog input voltage -V(REF) results in 8000h, and the analog input voltage +V(REF) results in 7FFCh.|
|2|ADC14REFBURST|0b = ADC reference buffer on continuosuly <br> 1b = ADC reference buffer on only during sample-and-conversion|
|1-0|ADC14WRMD|00b = Regular power mode for use with any resolution setting. Sample rate can be up to Msps.<br>01b = Reserved<br>10b = Low-power mode for 12-bit, 10-bit, and 8-bit resolution settings. Sample rate must not exceed 200 ksps.<br>11b = Reserved|

Example of how to set the ADC14. The following code will set the ADC to read from a sampling timer as a single-channel and single-conversion ADC.
~~~c
ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_CONSEQ_0 | ADC14_CTL0_ON;
ADC14->MCTL[0] = ADC14_MCTLN_INCH_5;							// set ADC channel as A5 = P5.0
ADC14->CTL1 |= ADC14_CTL1_RES__14BIT;							// set resolution as a 14 bits resolution
ADC14->IER0 |= ADC14_IER0_IE0;										// interrupt for mem 0
~~~

## **Authors:**
  - Jesus Minjares :zap:
    - Master of Science in Computer Engineering
  - Jorge Minjares :zap:
    - Bachelor of Science in Electrical Engineering
