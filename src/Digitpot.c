/**
 * @file Digitpot.c
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-30
 *
 * @copyright Copyright (c) 2024 All rights reserved
 *
 */

#include "Digitpot.h"
#include "Generic.h"
#include "Hal.h"
#include "Pin.h"
#include <stdio.h>

// Default values for wiper channels once powered on
static u16 current_wiper_A = 128;
static u16 current_wiper_B = 128;

/**
 * @brief Spin inline function
 *
 * @param count
 */
static inline void Spin(volatile u32 count) {
  while (count--) {
    ;
  }
}
/**
 * @brief Activate a Chip Select
 *
 * @param cs_pin The pin to select for chip select, in this case either CSA or CSB, by activating you are telling the chip signals are going to be sent
 */
static void SelectChannel(PinT cs_pin) {
  PinWrite(cs_pin, False); // Active low
}

/**
 * @brief Deselect a channel
 *
 * @param cs_pin The pin to deselect for chip select, in this case either CSA or CSB, needs to be called after SelectChannel
 */
static void DeselectChannel(PinT cs_pin) {
  PinWrite(cs_pin, True); // Inactive high
}

/**
 * @brief Set the direction object
 *
 * @param ud_pin Register up down control input pin
 * @param increment Set to true to increment, false to decrement
 */
static void SetDirection(PinT ud_pin, bool increment) {
  PinWrite(ud_pin, increment);
}

/**
 * @brief Increment or decrement the pin, once SelectChannel() and SetDirection() have been called
 *
 * @param inc_pin
 */
static void PulseIncrement(PinT inc_pin) {
  PinWrite(inc_pin, True);
  Spin(10); // Short delay
  PinWrite(inc_pin, False);
  Spin(5); // Small delay again
}

/**
 * @brief Helper method to find the tap position based on given
 * resistance (should be static, not for unit test example)
 *
 * @param desired_resistance Used to calculate tap position
 * @param max_resistance Used as reference to calculate tap position
 * @return Returns needed tap position for potentieometer to be set to desired resistance
 */
u8 CalculateTapPosition(u32 desired_resistance, u32 max_resistance) {

  if (desired_resistance > max_resistance) {
    desired_resistance = max_resistance;
  }
  return (u8)((desired_resistance * 255) / max_resistance);
}

/**
 * @brief Set the resistance for the given channel
 *
 * @param channel The channel of the Digitpot either 'A' or 'B', to have the resistance set
 * @param desired_resistance The desired resistance to be set of the channel selected
 */
s8 SetResistance(char channel, u32 desired_resistance) {

  u16 *current_position;
  PinT cs_pin, ud_pin, inc_pin;
  u32 max_resistance =
      MAX_RESISTANCE_10K; // Default to 10K if not set otherwise

  switch (channel) {
  case 'A': 
    current_position = &current_wiper_A;
    max_resistance =
        MAX_RESISTANCE_10K; // Note that this is hard coded for 10k Ohm resistor
    cs_pin = PinCSA;
    ud_pin = PinUDA;
    inc_pin = PinINCA;
    break;
  
  case 'B': 
    current_position = &current_wiper_B;
    max_resistance =
        MAX_RESISTANCE_10K; // Note that this is hard coded for 10k Ohm resistor
    cs_pin = PinCSB;
    ud_pin = PinUDB;
    inc_pin = PinINCB;
    break;
  
  default: 
    printf("Incorrect channel selected, or not available\n");
    return 1;
  
  }

    u8 desired_position =
        CalculateTapPosition(desired_resistance, max_resistance);
    if (desired_position > MAX_TAP_POSITION) {
      desired_position = MAX_TAP_POSITION;
    }

    // Chip select the channel we want to change
    SelectChannel(cs_pin);
    // Determine if we are incrementing or decrementing
    bool increment = (*current_position < desired_position);
    SetDirection(ud_pin, increment);

    while (*current_position != desired_position) {
      PulseIncrement(inc_pin);
      if (increment) {
        (*current_position)++;
      } else {
        (*current_position)--;
      }
    }
    // Remove channel select
    DeselectChannel(cs_pin);
    return 0;
  }
