/*
 * Timer.c
 *
 *  Created on: Apr 1, 2022
 *      Author: Wels
 */
#include "Timer.h"

TIM_HandleTypeDef Tim3;

bool Timer_Init(uint32_t periodo)
{
	// CLOCK
	__HAL_RCC_TIM3_CLK_ENABLE();

	Tim3.Instance = TIM3;
	Tim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	Tim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;//84MHz
	Tim3.Init.Period = 8400-1;//8399
	Tim3.Init.Prescaler = (periodo*10) - 1;//100uS 0.1ms
	Tim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	Tim3.Init.RepetitionCounter = 0;
	if(HAL_TIM_Base_Init(&Tim3)!= HAL_OK)
	{
		return false;
	}

	TIM_ClockConfigTypeDef TimClock = {0};
	TimClock.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if(HAL_TIM_ConfigClockSource(&Tim3, &TimClock) != HAL_OK)
	{
		return false;
	}

	TIM_MasterConfigTypeDef TimMaster = {0};
	TimMaster.MasterSlaveMode = TIM_SLAVEMODE_DISABLE;
	TimMaster.MasterOutputTrigger = TIM_TRGO_RESET;
	if(HAL_TIMEx_MasterConfigSynchronization(&Tim3, &TimMaster) != HAL_OK)
	{
		return false;
	}
	HAL_NVIC_SetPriority(TIM3_IRQn, 5, 0);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);

	return true;

}

