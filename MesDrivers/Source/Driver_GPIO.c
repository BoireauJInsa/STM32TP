/*
typedef struct
{
			GPIO_TypeDef * GPIO;
			char GPIO_Pin; //numerode0a15
			char GPIO_Conf; //voircidessous
}	MyGPIO_Struct_TypeDef;


void MyGPIO_Init(MyGPIO_Struct_TypeDef * GPIOStructPtr);
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin); //renvoie 0 ou autre chose different de 0
void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);
*/
#include "Driver_GPIO.h"

void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr) {

	if (GPIOStructPtr->GPIO == GPIOA) {RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;}
	else if (GPIOStructPtr->GPIO == GPIOB) {RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;}
	else if (GPIOStructPtr->GPIO == GPIOC) {RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;}
	else if (GPIOStructPtr->GPIO == GPIOD) {RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;}
			
			
			
RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
}

int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin){
	return GPIO->IDR & (1<<GPIO_Pin);
}

void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR |= (1<<GPIO_Pin);
}
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR &= ~(1<<GPIO_Pin);
}
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);
