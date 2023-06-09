#include<stdio.h>
#include<stm32f4xx.h>
#include<stdint.h>
#include<uart.h>
#include  "adc.h"
#include  "systic.h"
#include "tim.h"



#define   GPIOAEN      (1U<<0)
#define   PIN5        (1U<<5)

#define   LED     PIN5

int  main(void){



	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);

	uart2_tx_init();
	tim2_1hz_init();

	while(1)
	{
        //wait for UIF
		while(!(TIM2->SR & SR_UIF)){}
		//clear UIF
		TIM2->SR &=~ SR_UIF;
		printf("A second passed \n\r");
		GPIOA->ODR ^= LED;

	}
}

