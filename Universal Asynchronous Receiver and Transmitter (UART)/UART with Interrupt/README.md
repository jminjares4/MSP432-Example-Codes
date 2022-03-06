# **UART with Interrupt :zap:**

## **Description**
This program will demostrate how to received characters through Universal Asynchronous Receiver and Transmitter (UART) via an interrupt and do corresponding subroutines. 

## **Pinout**
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
- Texas Instrument

## **Universal Asynchronous Receiver and Transmitter (UART) MSP432 Pins**
| UARTx | I/O Pins | PxSELx |
| :---  | :---     | :---:  |
| UART0 | P1.2->RX<br> P1.3->TX| P1->SEL0 -> enabled <br> P1->SEL1 -> disabled|
| UART1 | P2.2->RX<br> P2.3->TX| P2->SEL0 -> enabled <br> P2->SEL1 -> disabled|
| UART2 | P3.2->RX<br> P3.3->TX| P3->SEL0 -> enabled <br> P3->SEL1 -> disabled|
| UART3 | P9.6->RX<br> P9.7->TX| P9->SEL0 -> enabled <br> P9->SEL1 -> disabled|
  * UART Pinout Selection

## **MSP432 UART Configuration Table**
| **Field**  | **Bit** | **Description** |
| :---: | :---:            | :--- |
| UCPEN | D15 | 0b = Parity disabled <br> 1b = Parity enabled. Parity is generated (UCAxTXD) and expected (UCAxRXD) |
| UCPAR | D14 | 0b = Odd parity <br> 1b = Even parity |
| UCMSB | D13 | 0b = LSB first <br> 1b = MSB first |
| UC7BIT| D12 | 0b = 8-bit data <br> 1b = 7-bit data |
| UCSPB | D11 | 0b = One stop bit <br> 1b = Two stop bits |
| UCMODEx | D10:9 | 00b = UART mode <br> 01b = Idle-line multiprocessor mode <br> 10b = Address-bit multiprocessor mode <br> 11b = UART mode with automatic baud-rate detection |
| UCSYNC | D8 | 0b = Asynchronous mode <br> 1b = Synchronous mode |
| UCSSELx | D7:6| 00b = UCLK <br> 01b = ACLK <br> 10b = SMCLK <br> 11b = SMCLK |
| UCRXIE | D5 | 0b = Erronenous characters rejected and UCRXIFG is not set. <br> 1b = Erroneous characters recieved set UCRXIFG |
| UCBRKIE | D4 | 0b = Received break characters do not set UCRXIFG. <br> 1b = Recieved break characters set UCRXIFG. |
| UCDORM | D3 | 0b = Not dormant. All received character set UCRXIFG. <br> 1b = Dormant. Only characters that are not preceded by an idle-line or with address bit set UCRXIFG. In UART mode with automatic baud-rate detection, only the combination of a break and synch field sets UCRXIFG.|
| UCTXADDR | D2 | 0b = Next frame transmitted is data. <br> 1b = Next frame transmitted is an address |
| UCTXBRK | D1 | 0b = Next frame transmitted is not a break. <br> 1b = Next frame transmitted is a break or a break/synch. |
| UCSWRST | D0 | 0b = Disabled. eUSCI_A reset released for operation. <br> 1b = Enabled. eUSCI_A logic held in reset state. |
  * EUSCI_Ax->CTLW0 register table 

## **Disable and Enable Oversampling**
 - ***Enable Oversampling***
~~~c
// Assuming SMLCK -> 3MHz and Baudrate (BR) -> 9600 
// Using UART 0 
EUSCI_A0->BRW = 19; // SMCLK/16/BR -> 3000000/16/9600 = 19.53125
EUSCI_A0->MCTLW = (9 << EUSCI_A_MCTLW_BRF_OFS | EUSCI_A_MCTLW_OS16); // 19.53125 - 19 = 0.53125 * 16 = 8.5, round up to 9				 
~~~
 - ***Disable Oversampling***
~~~c
// Assuming SMLCK -> 3MHz and Baudrate (BR) -> 9600 
// Using UART 0 
EUSCI_A0->BRW = 19; // SMCLK/BR -> 3000000//9600 = 312
EUSCI_A0->MCTLW = 0; // Disable oversampling	
~~~

## **Authors:**
* [**Jesus Minjares** :zap:](https://github.com/jminjares4)<br>
  * Master of Science in Computer Engineering<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares4@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jesus-minjares-157a21195/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/jminjares4)
* [**Jorge Minjares** :zap:](https://github.com/JorgeMinjares)<br>
  * Bachelor of Science in Electrical Engineering<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares5@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jorge-minjares/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/JorgeMinjares)
