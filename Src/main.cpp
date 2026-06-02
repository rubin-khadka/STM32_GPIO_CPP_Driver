
#include "stm32f101xb.h"
#include <stdint.h>

int main(void)
{
	// Enable GPIOC clock
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	// Configure PC13 as push pull output, 2MHz
	GPIOC->CRH &= ~(0xFUL << 20);
	GPIOC->CRH |= (0x2UL << 20);

	while(1)
	{
		// Set pin 13 as high
		GPIOC->BSRR = (1UL << 13);
		for (volatile uint32_t i = 0; i < 500000; i++)
			__NOP();

		// Set pin 12 as low
		GPIOC->BSRR = (1UL << (13+16));
		for (volatile uint32_t i = 0; i < 500000; i++)
			__NOP();
	}
}
