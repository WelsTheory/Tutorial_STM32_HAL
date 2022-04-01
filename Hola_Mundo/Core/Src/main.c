#include "main.h"
#include "GPIO.h"
#include "SysConfig.h"

int main(void)
{
	HAL_Init();
	SysConfigClock();
	Gpio_Led_Init();
	while(1)
	{
		Gpio_Led2_Write(Gpio_But2_Read());
		Gpio_Led_Write(Gpio_But_Read());
		HAL_Delay(100);
	}
	return 0;
}





