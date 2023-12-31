/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include "LCD.h"
#include "KEYPAD.h"

void delay_ms(uint32_t time) ;
int main(void)
{
	uint8_t read = 0;
	RCC_GPIOA_CLK_EN() ;
	RCC_GPIOB_CLK_EN() ;
	LCD_INIT() ;
	KEYPAD_VINIT() ;


	while(1)
	{		do
		{
			read = KEYPAD_VREAD() ;
		}while(read ==NOT_PRESSED);
		LCD_WRITE_CHAR(read) ;
		delay_ms(100);

	}

}
