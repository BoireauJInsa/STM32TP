#include "Driver_ADC.h"

void ADC_Init(ADC_Struct_TypeDef * ADC){
	if (ADC->channel < 18){
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
		if (ADC->ADC == ADC1) {
			RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
		} else if (ADC->ADC == ADC2) {
			RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
		}
		
		ADC->ADC->CR2 |= ADC_CR2_ADON;
		
		ADC->ADC->SQR3 |= ADC->channel;
		ADC->ADC->CR2 |= ADC_CR2_CONT;
		ADC->ADC->CR1 |= ADC_CR1_EOCIE;
		ADC->ADC->CR2 |= ADC_CR2_ADON;
	}
}

int ADC_Read (ADC_Struct_TypeDef * ADC) {
	return ADC->ADC->DR;
}
