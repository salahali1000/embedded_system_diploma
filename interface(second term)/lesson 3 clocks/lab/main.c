/**
 ******************************************************************************
 * @file           : main.c
 * @author         : salah ali
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "STD_TYPES.h"


//register addresses
#define GPIOA_BASE      0x40010800
#define GPIOA_CRH       *(vuint32 *)(GPIOA_BASE+0x04)
#define GPIOA_ODR		*(vuint32 *)(GPIOA_BASE+0x0c)
#define RCC_BASE        0x40021000
#define RCC_APB2ENR		*(vuint32 *)(RCC_BASE+0x18)
#define RCC_CFGR		*(vuint32 *)(RCC_BASE+0x04)
#define RCC_CR			*(vuint32 *)(RCC_BASE+0x00)
int main(void)
{
	RCC_CFGR &= ~(1<<16);
	RCC_CFGR |= (0b0110 << 18 );
	RCC_CFGR |= (0b100 << 8);
	RCC_CFGR |= (0b101 << 11);
	RCC_CFGR |= (0b10);
	RCC_CR |= (1<<24);

	//init clock for GPIOA
	RCC_APB2ENR |=(1<<2);
	GPIOA_CRH &= 0Xff0fffff;
	GPIOA_CRH |= 0X00200000;
	while(1)
	{
		GPIOA_ODR |= (1<<13) ;
		for(int i = 0; i < 5000; i++);
		GPIOA_ODR &= ~(1<<13) ;
		for(int i = 0; i < 5000; i++);

	}
}
