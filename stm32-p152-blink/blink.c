/*
 *
 */

#include <stdint.h>

#define REG32(addr) (*(volatile uint32_t *)(addr))

#define GPIOE_BASE   0x40021000
#define GPIOE_MODER  REG32(GPIOE_BASE + 0x00)
#define GPIOE_OTYPER REG32(GPIOE_BASE + 0x04)
#define GPIOE_ODR    REG32(GPIOE_BASE + 0x14)

#define RCC_BASE 0x40023800
#define RCC_AHBENR REG32(RCC_BASE + 0x1C)
#define RCC_AHBENR_GPIOEEN 0x10

#define STAT4_PIN 11
#define STAT4_PIN_MASK (1UL<<STAT4_PIN)

static
void delay(int nops)
{
    while(nops > 0)
    {
        asm ("nop");
        nops--;
    }
}

static
void set_gpioe_moder(int pin, int mode)
{
    uint32_t moder;
    uint32_t moder_pin_pos;
    uint32_t moder_pin_mask;

    moder_pin_pos = pin*2; // 2 bits per pin
    moder_pin_mask = 0x3UL << moder_pin_pos;

    moder = GPIOE_MODER; // read from register
    moder &= ~moder_pin_mask; // clear moder pin field
    moder |= (mode << moder_pin_pos); // set moder pin field
    GPIOE_MODER = moder; // write to register
}

void main(void)
{
    RCC_AHBENR |= RCC_AHBENR_GPIOEEN; // enable GPIOE clock
    GPIOE_OTYPER |= STAT4_PIN_MASK; // open-drain
    set_gpioe_moder(STAT4_PIN, 1); // general purpose output
    while(1)
    {
        GPIOE_ODR |= STAT4_PIN_MASK; // output pin low -> LED ON
        delay(100000);
        GPIOE_ODR &= ~STAT4_PIN_MASK; // output pin high-z -> LED OFF
        delay(100000);
    }
}

#define RCC_CR REG32(RCC_BASE + 0x00)
#define RCC_CR_HSION 0x1
#define RCC_CR_HSIRDY 0x2
#define RCC_CFGR REG32(RCC_BASE + 0x08)
#define RCC_CFGR_SW 0x3
#define RCC_CFGR_SW_HSI 0x1

void SystemInit(void)
{
    uint32_t cfgr;

    RCC_CR |= RCC_CR_HSION; // Enable High Speed Internal clock
    while(!(RCC_CR & RCC_CR_HSIRDY)) // Wait for HSI ready
    {
        delay(10);
    }
    cfgr = RCC_CFGR;
    cfgr &= ~RCC_CFGR_SW;
    cfgr |= RCC_CFGR_SW_HSI; // Select HSI as system clock
    RCC_CFGR = cfgr;
    while((RCC_CFGR & RCC_CFGR_SW) != RCC_CFGR_SW_HSI) // Wait for HSI as system clock
    {
        delay(10);
    }
}

void _exit(int code)
{
    while(1);
}

