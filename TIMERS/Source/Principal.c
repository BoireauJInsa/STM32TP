#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"

/*typedef struct
{
	TIM_TypeDef * Timer;	//TIM1àTIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;*/



void CallBack( void ) {
	MyGPIO_Toggle(GPIOA, 5);
}



int main( void )
  {
	MyTimer_Struct_TypeDef MyTim2 = {TIM2, 100, 50};
	MyTimer_Struct_TypeDef MyTim3 = {TIM3, 3600, 10000};
	MyGPIO_Struct_TypeDef GPIOA5 = {GPIOA, 5, Out_Ppull};
	
	MyTimer_Base_Init(&MyTim3);
	MyTimer_Base_Start(MyTim3.Timer);
	
	MyGPIO_Init(&GPIOA5);
	
	MyTimer_ActiveIT(TIM3, 5, CallBack);
	
	
	
	TIM2->CCMR1 |= TIM_CCMR1_OC1M;
	TIM2->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM2->EGR |= TIM_EGR_UG;
	
	MyTimer_Base_Init(&MyTim2);
	MyTimer_Base_Start(MyTim2.Timer);
	
	
	
	

do
{
	
} while ( 1 ) ;
}
