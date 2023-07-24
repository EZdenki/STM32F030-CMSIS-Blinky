# STM32F030-CMSIS-Blinky
### Minimalist Blinky for for STM32F030 Using Only CMSIS.
This project can be used as a sanity check to check the toolchain used to program the STM32F030. And all of the files in this project
directory can be used as-is as a template for new projects. All that needs to be updated is main.c.
### Hardware Setup
```
                                       STM32F030F4xx
                                         ____  ____
                                        |1   \/  20| --- SWCLK *
                                        |2       19| --- SWDIO *
                                        |3       18|
                                        |4       17|
                                        |5       16| --- VCC   * (3.3 V)
  [GND]---[1k resistor]---[- LED +] --- |6       15| --- GND   *
                                        |7       14|
                                        |8       13|
                                        |9       13|
                                        |10      11|
                                        ------------
                                * ST-Link V2 Programming Dongle
```

