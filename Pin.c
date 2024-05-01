/**
 * @file Pin.c
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Pin.h"
#include "Hal.h"

static const u16 pinMappings[PinQuan] = {
    [PinCSA] = PIN('A', 1), [PinCSB] = PIN('A', 14),  [PinUDA] = PIN('A', 2),
    [PinUDB] = PIN('A', 3), [PinINCA] = PIN('A', 13), [PinINCB] = PIN('A', 12)};

/**
 * @brief Set up pin mode per pin, default is that they are all output modes
 *
 */
void PinModuleInit(void) {
  for (int i = 0; i < PinQuan; i++) {
    GpioSetMode(pinMappings[i], GPIO_MODE_OUTPUT);
  }
}

/**
 * @brief Write to the pin
 *
 * @param pin
 * @param value
 */
void PinWrite(PinT pin, bool value) { GpioWrite(PIN(PIN_BANK, pin), value); }
