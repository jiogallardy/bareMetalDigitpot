/**
 * @file Periodic.c
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Periodic.h"

static PeriodicHandlerT g_periodicHandler =
    NULL; // Global variable to hold the callback function

/**
 * @brief Initialization of the module 
 * 
 */
void PeriodicModuleInit(void) {

  // Set a default frequency
  u32 defaultFrequency = 1000;
  // Calculate ticks
  u32 ticks = SystemCoreClock / defaultFrequency - 1;
  // Call hardware setup
  SystickInit(ticks); 
}

/**
 * @brief Utility function for initializing the clock to the desired tick
 * 
 * @param FreqHz 
 * @param Handler 
 */
void PeriodicConfig(f32 FreqHz, PeriodicHandlerT Handler) {
  u32 ticks = SystemCoreClock / FreqHz - 1;
  if (ticks > 0xFFFFFF) {
    ticks = 0xFFFFFF; // Maximum value for SysTick LOAD register
  }

  SysTick->LOAD = ticks;
  SysTick->VAL = 0;

  // Handler attachment
  g_periodicHandler = Handler;

  // Enable SysTick IRQ and SysTick Timer
  SysTick->CTRL = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;
  
  PeriodicStop(); // Start with the timer stopped
}

/**
 * @brief Starts SysTick and resets SysTick->VAL
 *
 */
void PeriodicStart(void) {
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/**
 * @brief Disables SysTick
 *
 */
void PeriodicStop(void) { SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; }

/**
 * @brief Enable the SysTick interrupt
 *
 */
void PeriodicIruptEnable(void) { SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk; }

/**
 * @brief Disable the SysTick interrupt
 *
 */
void PeriodicIruptDisable(void) { SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk; }

/**
 * @brief Not used, but would be a metehod to clear the interrupt flag
 * 
 */
void PeriodicIruptFlagClear(void) {
  // Not applicable for SysTick as the count flag is cleared by reading the CTRL
  // register
}

/**
 * @brief Calculate the time it takes for the function to complete
 * 
 * @param operation 
 * @param time_limit 
 */
void ExecuteAndMeasure(void (*operation)(void), u32 time_limit) {
  MeasureResult result; 
  u32 start_time = s_ticks;
  result.status = operation(); // Call the function in this case the set resistance function
  result.on_time = False; // default to false
  u32 elapsed_time = s_ticks - start_time;

  if (elapsed_time > time_limit) {
    printf("Operation exceeded time limit of %lu ms, taking %lu ms\n",
           time_limit, elapsed_time);
           result.on_time = False; 
  } else {
    printf("Operation completed within the time limit: %lu ms\n", elapsed_time);
    result.on_time = True; 
  }
  return result; 
}
