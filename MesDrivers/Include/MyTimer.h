#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"
typedef struct
{
	TIM_TypeDef * Timer;	//TIM1�TIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;
/*
*****************************************************************************************
*@brief
*@param->Param�tre sous forme d�une structure (son adresse) contenant les
informations de base
*@Note->Fonction � lancer syst�matiquement avant d�aller plus en d�tail dans les
conf plus fines(PWM, codeur inc...)
*************************************************************************************************
*/
void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer);
void MyTimer_ActiveIT (TIM_TypeDef * Timer , char Prio, void (*IT_function) (void));
void TIM4_IRQHandler (void);
void TIM3_IRQHandler (void);
void TIM2_IRQHandler (void);
void TIM1_UP_IRQHandler (void);
void MyTimer_PWM( MyTimer_Struct_TypeDef * Timer , char Channel);
void MyTimer_Edit_PWM_DutyCycle( MyTimer_Struct_TypeDef * Timer , char Channel, int DutyCycle);
#define MyTimer_Base_Start(Timer) Timer->CR1 |= TIM_CR1_CEN;
#define MyTimer_Base_Stop(Timer) Timer->CR1 |= 0x0000;
#endif
