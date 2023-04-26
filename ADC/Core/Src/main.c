#include "main.h"
#include "GPIO.h"
#include "SysConfig.h"
#include "LCD.h"
#include "Timer.h"
#include "ADC.h"

extern ADC_HandleTypeDef ADC1Handler;

uint16_t adcValue;
float voltaje;
char data[10];

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
	ADC_Init();
	LCD_Struct_t LCD = LCD_Create(LCD_Port, LCD_Pin, RS_Port, RS_Pin, E_Port, E_Pin);
	LCD_XY(&LCD, 0,0);
	LCD_Cadena(&LCD, "MEDICION");
	while(1)
	{
		HAL_ADC_Start(&ADC1Handler);
		if(HAL_ADC_PollForConversion(&ADC1Handler, 10) == HAL_OK)
		{
			adcValue = HAL_ADC_GetValue(&ADC1Handler);
			voltaje = (5.0*adcValue)/4095;
			sprintf(data,"Vol: %.2f",voltaje);
			LCD_XY(&LCD, 0, 0);
			LCD_Cadena(&LCD, data);
		}
		HAL_Delay(100);
	}
	return 0;
}


