/*
 main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: salah
 */
#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int buffer1[5];

int main()
{
	unsigned int i,temp=0;
	LIFO_Buf_t uart_lifo,i2c_lifo;
	LIFO_init(&uart_lifo,buffer1,5);

	unsigned int* buffer2=(unsigned int*)malloc(5*sizeof(int));
	LIFO_init(&i2c_lifo,buffer2,sizeof(5*sizeof(int)));

	for(i=0 ; i<5; i++)
	{
		if( LIFO_Add_item(&uart_lifo,i) == LIFO_no_error )
			printf("UART LIFO Add : %d\n",i);
	}
	for(i=0 ; i<5; i++)
		{
			if( LIFO_Get_item(&uart_lifo,&temp) == LIFO_no_error )
				printf("UART LIFO get : %d\n",temp);
		}
	return 0;
}
