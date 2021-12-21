# **Timer_A with Interrupts :zap:**

## **Description**
This program will demostrate how to use Timer_A to create periodic tasks and use interrupts to change the state of the timer.

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument


## **MSP432 I/O Configuration Table** 
| **PxDIR** | **PxREN** | **PxOUT** | **I/O Configuration**|
| :---: | :---: | :---: |     :---         |     
| 0     | 0     |  x    |  Input           |
| 0     | 1     |  0    |  Input with pulldown resistor  |
| 0     | 1     |  1    |  Input with pullup resistor |
| 1     | x     |  x    |  Output         |
  * I/O Configuration

## **MSP432 Interrupt Configuration Table**
| **PxIE**  | **PxIES** | **PxIFG** | **I/O Configuration**  |
| :---: | :---: | :---: |     :---           |     
| 1     | 0     |  0    |  Pull-down         |
| 1     | 1     |  0    |  Pull-up           |
| x     | x     |  1    | Interrupt occured! |
  * Interrupt Configuration

## **Pull-up and Pull-down Configuration**

<img width="413" alt="button configuation" src="https://user-images.githubusercontent.com/60948298/144836131-96f04e0f-c7f7-443f-b35c-814fb9db4e29.png">


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
