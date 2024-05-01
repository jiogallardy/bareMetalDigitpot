/**
 * @file main.c
 * @author Jio Gallardy  (jiogallardy@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Digipot.h"
#include "Hal.h"
#include "Pin.h"
#include "Periodic.h"
#include "Generic.h"

static volatile u32 s_ticks;

void SysTick_Handler(void) { s_ticks++; }

void SetResistanceA(void) { SetResistance('A', 5000); }
void SetResistanceB(void) { SetResistance('B', 3000); }

int main(void) {

  u16 Frequency = 1000;

  // We want it to tick at 1ms
  PeriodicModuleInit();
  PeriodicConfig(Frequency, SysTick_Handler); 
  PeriodicStart();

  // Measure the time it takes to run the set resistance for each channel
  MeasureResult result_A = ExecuteAndMeasure(SetResistanceA, 40);
  if (result_A.status != 0) {
      printf("Failed to set resistance for channel A with error code: %d\n", result_A.status);
  }
  if (!result_A.on_time) {
      printf("Operation for channel A exceeded time limit.\n");
  }

  MeasureResult result_B = ExecuteAndMeasure(SetResistanceB, 40);
  if (result_B.status != 0) {
      printf("Failed to set resistance for channel B with error code: %d\n", result_B.status);
  }
  if (!result_B.on_time) {
      printf("Operation for channel B exceeded time limit.\n");
  }
  
  return 0;
}


// Startup code
__attribute__((naked, noreturn)) void _reset(void) {
  // Initialize memory
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

  main();
  for (;;) (void) 0;  // Infinite loop
}

extern void _estack(void);  // Defined in stm32.ld

// 16 standard and 91 STM32-specific handlers
// Note the attachment of systick handler here in the vector table
__attribute__((section(".vectors"))) void (*const tab[16 + 91])(void) = {
    _estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SysTick_Handler};