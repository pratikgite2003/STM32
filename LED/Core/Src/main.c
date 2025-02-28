

#include "stm32f407xx.h"

void delay(void);

int main(void)
{
    // ENABLE CLOCK TO PORT D
    RCC->AHB1ENR |= (1U << 3);  // Enable GPIOD clock

    // Set GPIOD pin 13 as output (01 in MODER)
    GPIOD->MODER &= ~(3U << (13 * 2));  // Clear MODER bits for pin 13


    GPIOD->MODER |= (1U << (13 * 2));   // Set pin 13 as output

    while(1)
    {
        GPIOD->ODR ^= (1U << 13);    // Toggle LED
        delay();
    }

    return 0;
}

void delay(void)
{
    for ( int i = 0; i < 500000; i++); // Simple delay
}
