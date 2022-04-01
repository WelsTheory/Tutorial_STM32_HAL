/*
 * GPIO.h
 *
 *  Created on: 2 mar. 2022
 *      Author: Wels
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

typedef enum
{
	LOW,// LOW = 0
	HIGH// HIGH = 1
}gpio_state;

void Gpio_Led_Init(void);

void Gpio_Led_Write(gpio_state state);

void Gpio_Led2_Write(gpio_state state);

void Gpio_Led_Toggle(void);

/*BUTTON */

void Gpio_But_Init(void);

gpio_state Gpio_But_Read(void);

gpio_state Gpio_But2_Read(void);


#endif /* INC_GPIO_H_ */
