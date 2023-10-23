/*
typedef struct
{
			GPIO_TypeDef * GPIO;
			char GPIO_Pin; //numerode0a15
			char GPIO_Conf; //voircidessous
}	GPIO_Struct_TypeDef;


void GPIO_Init(GPIO_Struct_TypeDef * GPIOStructPtr);
int GPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin); //renvoie 0 ou autre chose different de 0
void GPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void GPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void GPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);
*/
#include "Driver_GPIO.h"

void GPIO_Init (GPIO_Struct_TypeDef * GPIOStructPtr) {

	if (GPIOStructPtr->GPIO == GPIOA) {RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;}
	else if (GPIOStructPtr->GPIO == GPIOB) {RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;}
	else if (GPIOStructPtr->GPIO == GPIOC) {RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;}
	else if (GPIOStructPtr->GPIO == GPIOD) {RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;}
	
	// Détermination CRH/CRL 
	if(GPIOStructPtr->GPIO_Pin < 8)
	{
			GPIOStructPtr->GPIO->CRL &= ~(0xF << GPIOStructPtr->GPIO_Pin*4);
		
			if (GPIOStructPtr->GPIO_Conf == In_PullUp)
			{
					//Pullup : bit ODR correspondant à 1
					GPIO_Set(GPIOStructPtr->GPIO, GPIOStructPtr->GPIO_Pin);
					GPIOStructPtr->GPIO->CRL |= (In_PullDown << GPIOStructPtr->GPIO_Pin*4);
			}
			else if (GPIOStructPtr->GPIO_Conf == In_PullDown)
			{
					//Pulldown : bit ODR correspondant à 0
					GPIO_Reset(GPIOStructPtr->GPIO, GPIOStructPtr->GPIO_Pin);
					GPIOStructPtr->GPIO->CRL |= (In_PullDown << GPIOStructPtr->GPIO_Pin*4);
			}
			else
			{
				GPIOStructPtr->GPIO->CRL |= (GPIOStructPtr->GPIO_Conf << GPIOStructPtr->GPIO_Pin*4);
			}
	}
	else
	{
			GPIOStructPtr->GPIO->CRH &= ~(0xF << ((GPIOStructPtr->GPIO_Pin-8)*4));

			if (GPIOStructPtr->GPIO_Conf == In_PullUp)
			{
					// Pullup : bit ODR correspondant à 1
						GPIO_Set(GPIOStructPtr->GPIO, GPIOStructPtr->GPIO_Pin);
						GPIOStructPtr->GPIO->CRH |= (In_PullDown << (GPIOStructPtr->GPIO_Pin-8)*4);
			}
			else if (GPIOStructPtr->GPIO_Conf == In_PullDown)
			{
					// Pulldown : bit ODR correspondant à 0
						GPIO_Reset(GPIOStructPtr->GPIO, GPIOStructPtr->GPIO_Pin);
						GPIOStructPtr->GPIO->CRH |= (In_PullDown << (GPIOStructPtr->GPIO_Pin-8)*4);
			}
			else
			{
				GPIOStructPtr->GPIO->CRH |= (GPIOStructPtr->GPIO_Conf << (GPIOStructPtr->GPIO_Pin-8)*4);
			}
}		
			
}

int GPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin){
	return GPIO->IDR & (1<<GPIO_Pin);
}

void GPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR |= (1<<GPIO_Pin);
}
void GPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR &= ~(1<<GPIO_Pin);
}
void GPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR ^= (1<<GPIO_Pin);
}
