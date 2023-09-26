#include "stm32f10x.h"
#include "Driver_GPIO.h"
int main( void )
{
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
GPIOA->CRL &= ~(0xFF << 0*8) ;
GPIOA->CRL |= (0x01 << 5) | (0x01 << 3) ;
GPIOA->ODR |= (0x01 << 0) ;
	//ocnfig bp floating input : PA0
	//config led output push pull : PA1
do
{
	if (!(GPIOA->IDR & GPIO_IDR_IDR0)) {
		GPIOA->ODR |= GPIO_ODR_ODR1;
		} else {
		GPIOA->ODR &= ~(0x01 << 1);
		}
} while ( 1 ) ;
}