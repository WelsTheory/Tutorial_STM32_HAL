/*
 * SysConfig.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Wels
 */

#include "SysConfig.h"

bool SysConfigClock(void)
{
	RCC_OscInitTypeDef oscInit = {0};
	RCC_ClkInitTypeDef clkInit = {0};

	oscInit.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	oscInit.HSEState = RCC_HSE_ON;
	oscInit.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	oscInit.PLL.PLLState = RCC_PLL_ON;
	oscInit.PLL.PLLM = 4;
	oscInit.PLL.PLLN = 84;
	oscInit.PLL.PLLP = RCC_PLLP_DIV2;
	oscInit.PLL.PLLQ = 7;

	if(HAL_RCC_OscConfig(&oscInit) != HAL_OK)
	{
		return false;
	}

	clkInit.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
						RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	clkInit.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clkInit.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clkInit.APB1CLKDivider = RCC_HCLK_DIV2;
	clkInit.APB2CLKDivider = RCC_HCLK_DIV1;;
	if(HAL_RCC_ClockConfig(&clkInit, FLASH_LATENCY_2) != HAL_OK)
	{
		return false;
	}
	return true;

}


