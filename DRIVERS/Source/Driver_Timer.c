#include "Driver_Timer.h"

void ( * ptrFcnTim1 ) ();
void ( * ptrFcnTim2 ) ();
void ( * ptrFcnTim3 ) ();
void ( * ptrFcnTim4 ) ();


void Timer_Base_Init(Timer_Struct_TypeDef * Timer) {
	
	if (Timer->Timer == TIM1) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}	else if (Timer->Timer == TIM2) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}	else if (Timer->Timer == TIM3) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}	else if (Timer->Timer == TIM4) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}	
	Timer->Timer->ARR = Timer->ARR-1; 
	Timer->Timer->PSC = Timer->PSC-1;
}

void Timer_ActiveIT (TIM_TypeDef * Timer , char Prio, void (*IT_function) (void)){
	int Tim;
	
	if (Timer == TIM1) {
		Tim = TIM1_UP_IRQn;
		ptrFcnTim1 = IT_function;
		
	}else if (Timer == TIM2) {
		Tim = TIM2_IRQn;
		ptrFcnTim2 = IT_function;
		
	}else if (Timer == TIM3) {
		Tim = TIM3_IRQn;
		ptrFcnTim3 = IT_function;
		
	}else if (Timer == TIM4) {
		Tim = TIM4_IRQn;
		ptrFcnTim4 = IT_function;
	}	 
	
	
	NVIC_EnableIRQ(Tim);
	NVIC_SetPriority (Tim, Prio);
	Timer->DIER |= TIM_DIER_UIE;
}

void TIM4_IRQHandler () {
	TIM4->SR &= ~TIM_SR_UIF;
	if (ptrFcnTim4 != 0) {(*ptrFcnTim4) ();}
	}

void TIM3_IRQHandler () {
	TIM3->SR &= ~TIM_SR_UIF;
	if (ptrFcnTim3 != 0) {(*ptrFcnTim3) ();}
	}

void TIM2_IRQHandler () {
	TIM2->SR &= ~TIM_SR_UIF;
	if (ptrFcnTim2 != 0) {(*ptrFcnTim2) ();}
	}

void TIM1_UP_IRQHandler () {
	TIM1->SR &= ~TIM_SR_UIF;
	if (ptrFcnTim1 != 0) {(*ptrFcnTim1) ();}
	}

void Timer_PWM( Timer_Struct_TypeDef * Timer , char Channel ) {
	switch(Channel) {
		
		case 1 :
				Timer->Timer->CCMR1 |= TIM_CCMR1_OC1M;
				Timer->Timer->CCMR1 |= TIM_CCMR1_OC1PE;
				Timer->Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
				Timer->Timer->CCER |= TIM_CCER_CC1E;
				break;
		case 2 :
				Timer->Timer->CCMR1 |= TIM_CCMR1_OC2M;
				Timer->Timer->CCMR1 |= TIM_CCMR1_OC2PE;
				Timer->Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
				Timer->Timer->CCER |= TIM_CCER_CC2E;
				break;
		case 3 :
				Timer->Timer->CCMR2 |= TIM_CCMR2_OC3M;
				Timer->Timer->CCMR2 |= TIM_CCMR2_OC3PE;
				Timer->Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
				Timer->Timer->CCER |= TIM_CCER_CC3E;
				break;
		case 4 :
				Timer->Timer->CCMR2 |= TIM_CCMR2_OC4M;
				Timer->Timer->CCMR2 |= TIM_CCMR2_OC4PE;
				Timer->Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
				Timer->Timer->CCER |= TIM_CCER_CC4E;
				break;
		default:
				break;
	}
	if (Timer->Timer == TIM1) {
			Timer->Timer->BDTR |= TIM_BDTR_MOE;
	}
	Timer->Timer->CR1 |= TIM_CR1_ARPE;
	Timer->Timer->CR1 &= ~TIM_CR1_DIR;
	Timer->Timer->EGR |= TIM_EGR_UG;
	Timer_Edit_PWM_DutyCycle(Timer, Channel, 75);
}

void Timer_Edit_PWM_DutyCycle( Timer_Struct_TypeDef * Timer , char Channel, int DutyCycle) {
		switch(Channel) {
			
			case 1 :
					Timer->Timer->CCR1 &= 0;
					Timer->Timer->CCR1 |= Timer->ARR * DutyCycle/100;
					break;
			case 2 :
					Timer->Timer->CCR2 &= 0;
					Timer->Timer->CCR2 |= Timer->ARR * DutyCycle/100;
					break;
			case 3 :
					Timer->Timer->CCR3 &= 0;
					Timer->Timer->CCR3 |= Timer->ARR * DutyCycle/100;
					break;
			case 4 :
					Timer->Timer->CCR4 &= 0;
					Timer->Timer->CCR4 |= Timer->ARR * DutyCycle/100;
					break;
			default:
					break;
		}
}

