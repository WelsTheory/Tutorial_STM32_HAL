/*
 * LCD.c
 *
 *  Created on: Mar 22, 2022
 *      Author: Wels
 */
#include "LCD.h"

LCD_Struct_t LCD_Create(
		LCD_PortType port[], LCD_PinType pin[],
		LCD_PortType rs_port, LCD_PinType rs_pin,
		LCD_PortType e_port, LCD_PinType e_pin
)
{
	LCD_Struct_t LCD;
	LCD.E_pin = e_pin;
	LCD.E_port = e_port;

	LCD.RS_pin = rs_pin;
	LCD.RS_port = rs_port;

	LCD.dataport = port;
	LCD.datapin = pin;

	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	gpioInit.Pin = D4_Pin | D5_Pin | D6_Pin | D7_Pin;
	gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInit.Pull = GPIO_NOPULL;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(D4_Port, &gpioInit);

	gpioInit.Pin = RS_Pin | E_Pin;
	gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInit.Pull = GPIO_NOPULL;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(RS_Port, &gpioInit);

	LCD_Init(&LCD);

	return LCD;
}

void LCD_Init(LCD_Struct_t *LCD)
{
	HAL_Delay(100);
	LCD_Comando(LCD,0x30);
	HAL_Delay(5);
	LCD_Comando(LCD,0x30);
	HAL_Delay(1);
	LCD_Comando(LCD,0x32);
	LCD_Comando(LCD,0x28);
	LCD_Comando(LCD,0x0C);
	LCD_Comando(LCD,0x01);
	LCD_Comando(LCD,0x06);
}

void LCD_Comando(LCD_Struct_t *LCD, char cmd)
{
	char comando = 0;
	//RS = 0 -> COMANDO
	HAL_GPIO_WritePin(LCD->RS_port, LCD->RS_pin, GPIO_PIN_RESET);
	// 4 bits 4 bits
	// cmd = 0x03
	// 0011
	comando = (cmd>>4)&0x0F;
	for(uint8_t i = 0; i< 4; i++)
	{
		//0011
		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (comando>>i) & 0x01);
	}

	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_RESET);

	comando = cmd & 0x0F;
	for(uint8_t i = 0; i< 4; i++)
	{
		//0011
		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (comando>>i) & 0x01);
	}

	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_RESET);

}

void LCD_Caracter(LCD_Struct_t *LCD, char data)
{
	char dat = 0;
	//RS = 1 -> CARACTER
	HAL_GPIO_WritePin(LCD->RS_port, LCD->RS_pin, GPIO_PIN_SET);
	// 4 bits 4 bits
	// cmd = 0x03
	// 0011
	dat = (data>>4)&0x0F;
	for(uint8_t i = 0; i< 4; i++)
	{
		//0011
		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (dat>>i) & 0x01);
	}

	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_RESET);

	dat = data & 0x0F;
	for(uint8_t i = 0; i< 4; i++)
	{
		//0011
		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (dat>>i) & 0x01);
	}

	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->E_port, LCD->E_pin, GPIO_PIN_RESET);

}

void LCD_Cadena(LCD_Struct_t *LCD, char *cadena)
{
	//"hola"
	for(uint8_t i = 0; i < strlen(cadena); i++)
	{
		LCD_Caracter(LCD, cadena[i]);
	}
}

void LCD_XY(LCD_Struct_t *LCD, char x, char y)
{
	if(x > 0)
	{
		LCD_Comando(LCD, 0XC0 + y);
	}
	else
	{
		LCD_Comando(LCD, 0X80 + y);
	}
}


