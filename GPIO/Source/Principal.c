#include "stm32f10x.h"
#include "Driver_GPIO.h"

/*typedef struct
{
			GPIO_TypeDef * GPIO;
			char GPIO_Pin; //numerode0a15
			char GPIO_Conf; //voircidessous
}	MyGPIO_Struct_TypeDef;*/


int main( void )
{
	MyGPIO_Struct_TypeDef GPIOA5 = {GPIOC, 13, Out_OD};
	MyGPIO_Init (&GPIOA5);
do
{
	
} while ( 1 ) ;
}