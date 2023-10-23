#ifndef DRIVERTIMER_H
#define DRIVERTIMER_H
#include "stm32f10x.h"
typedef struct
{
	TIM_TypeDef * Timer;	//TIM1àTIM4
	unsigned short ARR;
	unsigned short PSC;
} Timer_Struct_TypeDef;
/*
*****************************************************************************************
*@brief
*@param->Paramètre sous forme d’une structure (son adresse) contenant les
informations de base
*@Note->Fonction à lancer systématiquement avant d’aller plus en détail dans les
conf plus fines(PWM, codeur inc...)
*************************************************************************************************
*/
void Timer_Base_Init(Timer_Struct_TypeDef * Timer);
void Timer_ActiveIT (TIM_TypeDef * Timer , char Prio, void (*IT_function) (void));
void TIM4_IRQHandler (void);
void TIM3_IRQHandler (void);
void TIM2_IRQHandler (void);
void TIM1_UP_IRQHandler (void);
void Timer_PWM( Timer_Struct_TypeDef * Timer , char Channel);
void Timer_Edit_PWM_DutyCycle( Timer_Struct_TypeDef * Timer , char Channel, int DutyCycle);
#define Timer_Base_Start(Timer) Timer->CR1 |= TIM_CR1_CEN;
#define Timer_Base_Stop(Timer) Timer->CR1 |= 0x0000;
#endif
