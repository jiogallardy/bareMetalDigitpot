/**
 * @file Hal.h
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HAL_H
#define HAL_H

#include "Generic.h"

#define FREQ 132000000 // the given CPU frequency, 132 MHz
#define SystemCoreClock FREQ

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)

/**
 * @brief Delay by amount count
 * 
 * @param count 
 */
static inline void Spin(volatile u32 count) {
  while (count--)
    (void) 0;
}

struct systick {
  volatile u32 CTRL, LOAD, VAL, CALIB;
};
#define SYSTICK ((struct systick *)0xe000e010)

// By default GPIO's are not enabled so we must enable them
struct rcc {
  volatile u32 CR, PLLCFGR, CFGR, CIR, AHB1RSTR, AHB2RSTR, AHB3RSTR, RESERVED0,
      APB1RSTR, APB2RSTR, RESERVED1[2], AHB1ENR, AHB2ENR, AHB3ENR, RESERVED2,
      APB1ENR, APB2ENR, RESERVED3[2], AHB1LPENR, AHB2LPENR, AHB3LPENR,
      RESERVED4, APB1LPENR, APB2LPENR, RESERVED5[2], BDCR, CSR, RESERVED6[2],
      SSCGR, PLLI2SCFGR;
};
// As per 7.3.10 of datasheet
#define RCC ((struct rcc *)0x40023800)

/**
 * @brief ctrl disables/enables systick, load loads the inital counter value, val the current counter value, is clocked via RCC->APB2ENR
 * 
 * @param ticks 
 */
static inline void SystickInit(u32 ticks) {
  if ((ticks - 1) > 0xffffff)
    return; 
  SYSTICK->LOAD = ticks - 1;
  SYSTICK->VAL = 0;
  SYSTICK->CTRL = BIT(0) | BIT(1) | BIT(2); 
  RCC->APB2ENR |= BIT(14);                  
}

struct gpio {
  volatile u32 MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2];
};

// Given register for the GPIO's plus offset 
#define GPIO(bank) ((struct gpio *)(0x40020000 + 0x400 * (bank)))

// Available modes from datasheet ie 0, 1, 2, 3
enum {GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG};

/**
 * @brief Sets the gpio mode to a value 
 * 
 * @param pin 
 * @param mode 
 */
static inline void GpioSetMode(u16 pin, u8 mode) {
  struct gpio *gpio = GPIO(PINBANK(pin)); // GPIO bank
  int n = PINNO(pin);                     // Pin number
  RCC->AHB1ENR |= BIT(PINBANK(pin));      // Enable GPIO clock
  gpio->MODER &= ~(3U << (n * 2));        // Clear existing setting
  gpio->MODER |= (mode & 3U) << (n * 2);  // Set new mode
}

/**
 * @brief Writes a high or low to a given gpio pin
 * 
 * @param pin 
 * @param val 
 */
static inline void GpioWrite(u16 pin, bool val) {
  struct gpio *gpio = GPIO(PINBANK(pin));
  gpio->BSRR = (1U << PINNO(pin)) << (val ? 0 : 16);
}

#endif // HAL_H
