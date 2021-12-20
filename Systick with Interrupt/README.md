# **SysTick Timer with Interrupts :zap:**

## **Description**
This program will demostrate how to use SysTick to create periodic tasks. The SysTick will be controlled by interrupts as they will disable or enable the timer.

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## **MSP432 I/O Configuration Table** 
| PxDIR | PxREN | PxOUT | I/O Configuration|
| :---: | :---: | :---: |     :---         |     
| 0     | 0     |  x    |  Input           |
| 0     | 1     |  0    |  Input with pulldown resistor  |
| 0     | 1     |  1    |  Input with pullup resistor |
| 1     | x     |  x    |  Output         |
  * I/O Configuration

## **MPS432 Interrupt Configuration Table**
| PxIE  | PxIES | PxIFG | I/O Configuration  |
| :---: | :---: | :---: |     :---           |     
| 1     | 0     |  0    |  Pull-down         |
| 1     | 1     |  0    |  Pull-up           |
| x     | x     |  1    | Interrupt occured! |
  * Interrupt Configuration

## **Pull-up and Pull-down Configuration**

<img width="413" alt="button configuation" src="https://user-images.githubusercontent.com/60948298/144836131-96f04e0f-c7f7-443f-b35c-814fb9db4e29.png">


## **MPS432 SysTick Configuration Table**
| Bit  | Name              | Descriptions |
| :---: | :---:            | :--- |        
| 0     | ENABLE           | Enable <br> 0: the counter is disabled<br> 1:enables SysTick to begin counting down|  
| 1     | TICKINT          |  Interrupt Enable <br> 0: Interrupt generation is disabled <br>1: when SysTick counts to 0 an interrupt is generated<br>    | 
| 2     | CLKSOURCE        |  Clock Source <br> 0: 0: External clock <br> 1: System clock    |
  * SysTick->CTRL register table 

Example of how to set the SysTick Timer. The following code will set the interrupt to run every second.
~~~c
SysTick->CTRL |= 0x07; //enable, tick int, and clock source
SysTick->VAL = 0; //clear value register
SysTick->LOAD  = 3000000 - 1; // 1 sec period, N - 1, load is 24 bit register->max = 0xFFFFFF 
~~~

## **Authors:**
  - Jesus Minjares :zap:
    - Master of Science in Computer Engineering
  - Jorge Minjares :zap:
    - Bachelor of Science in Electrical Engineering
