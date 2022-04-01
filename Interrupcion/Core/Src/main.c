#include "main.h"
#include "GPIO.h"
#include "SysConfig.h"
#include "INT.h"

uint32_t __IO flag = 0;

int main(void)
{
	HAL_Init();
	SysConfigClock();
	Gpio_Led_Init();
	INT_Init();
	while(1)
	{
		if(flag == 1)
		{
			Gpio_Led_Toggle();
			EXTI->IMR |= (1UL<<13);
			flag = 0;
		}
	}
	return 0;
}


// HANDLER
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_13)
	{
		flag = 1;
		EXTI->IMR &= ~(1UL<<13);
	}
}


