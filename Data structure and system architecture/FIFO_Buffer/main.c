/*
  main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: salah
 */
#include "fifo.h"
int main()
{
	element_type i,temp;
	FIFO_Buf_t fifo_uart;
	if(FIFO_init( &fifo_uart , uart_buffer , 5 )==FIFO_no_error)
		printf("fifo init ----------- Done\n");

	for(i=0 ; i<7 ; i++)
	{
		printf("fifo enqueue %x\n",i);
		if(FIFO_enqueue( &fifo_uart , i )==FIFO_no_error)
			printf("\t fifo enqueue ----------- Done\n");
		else
			printf("\t fifo enqueue ----------- failed\n");

	}
	FIFO_Print( &fifo_uart );
	if(FIFO_dequeue( &fifo_uart , &temp )==FIFO_no_error)
				printf("\t fifo dequeue %d ----------- Done\n",temp);
	if(FIFO_dequeue( &fifo_uart , &temp )==FIFO_no_error)
				printf("\t fifo dequeue %d ----------- Done\n",temp);
	FIFO_Print( &fifo_uart );

	return 0;
}


