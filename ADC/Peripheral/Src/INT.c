/*
 * INT.c
 *
 *  Created on: Mar 21, 2022
 *      Author: Wels
 */
#include "INT.h"

void INT_Init(void)
{
	// PC13-> INT
	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();

	gpioInit.Pin = GPIO_PIN_13;
	gpioInit.Mode = GPIO_MODE_IT_FALLING;
	gpioInit.Pull = GPIO_PULLUP;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &gpioInit);

	//ENABLE INTERRUPT
	NVIC_SetPriority(EXTI15_10_IRQn,5);

	NVIC_EnableIRQ(EXTI15_10_IRQn);

}






