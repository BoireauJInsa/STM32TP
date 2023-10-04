#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"

/*typedef struct
{
	TIM_TypeDef * Timer;	//TIM1‡TIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;*/


int main( void )
{
	MyTimer_Struct_TypeDef MyTim3 = {TIM3, 3600, 10000};
	MyTimer_Base_Init(&MyTim3);
	MyTimer_Base_Start(MyTim3.Timer);

do
{
	
} while ( 1 ) ;
}
