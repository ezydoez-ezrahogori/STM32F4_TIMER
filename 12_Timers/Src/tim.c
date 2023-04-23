/*
 * tim.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Ezrah Buki
 */
#include<stm32f4xx.h>

#define TIM2EN      (1U<<0)
#define CR1_CEN     (1U<<0)



void tim2_1hz_init(void)
{
	/*Enable clock access to tm2*/
	RCC->AHB1ENR |= TIM2EN;
	/*Set Prescaler value*/
	TIM2->PSC = 1600-1 ;// 16 000 000/1600 =100000
	/*set auto-reload value*/
    TIM2->ARR = 10000-1; // 10000/10000 = 1
	/*Clear counter*/
    TIM2->CNT = 0;
	/*Enable counter*/
    TIM2->CR1 = TIM2EN;
}

