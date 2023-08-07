#include "system.h"


void X_System_Init(void){

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;



	AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG;
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_1;



}
void X_Clock_Init(void){

	volatile uint32_t counter=0;

	RCC->CR &= ~RCC_CR_HSEBYP;


	RCC->CR |= RCC_CR_HSEON;
	do{
		counter++;
	}while( ((RCC->CR & RCC_CR_HSERDY)==0x0) && (counter<0x500)  );

	if((RCC->CR & RCC_CR_HSERDY)!=0x0){

		FLASH->ACR |= FLASH_ACR_PRFTBE;

		FLASH->ACR &= ~FLASH_ACR_LATENCY;
		FLASH->ACR |= FLASH_ACR_LATENCY_1;

		RCC->CFGR &= ~RCC_CFGR_HPRE;

		RCC->CFGR &= ~RCC_CFGR_PPRE1;
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

		RCC->CFGR &= ~RCC_CFGR_PPRE2;

		RCC->CFGR &= ~RCC_CFGR_ADCPRE;
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;

		RCC->CFGR &= ~RCC_CFGR_USBPRE;

		RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;

		RCC->CFGR |= RCC_CFGR_PLLSRC;

		RCC->CFGR &= ~RCC_CFGR_PLLMULL;
		RCC->CFGR |= RCC_CFGR_PLLMULL9;

		RCC->CR |= RCC_CR_PLLON;

		while( (RCC->CR & RCC_CR_PLLRDY)==0x0 );

		RCC->CFGR &= ~RCC_CFGR_SW;
		RCC->CFGR |= RCC_CFGR_SW_PLL;

		while((RCC->CFGR & RCC_CFGR_SWS) != 0x08);






















	}


}



