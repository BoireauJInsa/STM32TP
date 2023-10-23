#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"


/*typedef struct
{
			GPIO_TypeDef * GPIO;
			char GPIO_Pin; //numerode0a15
			char GPIO_Conf; //voircidessous
}	MyGPIO_Struct_TypeDef;*/

int value;

void ADC1_2_IRQHandler(){
	ADC2->SR &= ~ADC_SR_EOC;
	value = ADC2->DR;
}

int main( void )
{
	GPIO_Struct_TypeDef GPIOA00 = {GPIOA, 00, In_Analog};
	ADC_Struct_TypeDef ADC100 = {ADC1, 0};
	GPIO_Init (&GPIOA00);
	ADC_Init (&ADC100);
	
do
{
	value = ADC_Read(&ADC100);
} while ( 1 ) ;
}
