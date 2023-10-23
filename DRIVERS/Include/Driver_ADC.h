#ifndef DRIVERADC_H
#define DRIVERADC_H
#include "stm32f10x.h"
typedef struct
{
	ADC_TypeDef * ADC;
	char channel;
} ADC_Struct_TypeDef;
/*
*****************************************************************************************
*@brief
*@param->Param�tre sous forme d�une structure (son adresse) contenant les
informations de base
*@Note->Fonction � lancer syst�matiquement avant d�aller plus en d�tail dans les
conf plus fines(PWM, codeur inc...)
*************************************************************************************************
*/
void ADC_Init(ADC_Struct_TypeDef * ADC);
int ADC_Read (ADC_Struct_TypeDef * ADC);
#endif
