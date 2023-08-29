# STM32F030-CMSIS-Blinky
### Minimalist Blinky for for STM32F030 Using Only CMSIS.
This project can be used as a sanity check to check the toolchain used to program the STM32F030. And all of the files in this project
directory can be used as-is as a template for new projects. All that needs to be updated is main.c.
### Hardware Setup
1. Wire an LED and 1k resistor between pin 6 and ground.
2. Connect the four pins from the ST-Link V2 as shown below:
```
                                                            ST-Link V2 
                                    STM32F030F4xx           ╭───────╮     
                                     ╭────╮╭────╮           |    GND├───────╮
                               BOOT0 │1       20│ SWCLK ────┤SWCLK  |       |
                                 PF0 │2       19│ SWCLK ────┤SWDIO  |       |
                                 PF1 │3       18│ PA10      |   3.3V├───╮   |
                                NRST │4       17│ PA9       ╰───────╯   |   |
                                VDDA │5       16│ VCC ──────── VCC ─────╯   |
    GND ─── [1K] ─── [-LED+] ─── PA0 │6       15│ GND ──────── GND ─────────╯
                                 PA1 │7       14│ PB1
                                 PA2 │8       13│ PA7
                                 PA3 │9       12│ PA6
                                 PA4 │10      11│ PA5
                                     ╰──────────╯
```
