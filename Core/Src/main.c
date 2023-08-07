#include "stm32f103xb.h"
#include "system.h"


int main(void){

	X_System_Init();
	X_Clock_Init();


	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRH |= GPIO_CRH_MODE8;

	GPIOA->CRH &= ~GPIO_CRH_CNF8;
	GPIOA->CRH |= GPIO_CRH_CNF8_1;

	RCC->CFGR &= ~RCC_CFGR_MCO;
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;


	while(1){


	}



}
