# **MSP432-Example-Codes :zap:**
## **Description**

This repository will contain various examples of TI MSP432 Microcontroller. The purpose of these codes is to provide various examples of how to use the MSP432P401R at the register level. There are not many sources for the MSP432P401R, therefore we developed simple and straight-to-the-point examples. Each of the examples has the most useful setup for the most common peripherals for Microprocessor 1.

## **Table of Contents**
- [Analog to Digital Converter (ADC)](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/Analog%20to%20Digital%20Converter%20(ADC))
- [General Purpose Input and Output (GPIO)](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/General%20Purpose%20Input%20and%20Output%20(GPIO))
- [Hello World](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/Hello%20World)
- [Liquid Crystal Display (LCD)](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/Liquid%20Crystal%20Display%20(LCD))
- [Port Interrupts](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/Port%20Interrupts)
- [Pulse Width Modulation (PWM)](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/Pulse%20Width%20Modulation%20(PWM))
- [SysTick Timer](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/SysTick%20Timer)
- [TimerA](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/TimerA)
- [Universal Asynchronous Reciever and Transmitter (UART)](https://github.com/jminjares4/MSP432-Example-Codes/tree/main/Universal%20Asynchronous%20Receiver%20and%20Transmitter%20(UART))

## **Good Books for MSP432P401R**
[TI MSP432 ARM Programming for Embedded Systems](https://www.amazon.com/MSP432-Programming-Embedded-Systems-books/dp/0997925914)
* Highly recommend for a good introductory to MSP432P401R 

[Learning Embedded Systems with MSP432 microcontrollers: MSP432P401R with Code Composer Studio](https://www.amazon.com/Learning-Embedded-Systems-MSP432-microcontrollers/dp/B08FV1XTVJ)
* Volume 1 and 2 are good as they go straight examples for quick development

## **Software**
![](https://img.shields.io/badge/Code-C-informational?style=flat&logo=C&color=003B57)

## **Microcontroller**
![Texas Instruments](https://img.shields.io/static/v1?label=&message=MSP432&color=696969&logoWidth=30&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGwAAAAoCAYAAAAbrx%2B3AAAKYklEQVR42u1aA5B0ORDOzpvV%2FDNr2zv4bfNs27Zt27Zt27Zt2%2Fbd99V2159Lvdm9mdNs1euqrnlJOnlJf0mnu9%2BYgAIK6P%2BkyuLixqVqyjdyuWNIwTATUO7RmLLorNvHpn53eanqyk3N4KQAsDpjqhuKi5tNQLkPWMyYqmtHJT6%2FZUzyx2QkMsoElJuAnZDovH9Caem8tcbUALDPCFgqEhnXXFjYWRWJNKBrMTjPBJQbgJE3aK7dtypi6ieXRmePi8UmNxUWdmnbHWNTv142svedGeWxRU1uUAAYwdijq%2FlcPm%2FeUn%2F4zLLYEq7MkjXlG5j%2FlwLA9upquWTj5rpDY%2FD6LxjR8zLrFqgqX3FUNDqD9VeOjH%2BkskvXlG9o%2Fj8KALsNpo53lDocLLOed5d0KbppTPI7ld%2BgsW4vE9A%2FT3EEwhcM73nF5ctG9L5rA3bOsO7njNCkkpL5WXf1qPhHKIZYN7YsOtOWv3h4zxtRuP3Gn4rAZQMz90ZALuWfN6z7BVF0Wsbp%2BeHSEb3vTy%2BLLbZWY82urDu0p%2B36UbHiSayHx%2FiF22evzuYLfV%2BY711UUBD%2B7S%2FwNxAvcboH1BUtSF0xIv7%2BQKCROwoLew7qab2az%2Bs31e25RkP1Dulk9%2B1svtTndWXhsHdlKBTawvO8NcCrA8BbAc7v4M%2B1Du0b4vdUzzOrBAj5EF1znJR3%2BgPr%2BtGJL3hArhRwp5bHFjlEwBN2nJTmi%2FzMoRunhcOhfQgYgHvFqh4ip6uJvw5rrOfW50vfAqfes19njZGWZIyo9CXnHtHj6w%2BwUxKdD9cXFbXi%2BTc6HdVDTN3VI%2BMfppPfqrXhaDMw%2BQKGk7U46r4D%2F%2Boy5F6FSCFO4S4o%2FyT176NO02RtKH8B%2FhZj74lyufWuvfvGCD0loDtzMXMw%2Fr2Q%2BQH8C%2Fjr%2FPzwC8yHmxykostHznU2bh2b%2FOWSEb1vESCWj4i33co1NWLy2PYV7MC01LbtDcc4YP12WrLzEToi2QJGolJZD2B2oK8DngyFzgtTeTJ%2Fpe8BYk5%2FQDFlgf0rfpdwTw2BFYB%2FxxiznfZR3AD5Ye82PA8FV4Mn4H2ng9c1uUjzVZQucxuAgvn7amQsNoV1K9VXbUkgLkTs5bcrj%2Bxtv0XBOry37QamqlyZLAF7gvV4nOrTLaJi6HeH9H%2BAjq%2FchSc68gRy%2BXA4%2FDbb%2BgDzLrPbsTF27KsPHenzvpZcdkKSbUVFbVZV3inJrgcJyBr1tTvRHIE9OiBrN9bucuuY1E83jU5%2Bt2h15RoK6D8JGBS9GIp1wuNwMtyTWw%2B59%2BSkfQET9iLvQOMQgQUou3EMkf0Zz61zAfVWZr3M5WGaXFSPHpS50VllZYvrKboZATIA%2BkbLAOznqRUlC6jsPw2YwwRwZZ9hZqipg6K39mlPidlsIAAY%2Bxk5TfvbJhOn7mr3fZB9jLkEM8gohOD5WT%2FnYtOWhoMo8G8BRjcfxeFkgLUIeCHjEEDayFLyZ64J87zQ0bwT0XdZMs0hZQsLwx87HmMeTzDl6WxIPChygyuQ5%2F22vA9gv7UUFXW4sv%2F2HebQaMh9D2BPgZKflbFut9zxqHiNn6L9Y2U9kei3pshVOOPmycn9RpyUWWaQUR6yG9e6OUY6AP8yYNN8uk3RQBz9Xobs0zKPBPp8pd6lnL4N4Gy8o3GaEgN4MXmPcG0oX0xP1D28HF%2FmkTKDjBjQlB4bb7%2FDBg1BT9xkT7zsT%2BpTXPhDFi1FvS5A3gs%2BT%2Fh88D18pvMDJV8iyhxvmcetxTT%2BCPO3INzIN2jifN67EuXk9MyPfpvz1NGtxyY6kDGb5YGeZXKEGnhHgNcg04P6K4diydqKdQ%2FtbbuR%2BURx%2F7OlEVDmKRLrgM0i4oKvKHW%2BDAXPB4XuoWWaLp0bFL%2B7JXsafyF7kGsJILfpXLnQMagahrqd%2BAyAbgPfDT4Xc1mO4iZXCBM8WXba15KOCSiHiTttVwImdn4QUgBYBczEqmQfD61T2xzzOR7jbMfcXZ%2BJNQtLfULkfVlSTtN82lYR971KxillYKvtmpoSClOe9WK%2BelROTKUvMYUlfZah08FMSD%2FzHA0u4hzsPvbVorKS8hozwLqHWX2T0N2W0N1e%2BF1f1h3NADBOPnS8fXFLvaaC7pLkaQxcgPKFjFfoUrON6R9xBHpRPoNj0KGg6y1j%2FoLyB5JYfZ4ZDD6zDYO%2FBUfiDoz%2FqLjd32N%2Bm6m3J%2F0%2FJ5CO8peSoHppKhbvfUgzH2kSt1M5Z7JuPMZn7KP9wO%2FLPH%2BAI3K7yCyjMnRMbDWifJhkT7rlk9G30v9n6fOTlL%2FFeDdRz%2BhzKNdJx6hPr%2BGXOCeAvkBGJpFK0onJh8SJ1p13Kr01vbjFhd5c22W3LsndzkyC7hYuUHJ41%2BprQFsx0aoeIfqsYIT4bKWQ6sCTWRYX3qV63STiAZ5mKXYfNzzB%2B%2B6zksae7nSp%2B82JyQr5%2FU4%2BDXVZepGsijXf%2FPAnXC8tjYYR1FXf2kLHqkVA%2B360RKoPx6kZSQ82G8A%2BA39pRfoJFzA9iZJI9QmgxWxYmXXGP66MBdiyVn0V6wSIOM2nAPZUJoBxDXrK3JOUHjDbJLFdSADjiRDZX2mONbmc3wdYnrARwM72SSrnafjBOI9xpZuzzBgwmjg8TucJ00mi3PRnwIzEMmAxi5jYwW6QOQBgxgJsLfmsMQZyV8iCbuaUMgVMYqhvnVNWSAWBH%2BwPMKx%2FY4yxDn7XwzyuYT8bMN5pWOtz9rXhAGYGAIw0UbMtZCQy32W2hjrPHjAQYx7eJWqOsIDLFTDZKTuJzf%2Fd4l9Qv32mgNnMU80NoaYlC8DOo0m27zIJjn%2BmY5AWMLlLuUH5K1eCC1gTmdkZDYl4h2UIGOe5Bu9Kd%2B0CXChjwJwvwD%2FpgAKYTRF6N5jUEXQw1FxwgZkAJpn4UsgebmXKy7MFjH1R%2F4ncIUdzEzDuRH1NBiZxNDjsAxipXUAVvWQGmIow4Yz2fakHO%2FuSNWCafeDJsQALpzm%2BdWqKaCoyBEzvsALWOZtjtOz%2BN33emVBFOoBxLds6DlRjZoAJ%2BQNGivOUZAqYuP8uRXTddOjSAbabD2Cb00b7HOG1eXJUiXRfeXk6C0xSETSjVE6WgBnGJKwTN3cOzZIqRtJoedYiL7C9R6abBDBSsZ4C5gelbiDAajgFYbanuIktwJrBNg3nSU4D2DkuYOKwHUWLhMdaZ7O%2FL3OYaPwQhQJv0MtTvDFP4qev%2FTw%2FIm%2Ft3o3l4vyOpopKE9P5HmMje968%2B2QXvujERm2Wc3CgZbs9AmE5POPAUxnn6UmTeO0L3iVWMBpjpl9ivCrdaIyB8FjiJH5%2F4053Ngj5O44rrJ9X5kBmQz6LZ%2BjSeP5ByAFsCOcoluIO55vaMLFYP3OukHtc3vs53rOJSUPt%2FASvjPJYcJlVHpXONGgGQmKkFG2uZDhGEyDXTDrvGWm1jXXaIk5YMEKi%2FxapK5Ls%2Bma0BHSKaELtDaBjKYiO%2BfbQtqjKyF2Rx3dInR8vypNq9ZlvAL0odThri%2Fv8V6Qb480jie8JfI%2F5DymggAL6A7%2FPpMSyS0OKAAAAAElFTkSuQmCC)
## **Software Development**
![Texas Instruments](https://img.shields.io/static/v1?label=Software&message=Code%20Composer%20Studio&color=red&logoWidth=30&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGwAAAAoCAYAAAAbrx%2B3AAAKYklEQVR42u1aA5B0ORDOzpvV%2FDNr2zv4bfNs27Zt27Zt27Zt2%2Fbd99V2159Lvdm9mdNs1euqrnlJOnlJf0mnu9%2BYgAIK6P%2BkyuLixqVqyjdyuWNIwTATUO7RmLLorNvHpn53eanqyk3N4KQAsDpjqhuKi5tNQLkPWMyYqmtHJT6%2FZUzyx2QkMsoElJuAnZDovH9Caem8tcbUALDPCFgqEhnXXFjYWRWJNKBrMTjPBJQbgJE3aK7dtypi6ieXRmePi8UmNxUWdmnbHWNTv142svedGeWxRU1uUAAYwdijq%2FlcPm%2FeUn%2F4zLLYEq7MkjXlG5j%2FlwLA9upquWTj5rpDY%2FD6LxjR8zLrFqgqX3FUNDqD9VeOjH%2BkskvXlG9o%2Fj8KALsNpo53lDocLLOed5d0KbppTPI7ld%2BgsW4vE9A%2FT3EEwhcM73nF5ctG9L5rA3bOsO7njNCkkpL5WXf1qPhHKIZYN7YsOtOWv3h4zxtRuP3Gn4rAZQMz90ZALuWfN6z7BVF0Wsbp%2BeHSEb3vTy%2BLLbZWY82urDu0p%2B36UbHiSayHx%2FiF22evzuYLfV%2BY711UUBD%2B7S%2FwNxAvcboH1BUtSF0xIv7%2BQKCROwoLew7qab2az%2Bs31e25RkP1Dulk9%2B1svtTndWXhsHdlKBTawvO8NcCrA8BbAc7v4M%2B1Du0b4vdUzzOrBAj5EF1znJR3%2BgPr%2BtGJL3hArhRwp5bHFjlEwBN2nJTmi%2FzMoRunhcOhfQgYgHvFqh4ip6uJvw5rrOfW50vfAqfes19njZGWZIyo9CXnHtHj6w%2BwUxKdD9cXFbXi%2BTc6HdVDTN3VI%2BMfppPfqrXhaDMw%2BQKGk7U46r4D%2F%2Boy5F6FSCFO4S4o%2FyT176NO02RtKH8B%2FhZj74lyufWuvfvGCD0loDtzMXMw%2Fr2Q%2BQH8C%2Fjr%2FPzwC8yHmxykostHznU2bh2b%2FOWSEb1vESCWj4i33co1NWLy2PYV7MC01LbtDcc4YP12WrLzEToi2QJGolJZD2B2oK8DngyFzgtTeTJ%2Fpe8BYk5%2FQDFlgf0rfpdwTw2BFYB%2FxxiznfZR3AD5Ye82PA8FV4Mn4H2ng9c1uUjzVZQucxuAgvn7amQsNoV1K9VXbUkgLkTs5bcrj%2Bxtv0XBOry37QamqlyZLAF7gvV4nOrTLaJi6HeH9H%2BAjq%2FchSc68gRy%2BXA4%2FDbb%2BgDzLrPbsTF27KsPHenzvpZcdkKSbUVFbVZV3inJrgcJyBr1tTvRHIE9OiBrN9bucuuY1E83jU5%2Bt2h15RoK6D8JGBS9GIp1wuNwMtyTWw%2B59%2BSkfQET9iLvQOMQgQUou3EMkf0Zz61zAfVWZr3M5WGaXFSPHpS50VllZYvrKboZATIA%2BkbLAOznqRUlC6jsPw2YwwRwZZ9hZqipg6K39mlPidlsIAAY%2Bxk5TfvbJhOn7mr3fZB9jLkEM8gohOD5WT%2FnYtOWhoMo8G8BRjcfxeFkgLUIeCHjEEDayFLyZ64J87zQ0bwT0XdZMs0hZQsLwx87HmMeTzDl6WxIPChygyuQ5%2F22vA9gv7UUFXW4sv%2F2HebQaMh9D2BPgZKflbFut9zxqHiNn6L9Y2U9kei3pshVOOPmycn9RpyUWWaQUR6yG9e6OUY6AP8yYNN8uk3RQBz9Xobs0zKPBPp8pd6lnL4N4Gy8o3GaEgN4MXmPcG0oX0xP1D28HF%2FmkTKDjBjQlB4bb7%2FDBg1BT9xkT7zsT%2BpTXPhDFi1FvS5A3gs%2BT%2Fh88D18pvMDJV8iyhxvmcetxTT%2BCPO3INzIN2jifN67EuXk9MyPfpvz1NGtxyY6kDGb5YGeZXKEGnhHgNcg04P6K4diydqKdQ%2FtbbuR%2BURx%2F7OlEVDmKRLrgM0i4oKvKHW%2BDAXPB4XuoWWaLp0bFL%2B7JXsafyF7kGsJILfpXLnQMagahrqd%2BAyAbgPfDT4Xc1mO4iZXCBM8WXba15KOCSiHiTttVwImdn4QUgBYBczEqmQfD61T2xzzOR7jbMfcXZ%2BJNQtLfULkfVlSTtN82lYR971KxillYKvtmpoSClOe9WK%2BelROTKUvMYUlfZah08FMSD%2FzHA0u4hzsPvbVorKS8hozwLqHWX2T0N2W0N1e%2BF1f1h3NADBOPnS8fXFLvaaC7pLkaQxcgPKFjFfoUrON6R9xBHpRPoNj0KGg6y1j%2FoLyB5JYfZ4ZDD6zDYO%2FBUfiDoz%2FqLjd32N%2Bm6m3J%2F0%2FJ5CO8peSoHppKhbvfUgzH2kSt1M5Z7JuPMZn7KP9wO%2FLPH%2BAI3K7yCyjMnRMbDWifJhkT7rlk9G30v9n6fOTlL%2FFeDdRz%2BhzKNdJx6hPr%2BGXOCeAvkBGJpFK0onJh8SJ1p13Kr01vbjFhd5c22W3LsndzkyC7hYuUHJ41%2BprQFsx0aoeIfqsYIT4bKWQ6sCTWRYX3qV63STiAZ5mKXYfNzzB%2B%2B6zksae7nSp%2B82JyQr5%2FU4%2BDXVZepGsijXf%2FPAnXC8tjYYR1FXf2kLHqkVA%2B360RKoPx6kZSQ82G8A%2BA39pRfoJFzA9iZJI9QmgxWxYmXXGP66MBdiyVn0V6wSIOM2nAPZUJoBxDXrK3JOUHjDbJLFdSADjiRDZX2mONbmc3wdYnrARwM72SSrnafjBOI9xpZuzzBgwmjg8TucJ00mi3PRnwIzEMmAxi5jYwW6QOQBgxgJsLfmsMQZyV8iCbuaUMgVMYqhvnVNWSAWBH%2BwPMKx%2FY4yxDn7XwzyuYT8bMN5pWOtz9rXhAGYGAIw0UbMtZCQy32W2hjrPHjAQYx7eJWqOsIDLFTDZKTuJzf%2Fd4l9Qv32mgNnMU80NoaYlC8DOo0m27zIJjn%2BmY5AWMLlLuUH5K1eCC1gTmdkZDYl4h2UIGOe5Bu9Kd%2B0CXChjwJwvwD%2FpgAKYTRF6N5jUEXQw1FxwgZkAJpn4UsgebmXKy7MFjH1R%2F4ncIUdzEzDuRH1NBiZxNDjsAxipXUAVvWQGmIow4Yz2fakHO%2FuSNWCafeDJsQALpzm%2BdWqKaCoyBEzvsALWOZtjtOz%2BN33emVBFOoBxLds6DlRjZoAJ%2BQNGivOUZAqYuP8uRXTddOjSAbabD2Cb00b7HOG1eXJUiXRfeXk6C0xSETSjVE6WgBnGJKwTN3cOzZIqRtJoedYiL7C9R6abBDBSsZ4C5gelbiDAajgFYbanuIktwJrBNg3nSU4D2DkuYOKwHUWLhMdaZ7O%2FL3OYaPwQhQJv0MtTvDFP4qev%2FTw%2FIm%2Ft3o3l4vyOpopKE9P5HmMje968%2B2QXvujERm2Wc3CgZbs9AmE5POPAUxnn6UmTeO0L3iVWMBpjpl9ivCrdaIyB8FjiJH5%2F4053Ngj5O44rrJ9X5kBmQz6LZ%2BjSeP5ByAFsCOcoluIO55vaMLFYP3OukHtc3vs53rOJSUPt%2FASvjPJYcJlVHpXONGgGQmKkFG2uZDhGEyDXTDrvGWm1jXXaIk5YMEKi%2FxapK5Ls%2Bma0BHSKaELtDaBjKYiO%2BfbQtqjKyF2Rx3dInR8vypNq9ZlvAL0odThri%2Fv8V6Qb480jie8JfI%2F5DymggAL6A7%2FPpMSyS0OKAAAAAElFTkSuQmCC)


## **License**
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## **Version**
[![Version Release](https://img.shields.io/github/v/release/jminjares4/MSP432-Example-Codes?include_prereleases)](https://github.com/jminjares4/MSP432-Example-Codes/releases/tag/v1.0.0)

## **Authors:**
  - [Jesus Minjares](https://github.com/jminjares4) :zap:
    - Master of Science in Computer Engineering
  - [Jorge Minjares](https://github.com/JorgeMinjares) :zap:
    - Bachelor of Science in Electrical Engineering

### Special Message
 ~~~c
 printf("Go Miners!\n");
 ~~~