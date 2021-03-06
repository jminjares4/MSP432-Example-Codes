# **Simple Timer :zap:**

## **Description**
This program will demostrate how to use SysTick to create periodic tasks. The following code will toggle
the onboard led every 5 seconds.

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

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
* [**Jesus Minjares** :zap:](https://github.com/jminjares4)<br>
  * Master of Science in Computer Engineering<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares4@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jesusminjares/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/jminjares4)
* [**Jorge Minjares** :zap:](https://github.com/JorgeMinjares)<br>
  * Bachelor of Science in Electrical Engineering<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares5@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jorge-minjares/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/JorgeMinjares)
