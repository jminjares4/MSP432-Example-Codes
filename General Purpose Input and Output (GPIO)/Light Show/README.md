# **Light Show :zap:**

## **Description**
This program will demostrate how to use external GPIOs to create a lightshow.

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## **Current Limit Resistor**
When using `LEDs`, you must use current limit resistor to avoid  buring the led. Therefore with the use of *ohm's law*, **V = I*R** we can find the resistor to be used based on the table below. Typically 220 ohm do the job, however 330 is a safe bet!

## **LEDs** 
| **Color** | **Voltage (V)** | **Current (mA)** |
|:---   | :---:       |     ---:     |
| Red   | 1.8-2.4     |      20      |
| Yellow| 2.0-2.2     |      20      |
| Green | 3.0-3.4     |      20      |
| Blue  | 3.0-3.4     |      20      | 
| White | 3.0-3.4     |      20      |
  * Table 1 Typical LED with voltage and current requirements
## **LEDs Circuit**
<img src="https://user-images.githubusercontent.com/60948298/146442932-b87b92c4-9241-40eb-b26e-057f261b8fbc.png" width="450" height="250">

## **Bit Shift**
Bit shift as the name states will manipulate the bit by shift them according. For instance, `<<` will shift the bits to the left and `>>` shift the bits to the right.
- Left Bit Shift
~~~c
uint8_t x = 0x01 << 0; //shift 0x01 by 0 -> 0x01
uint8_t y = 0x01 << 1; //shift 0x01 by 1 -> 0x02
~~~
- Right Bit Shift 
~~~c
uint8_t x = 0x10 >> 0; //shift 0x10 by 0 -> 0x10
uint8_t y = 0x10 >> 1; //shift 0x10 by 1 -> 0x40
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
  - Bachelor of Science in Electrical Engineering
