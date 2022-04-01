#include "main.h"
#include "GPIO.h"
#include "SysConfig.h"
#include "LCD.h"
#include "Timer.h"

extern TIM_HandleTypeDef Tim3;

int main(void)
{
	HAL_Init();
	SysConfigClock();
	Gpio_Led_Init();
	Timer_Init(150);
	HAL_TIM_Base_Start_IT(&Tim3);
	while(1)
	{

	}
	return 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM3)
	{
		Gpio_Led_Toggle();
	}
}

