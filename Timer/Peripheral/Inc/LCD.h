/*
 * LCD.h
 *
 *  Created on: Mar 22, 2022
 *      Author: Wels
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"

#define LCD_PinType  uint16_t
#define LCD_PortType GPIO_TypeDef*

// 4 pines datos
// 2 RS y E

typedef struct
{
	LCD_PortType *dataport;// D4 d5 d6 d7
	LCD_PinType *datapin;

	LCD_PortType RS_port;
	LCD_PinType RS_pin;

	LCD_PortType E_port;
	LCD_PinType E_pin;

}LCD_Struct_t;

LCD_Struct_t LCD_Create(
		LCD_PortType port[], LCD_PinType pin[],
		LCD_PortType rs_port, LCD_PinType rs_pin,
		LCD_PortType e_port, LCD_PinType e_pin
);

void LCD_Init(LCD_Struct_t *LCD);

void LCD_Comando(LCD_Struct_t *LCD, char cmd);

void LCD_Caracter(LCD_Struct_t *LCD, char data);

void LCD_Cadena(LCD_Struct_t *LCD, char *cadena);

void LCD_XY(LCD_Struct_t *LCD, char x, char y);


#endif /* INC_LCD_H_ */
