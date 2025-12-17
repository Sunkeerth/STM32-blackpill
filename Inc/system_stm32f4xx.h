#ifndef SYSTEM_STM32F4XX_H
#define SYSTEM_STM32F4XX_H

#include <stdint.h>
#include "stm32f411xe.h"

extern uint32_t SystemCoreClock;

void SystemInit(void);
void SystemCoreClockUpdate(void);

#endif
