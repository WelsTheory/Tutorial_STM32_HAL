/*
 * Gpio.c
 *
 *  Created on: 19 feb. 2022
 *      Author: Wels
 */
#include "Gpio.h"

void Gpio_Led_Init(void)
{
	//PA5 -> LED -> GPIOA
	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpioInit.Pin = GPIO_PIN_5 | GPIO_PIN_6;
	gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInit.Pull = GPIO_NOPULL;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOA, &gpioInit);

}

void Gpio_Led_Write(gpio_state state)
{
	if(state == HIGH)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	}
}

void Gpio_Led2_Write(gpio_state state)
{
	if(state == HIGH)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	}
}

void Gpio_Led_Toggle(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
/**/

void Gpio_But_Init(void)
{
	// PC13-> BUT
	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();

	gpioInit.Pin = GPIO_PIN_13 | GPIO_PIN_0;
	gpioInit.Mode = GPIO_MODE_INPUT;
	gpioInit.Pull = GPIO_PULLUP;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &gpioInit);

}

gpio_state Gpio_But_Read(void)
{
	return (bool)HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
}

gpio_state Gpio_But2_Read(void)
{
	return (bool)HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
}





