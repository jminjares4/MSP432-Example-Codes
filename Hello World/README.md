# **Hello World! :zap:**

## Description
This code will just turn an `P1.0` onboard LED, which is the RED onboard led of the MSP432 at the register level. 

## Pinout
![image](https://user-images.githubusercontent.com/60948298/146273491-d2079ae0-385a-4f9a-ac03-24f95911efea.png)
   - Texas Instrument
## Binary Operators

- Binary OR Operator
    ~~~c
    //Bit OR is use with an single vertical bar |
    uint8_t x = 1;
    uint8_t y = 2;
    x |= y; // or x = x | y, 
    //   0000 0001
    //             | -> BIT OR
    //   0000 0010
    //---------------
    //   0000 0011 -> 3
    ~~~

- Binary AND Operator
    ~~~c
    // Bit AND is use with an single &
    uint8_t x = 1;
    uint8_t y = 3;

    x &= y; // or x = x & y;
    // 0000 0001
    //          & -> BIT AND
    // 0000 0011
    //----------
    // 0000 0001 -> 1
    ~~~

- Binary One's Complement Operator
    ~~~c
    uint8_t x  = 1;
    x = ~(x); //flip bits
    // 0000 0001
    //          ~ -> 
    // 1111 1110 -> 254
    ~~~~

 - Binary XOR
    ~~~c 
    uint8_t x = 1;
    x ^= x; // toggle the bit
    // 0000 0001
    //           ^ -> BIT XOR    
    // 0000 0001 
    // -----------
    // 0000 0000 -> 0    
    x ^= 1;
    // 0000 0000
    //           ^ -> BIT XOR
    // 0000 0001  
    // ------------
    // 0000 0001 -> 1
    ~~~


# Intialize Ports
The following section of code will provide a brief description of what is going on and how to set an `LED` or `OUTPUT`. The MSP432 has various port that can be use for *general purpose input and output* or `GPIOs`. Within the MSP432, `Px` is used to select the port that will be utlize, x being the port number. For instance, we will want to use `P1.0` as an output. Therefore, `1` will be our port and `BIT0` will be the bit that we will use. 
~~~c
P1->DIR |= BIT0; //initialize BIT0 as output
~~~
Set `BIT0` as `OFF` or `LOW` by clearing the bit. Essentially, `&= ~(BITx)` will clear the specfic bit from the register.
~~~c
P1->OUT &= ~(BIT0); //set BIT0 as low or clear
~~~
Clear the bit from using the secondary function.
~~~c
P1->SEL0 &= ~(BIT0); //clear BIT0 from secondary function
P1->SEL1 &= ~(BIT0); //clear BIT0 from secondary function
~~~
The following function is a special function that is use to create some delay by wasting cpu clock cycles.
~~~c
__delay_cycles(cpu_clock_cycles);
~~~

## Authors:
  - Jesus Minjares :zap:
    - Master of Science in Computer Engineering
  - Jorge Minjares :zap:
    - Bachelor of Science in Electrical Engineering
