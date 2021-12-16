# **GPIO BUttons :zap:**

## Description
This program will demostrate how to use GPIO inputs to turn on and off the external `LEDs`.

## Pinout
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## LEDs 
| PxDIR | PxREN | PxOUT | I/O Configuration|
| :---: | :---: | :---: |     :---         |     
| 0     | 0     |  x    |  Input           |
| 0     | 1     |  0    |  Input with pulldown resistor  |
| 0     | 1     |  1    |  Input with pulldown resistor |
| 1     | x     |  x    |  Output         |
  * I/O Configuration

  * Table 1 Typical LED with voltage and current requirements

### **Pull-up and Pull-down Configuration**

<img width="413" alt="button configuation" src="https://user-images.githubusercontent.com/60948298/144836131-96f04e0f-c7f7-443f-b35c-814fb9db4e29.png">

## Authors:
  - Jesus Minjares :zap:
    - Master of Science in Computer Engineering
  - Jorge Minjares :zap:
    - Bachelor of Science in Electrical Engineering
