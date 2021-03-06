# **Multiple Dimmer :zap:**

## **Description**
This program will demostrate how to use Timer_A to create pulse width modulation (PWM) signals. TimerA has a total of 4 timers: TimerA0, TimerA1, TimerA2, TimerA3. With the use of capture compare mode, PWM signal can be generated. The following program will demostrate how to use all of the TimerA0 PWM pins to change the brightness of a LED.

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## **MSP432 Timer_A Configuration Table 1**
| **Bit**  | **Name**              | **Descriptions** |
| :---: | :---:            | :--- |        
| 0     | TAIFG           | Timer_A <br> 0: Timer did not overflow <br> 1:Timer overflow |  
| 1     | TAIE          |  Timer_A Interrupt Enable (0: Disabled, 1: Enabled)   | 
| 2     | TACLR       |  Timer_A Clear    |
| 4-5   | MC       |  Mode Control: <br> 00: Stop mode: timer is halted <br> 01: Up mode: Timer counts to TAxCCR0 <br> 10: Continous mode: Timer counts up to 0xFFF <br> 11: Up/down mode: Timer counts up to TAxCCR0 then down to 0.   |
| 6-7   | ID | Input divider: These bits select the divider for the input clock: <br> 00: divide by 1 <br> 01: divide by 2 <br> 10: divide by 4 <br> 11: divide by 8|
| 8-9 | TASSEL | Timer_A clock Source Select: These bits select the Timer_A clock source: <br> 00: TAxCLK (external clock): The timer uses external clock which is fed to the PM_TAxCLK pin. <br> 01: ACLK (internal clock) <br> 10: SMCLK (internal clock) <br> 11: INCLK
  * TIMER_Ax->CTRL register table 

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

Example of how to set the Timer_A0 to set the period and duty cycle of TA0.1.
~~~c
TIMER_A0->CTL |= TIMER_A_CTL_TASSEL_2| TIMER_A_CTL_MC_1; // SMLCK and UP-MODE
TIMER_A0->CCR[0] = 60000 - 1; //CCR max is 65k,  3Mhz/ 60k -> 50, 50 cycles for 1 second
TIMER_A0->CCR[1] = 30000 - 1; // set the TA0.1 @ 50% duty cycle  
TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; //enable interrupt
TIMER_A0->CCTL[1] = TIMER_A_CCTLN_OUTMOD_7; //enable for PWM
~~~

## **Authors:**
* [**Jesus Minjares** :zap:](https://github.com/jminjares4)<br>
  * Master of Science in Computer Engineering<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares4@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jesusminjares/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/jminjares4)
* [**Jorge Minjares** :zap:](https://github.com/JorgeMinjares)<br>
  * Bachelor of Science in Electrical Engineering<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares5@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jorge-minjares/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/JorgeMinjares)

