/*
 * ADC.c
 *
 *  Created on: Apr 20, 2022
 *      Author: Wels
 */
#include "ADC.h"

ADC_HandleTypeDef ADC1Handler;

void ADC_Gpio(void)
{
	//PA0 -> ENTRADA ANALOGICA
	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpioInit.Pin = GPIO_PIN_0;
	gpioInit.Mode = GPIO_MODE_ANALOG;
	gpioInit.Pull = GPIO_NOPULL;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOA, &gpioInit);
}

bool ADC_Init(void)
{
	ADC_Gpio();
	__HAL_RCC_ADC1_CLK_ENABLE();
	ADC_ChannelConfTypeDef adcConf;
	ADC1Handler.Instance = ADC1;
	ADC1Handler.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADC1Handler.Init.ContinuousConvMode = DISABLE;
	ADC1Handler.Init.NbrOfConversion = 1;
	ADC1Handler.Init.DiscontinuousConvMode = DISABLE;
	ADC1Handler.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	if(HAL_ADC_Init(&ADC1Handler) != HAL_OK)
	{
		return false;
	}
	adcConf.Channel = 0;
	adcConf.Rank = 1;
	adcConf.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	// 3 CYCLES + 12 CYCLES -> 12 BITS
	if(HAL_ADC_ConfigChannel(&ADC1Handler, &adcConf) != HAL_OK)
	{
		return false;
	}
	return true;
}



