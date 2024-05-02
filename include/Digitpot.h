/**
 * @file Digitpot.h
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-30
 *
 * @copyright Copyright (c) 2024 All rights reserved
 *
 */

#ifndef DIGITPOT_H
#define DIGITPOT_H

#include "Generic.h"
#include "Pin.h"

#define MAX_RESISTANCE_10K 10000
#define MAX_TAP_POSITION 255

/**
 * @brief Set the resistance object
 *
 * @param channel  'A' for channel CSA, and 'B' for channel CSB
 * @param desired_resistance the desired resistance
 * @return Returns a code 0 for success, 1 for errors
 */
s8 SetResistance(char channel, u32 desired_resistance);

/**
 * @brief Calculate tap position
 * @param desired_resistance The desired resistance to return a count for
 * @param max_resistance The max resistance the desired is based on
 * @return Returns the tap position of the desired resistance based on max resistance
 */
u8 CalculateTapPosition(u32 desired_resistance, u32 max_resistance);

#endif // DIGITPOT_H