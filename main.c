//  ==========================================================================================
//  main.c
//  ------------------------------------------------------------------------------------------
//  Minimalist Blinky with only CMSIS (no HAL)
//  ------------------------------------------------------------------------------------------
//  https://github.com/EZdenki/STM32F030-CMSIS-Blinky
//  Released under the MIT License
//  Copyright (c) 2023
//  Mike Shegedin, EZdenki.com
//  Version 1.0   Jul 2023    Started
//  ------------------------------------------------------------------------------------------
//  Target Microcontroller and Devices:
//    STM32F030Fxxx
//  ------------------------------------------------------------------------------------------
//  Hardware Setup:
//    Wire an LED and 1k resistor between pin 6 and ground.
//    Connect the four pins from the ST-Link V2 as shown below:
//
//                                                            ST-Link V2 
//                                    STM32F030F4xx           ╭───────╮     
//                                     ╭────╮╭────╮           │    GND├───────╮
//                               BOOT0 │1       20│ SWCLK ────┤SWCLK  │       │
//                                 PF0 │2       19│ SWCLK ────┤SWDIO  │       │
//                                 PF1 │3       18│ PA10      │   3.3V├───╮   │
//                                NRST │4       17│ PA9       ╰───────╯   │   │
//                                VDDA │5       16│ VCC ──────── VCC ─────╯   │
//    GND ─── [1K] ─── [-LED+] ─── PA0 │6       15│ GND ──────── GND ─────────╯
//                                 PA1 │7       14│ PB1
//                                 PA2 │8       13│ PA7
//                                 PA3 │9       12│ PA6
//                                 PA4 │10      11│ PA5
//                                     ╰──────────╯
//
//  ==========================================================================================

#include "stm32f030x6.h"

int
main( void )
{
  // ====================
  // Setup GPIO A pin PA0
  // ====================

  // 1. Enable GPIO Port A by setting the GPIOAEN bit in the RCC AHBENR register
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 

  // 2. Set MODER0[1:0] bits in the GPIOA MODER register to 0b01 to make pin PA0 function as
  // an output.
  GPIOA->MODER |= ( 0b01 << GPIO_MODER_MODER0_Pos );

  // Endless Loop
  while( 1 )
  {
    // Flip the outpout bit for PA0 in the GPIOA ODR register.
    GPIOA->ODR ^= GPIO_ODR_0;

    // Half-second delay:
    // There are about 13 instructions executed for each cycle of the for loop. We need to
    // burn 4 million cycles to make 0.5 seconds, therefore:
    // 4E6 (0.5 second) cycles / 13 = 307,692 for-loop cycles should equal about 0.5 seconds.
    for( uint32_t x=0; x<308e3; x++) ;
  }
}
