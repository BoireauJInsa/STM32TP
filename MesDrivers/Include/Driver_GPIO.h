#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"
typedef struct
{
			GPIO_TypeDef * GPIO;
			char GPIO_Pin; //numerode0a15
			char GPIO_Conf; //voircidessous
}	MyGPIO_Struct_TypeDef;
#define In_Floating		0x4		//0100
#define In_PullDown		0x8		//1000
#define In_PullUp		0x8		//1000
#define In_Analog		0x0		//0000
#define Out_Ppull		0x2		//0010
#define Out_OD		0x6		//0110
#define AltOut_Ppull		0xA		//1010
#define AltOut_OD		0xE		//1110
void MyGPIO_Init(MyGPIO_Struct_TypeDef * GPIOStructPtr);
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin); //renvoie 0 ou autre chose different de 0
void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);
#endif