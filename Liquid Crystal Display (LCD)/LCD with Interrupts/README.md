# **Liquid Crystal Display (LCD) with Interrupts :zap:**

## **Description**
This program will demostrate how to use lcdLib that was developed by previous alumnis at **UTEP**!
The library is simple custom driver to be able to us the LCD. However, I made some slight changes 
such as changing the P4X registers to P4->X as well as renaming the library. `lcdLib_432` to `lcdLib`.
Lastly, the following code will use the LCD to display RGB current color that is on.

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
| `4.4` | 6| Clock Enable|    
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
- **2** ***Clear previous data***
    ~~~c
    lcdClear();
    ~~~
- **3** ***Set any text***
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

## **Authors:**
  - [Jesus Minjares](https://github.com/jminjares4) :zap:
    - Master of Science in Computer Engineering
  - [Jorge Minjares](https://github.com/JorgeMinjares) :zap:
    - Bachelor of Science in Electrical Engineering