/**
 * @file test_Digitpot.c
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024 All rights reserved
 * 
 */

#include "unity.h"
#include "Digitpot.h"
#include "mock_Pin.h"

void setUp(void) {
}

void tearDown(void) {
}

/**
 * @brief Function on line 68, testing branch at 71
 * 
 */
void test_CalculateTapPosition_desired_greater_than_max(void) {

    // Arrange
    u32 desired_resistance = 15000; 
    u32 max_resistance = 10000; 

    // Act
    u8 result = CalculateTapPosition(desired_resistance, max_resistance);

    // Assert
    TEST_ASSERT_EQUAL(255, result); 
}

/**
 * @brief Function on line 68, testing main branch of code
 * 
 */
void test_CalculateTapPosition_main_branch(void) {

    // Arrange
    u32 desired_resistance = 5000; 
    u32 max_resistance = 10000; 

    // Act
    u8 result = CalculateTapPosition(desired_resistance, max_resistance);

    // Assert
    TEST_ASSERT_EQUAL(127, result); 
}