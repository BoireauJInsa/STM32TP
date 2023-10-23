#ifndef DRIVERGPIO_H
#define DRIVERGPIO_H
#include "stm32f10x.h"
typedef struct
{
			GPIO_TypeDef * GPIO;
			char GPIO_Pin; //numerode0a15
			char GPIO_Conf; //voircidessous
}	GPIO_Struct_TypeDef;
#define In_Floating		0x04		//0100
#define In_PullDown		0x08		//1000 + ODR 0
#define In_PullUp		0x18		//1000 + ODR 1
#define In_Analog		0x00		//0000
#define Out_Ppull		0x02		//0010
#define Out_OD		0x06		//0110
#define AltOut_Ppull		0x0A		//1010
#define AltOut_OD		0x0E		//1110
void GPIO_Init(GPIO_Struct_TypeDef * GPIOStructPtr);
int GPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin); //renvoie 0 ou autre chose different de 0
void GPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void GPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void GPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);
#endif
