#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"

/*typedef struct
{
	TIM_TypeDef * Timer;	//TIM1‡TIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;*/



void CallBack( void ) {
	MyGPIO_Toggle(GPIOA, 5);
}



int main( void )
   {
	MyTimer_Struct_TypeDef MyTim2 = {TIM2, 72, 10};
	MyGPIO_Struct_TypeDef GPIOA0 = {GPIOA, 0, AltOut_Ppull};
	
	MyGPIO_Init(&GPIOA0);
	
	MyTimer_Base_Init(&MyTim2);
	MyTimer_PWM(&MyTim2 , 1);
	MyTimer_Base_Start(MyTim2.Timer);
	
	MyTimer_Edit_PWM_DutyCycle(&MyTim2, 1, 33);
	
	

do
{
	
} while ( 1 ) ;
}
