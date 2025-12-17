#ifndef STM32F411XE_H
#define STM32F411XE_H

#include <stdint.h>

/* ================= NVIC ================= */
#define NVIC_ISER0      (*(volatile uint32_t *)0xE000E100UL)
#define NVIC_ENABLE_IRQ(n) (NVIC_ISER0 = (1U << (n)))

/* ================= Base Addresses ================= */
#define PERIPH_BASE        0x40000000UL
#define AHB1PERIPH_BASE    (PERIPH_BASE + 0x00020000UL)
#define APB1PERIPH_BASE    (PERIPH_BASE + 0x00000000UL)
#define APB2PERIPH_BASE    (PERIPH_BASE + 0x00010000UL)

/* ================= RCC ================= */
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t RESERVED0[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t RESERVED2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
} RCC_TypeDef;

#define RCC_BASE (AHB1PERIPH_BASE + 0x3800UL)
#define RCC ((RCC_TypeDef *)RCC_BASE)

/* RCC bits */
#define RCC_CR_HSION              (1U << 0)
#define RCC_CR_HSIRDY             (1U << 1)
#define RCC_AHB1ENR_GPIOAEN       (1U << 0)
#define RCC_AHB1ENR_DMA2EN        (1U << 22)
#define RCC_APB1ENR_TIM2EN        (1U << 0)
#define RCC_APB1ENR_USART2EN      (1U << 17)
#define RCC_APB2ENR_ADC1EN        (1U << 8)

/* ================= GPIO ================= */
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
} GPIO_TypeDef;

#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)

/* ================= TIM ================= */
typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
} TIM_TypeDef;

#define TIM2_BASE (APB1PERIPH_BASE + 0x0000UL)
#define TIM2 ((TIM_TypeDef *)TIM2_BASE)

#define TIM_CR1_CEN        (1U << 0)
#define TIM_CR2_MMS_1      (1U << 5)

/* ================= ADC ================= */
typedef struct {
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    uint32_t RESERVED1[2];
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t DR;
} ADC_TypeDef;

#define ADC1_BASE (APB2PERIPH_BASE + 0x2000UL)
#define ADC1 ((ADC_TypeDef *)ADC1_BASE)

/* ADC bits */
#define ADC_CR2_ADON        (1U << 0)
#define ADC_CR2_DMA         (1U << 8)
#define ADC_CR2_DDS         (1U << 9)
#define ADC_CR2_EXTEN_0     (1U << 28)
#define ADC_CR2_EXTSEL_Pos  24
#define ADC_SMPR2_SMP0      (7U << 0)

/* ================= DMA ================= */
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t NDTR;
    volatile uint32_t PAR;
    volatile uint32_t M0AR;
    volatile uint32_t M1AR;
    volatile uint32_t FCR;
} DMA_Stream_TypeDef;

typedef struct {
    volatile uint32_t LISR;
    volatile uint32_t HISR;
    volatile uint32_t LIFCR;
    volatile uint32_t HIFCR;
} DMA_TypeDef;

#define DMA2_BASE (AHB1PERIPH_BASE + 0x6400UL)
#define DMA2 ((DMA_TypeDef *)DMA2_BASE)
#define DMA2_Stream0 ((DMA_Stream_TypeDef *)(DMA2_BASE + 0x10UL))

/* DMA bits */
#define DMA_SxCR_EN         (1U << 0)
#define DMA_SxCR_TCIE       (1U << 4)
#define DMA_SxCR_CIRC       (1U << 8)
#define DMA_SxCR_MINC       (1U << 10)
#define DMA_SxCR_PSIZE_0    (1U << 11)
#define DMA_SxCR_MSIZE_0    (1U << 13)

#define DMA_LISR_TCIF0      (1U << 5)
#define DMA_LIFCR_CTCIF0    (1U << 5)

/* ================= USART ================= */
typedef struct {
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
} USART_TypeDef;

#define USART2_BASE (APB1PERIPH_BASE + 0x4400UL)
#define USART2 ((USART_TypeDef *)USART2_BASE)

/* USART bits */
#define USART_CR1_UE        (1U << 13)
#define USART_CR1_TE        (1U << 3)
#define USART_SR_TXE        (1U << 7)

/* ================= IRQ ================= */
#define DMA2_Stream0_IRQn   56

#endif /* STM32F411XE_H */
