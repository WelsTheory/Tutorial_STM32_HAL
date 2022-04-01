#include "main.h"
#include "GPIO.h"
#include "SysConfig.h"
#include "LCD.h"

LCD_PortType LCD_Port[] =
{
		D4_Port,D5_Port,D6_Port,D7_Port
};

LCD_PinType LCD_Pin[]={
		D4_Pin,D5_Pin,D6_Pin,D7_Pin
};

int main(void)
{
	HAL_Init();
	SysConfigClock();
	Gpio_Led_Init();
	LCD_Struct_t LCD = LCD_Create(LCD_Port, LCD_Pin, RS_Port, RS_Pin, E_Port, E_Pin);
	LCD_XY(&LCD, 0,0);
	LCD_Cadena(&LCD, "HOLA SOY WELS");
	while(1)
	{

	}
	return 0;
}

