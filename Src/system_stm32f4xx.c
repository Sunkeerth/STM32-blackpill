#include "system_stm32f4xx.h"

/* System clock frequency */
uint32_t SystemCoreClock = 16000000U;

/*
 * SystemInit
 * Called automatically from startup file.
 * We keep the default HSI = 16 MHz.
 */
void SystemInit(void)
{
    /* Enable HSI */
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));

    /* No PLL, no HSE, no CFGR, no SCB */
}

/*
 * Update SystemCoreClock
 * Minimal implementation
 */
void SystemCoreClockUpdate(void)
{
    SystemCoreClock = 16000000U;
}
