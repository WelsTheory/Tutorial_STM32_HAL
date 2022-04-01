
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H



/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


/* Private defines -----------------------------------------------------------*/
#define OTRO_LED_Pin GPIO_PIN_1
#define OTRO_LED_GPIO_Port GPIOC
#define BUT_Pin GPIO_PIN_0
#define BUT_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

//LCD PINES
#define D4_Pin  GPIO_PIN_4
#define D4_Port GPIOB
#define D5_Pin  GPIO_PIN_5
#define D5_Port GPIOB
#define D6_Pin  GPIO_PIN_6
#define D6_Port GPIOB
#define D7_Pin  GPIO_PIN_7
#define D7_Port GPIOB
#define RS_Pin  GPIO_PIN_0
#define RS_Port GPIOC
#define E_Pin   GPIO_PIN_1
#define E_Port  GPIOC

#endif /* __MAIN_H */
