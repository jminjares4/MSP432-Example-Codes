# **Stopwatch :zap:**

## **Description**
This program will demostrate how to use interrupts, SysTick and the LCD to create a stop watch. 

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

## **MSP432 LCD 16x02 Pinout**
| **MSP432 Pins** |    **LCD Pin** |  **Description** |   
| :---:       |  :--:      |   :---:      |
| `GND`, 10k Potentiometer Output (V&#177;) | 1| GND|  
| `VCC`, 10k Potentiometer Output (V&#177;) | 2| VCC|    
| 10k Potentiometer Output (V<sub>o</sub>) | 3| Contrast|    
| `P4.5` | 4| RS (Register Select): 0 – Command, 1 - Data|    
| `GND`| 5| R/W (Read/Write): 0 – Write, 1 - Read|    
| `2.4` | 6| Clock Enable|    
| `NC`| 7| Data 0|
| `NC`| 8| Data 1|    
| `NC` | 9| Data 2|    
| `NC`| 10| Data 3|    
| `P4.0` | 11|  Data 4|    
| `P4.1` | 12|  Data 5|    
| `P4.2` | 13|  Data 6|    
| `P4.3` | 14|  Data 7|    
| 100&#8486; to `VCC`| 15| Backlight Anode (+)|    
| `GND`| 16| Backlight Cathode (-)|    
  * LCD Pinout Configuration
  * Credits: [EE 3176 Pinout Lab 4](http://www.ece.utep.edu/courses/web3376/MSP430_Labs.html)
  
## **LCD Main Functions**
|**Function** | **Description** |
| :---    | :---        |
| lcdInit();    |   Initialize LCD Display            |
| lcdClear();   | Clear the LCD Display of characters | 
| lcdSetText(string, c, r); | Print a string/character starting at c, column and r, row |
|lcdSetInt(integer, c, r); | Print a integer starting at c, column and r, row. |
|delay_ms(x); | Delay for x milliseconds. |
## **How to use LCD Driver**
- **1** ***Initialize lcd***
    ~~~c
    lcdInit();
    ~~~
- **1** ***Clear previous data***
    ~~~c
    lcdClear();
    ~~~
- **1** ***Set any text***
    - *Integer*
    ~~~c
    lcdSetInt(432, x, y);
    ~~~
    - *String*
    ~~~c
    lcdSetText("Hello World!",x ,y);
    ~~~
    - *Custom Text*
    ~~~c
    char buffer[16];
    sprintf(buffer, "ECE! %.2lf, %c, %d", 3.14, 'A', 1);
    lcdSetText(buffer, x, y);
    ~~~
## **MPS432 SysTick Configuration Table**
| **Bit**  | **Name**              | **Descriptions** |
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
