# **Interrupt Bit Shifts :zap:**

## Description
This program will demostrate how to use interrupts and control a global variable. The interrupt configuration of the following program is at `pull-up`!

## Pinout
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## MSP432 I/O Configuration Table 
| PxDIR | PxREN | PxOUT | I/O Configuration|
| :---: | :---: | :---: |     :---         |     
| 0     | 0     |  x    |  Input           |
| 0     | 1     |  0    |  Input with pulldown resistor  |
| 0     | 1     |  1    |  Input with pullup resistor |
| 1     | x     |  x    |  Output         |
  * I/O Configuration

## MPS432 Interrupt Configuration Table
| PxIE  | PxIES | PxIFG | I/O Configuration  |
| :---: | :---: | :---: |     :---           |     
| 1     | 0     |  0    |  Pull-down         |
| 1     | 1     |  0    |  Pull-up           |
| x     | x     |  1    | Interrupt occured! |
  * Interrupt Configuration

## LEDs 
| Color | Voltage (V) | Current (mA) |
|:---   | :---:       |     ---:     |
| Red   | 1.8-2.4     |      20      |
| Yellow| 2.0-2.2     |      20      |
| Green | 3.0-3.4     |      20      |
| Blue  | 3.0-3.4     |      20      | 
| White | 3.0-3.4     |      20      |
  * Table 1 Typical LED with voltage and current requirements
## LEDs Circuit
<img src="https://user-images.githubusercontent.com/60948298/146442932-b87b92c4-9241-40eb-b26e-057f261b8fbc.png" width="450" height="250">

## **Pull-up and Pull-down Configuration**

<img width="413" alt="button configuation" src="https://user-images.githubusercontent.com/60948298/144836131-96f04e0f-c7f7-443f-b35c-814fb9db4e29.png">

## Authors:
  - Jesus Minjares :zap:
    - Master of Science in Computer Engineering
  - Jorge Minjares :zap:
    - Bachelor of Science in Electrical Engineering
