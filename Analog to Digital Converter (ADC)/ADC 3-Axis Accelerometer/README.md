# **Timer_A :zap:**

## **Description**
This program will demostrate how to use ADC to read information from external sources.

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
|    0        | ADC14SC |ADC14 start |
## **MS432 Timer_A Configuration Table 2**
| **Bit**  | **Name**              | **Descriptions** |
| :---: | :---:            | :--- |        
| 15-14 | CM | Capture mode <br> 00: No capture <br> 01: Capture on rising edge <br> 10: Capture on falling edge <br> 11: Capture on both rising and falling edges
| 13-12 | CCIS | Capture/compare input select. These its select the TAxCCR0 input signal: <br> 00: CCIxA <br> 01: CCIxB <br> 10: GND <br> 11:  VCC |
| 11 | SCS | Synchronize capture source. This bit is used to synchronize the capture input signal with the timer clock. <br> 0: Asynchronous capture <br> 1: Synchronous capture |
| 10 | SCCI | Synchronized capture/compare input. The selected CCI input signal is latched with the EQUx signal and can be read via this bit. |
| 8 | CAP | Capture mode <br> 0: Compare comode <br> 1: Capture mode |
| 7-5 | OUTMOD | Output mode. Mode 2,3,6, and 7, are not useful for TAxCCR0 because EQUx = EQU0 <br> 000: OUT bit value <br> 001: Set <br> 010: Toggle/reset <br> 011: Set/reset <br> 100: Toggle <br> 101: Reset <br> 110: Toggle/set <br> 111: Reset/set |
| 4 | CCIE | Capture/compare interrupt enable. This bit enables the interrupt request of the corresponding CCIFG flag. <br> 0: Interrupt disabled <br> 1: Interrupt enabled |
| 3 | CCI | Capture/compare input. The selected input signal can be read by this bit. |
| 2 | OUT | Output. For output mode 0, this bit directly controls the state of the output. <br> 0: Output low <br> 1: Output high|
| 1 | COV | Capture overflow. THis bit indicates a capture overflow occured. COV mst be reset with software. <br> 0: No capture overflow occured <br> 1: Capture overflow occured|
| 0 | CCIFG | Capture/compare interrupt flag <br> 0: No interrupt pending <br> 1: Interrupt pending |
    * TIMER_Ax->CCTL

Example of how to set the Timer_A timer. The following code will set the interrupt to run .02 second or 20ms.
~~~c
TIMER_A0->CTL |= TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1; // SMLCK and UP-MODE
TIMER_A0->CCR[0] = 60000 - 1; //CCR max is 65k,  3Mhz/ 60k -> 50, 50 cycles for 1 second
TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; //enable interrupt
~~~

## **Authors:**
  - Jesus Minjares :zap:
    - Master of Science in Computer Engineering
  - Jorge Minjares :zap:
    - Bachelor of Science in Electrical Engineering
