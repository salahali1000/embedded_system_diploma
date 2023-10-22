/*
  fifo.c
 *
 *  Created on: Sep 4, 2023
 *      Author: salah
 */
#include "fifo.h"
FIFO_status FIFO_init(FIFO_Buf_t* fifo,element_type* buf,int32_t length)
{
	//check if buffer is valid
	if(buf==0)
		return FIFO_null ;
	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->counter = 0 ;
	fifo->length = length ;
	return FIFO_no_error;
}
FIFO_status FIFO_enqueue(FIFO_Buf_t* fifo,element_type item)
{
	//check if buffer is valid
	if(!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_null ;
	//check if buffer is full
	if(FIFO_Is_Full(fifo)== FIFO_full)
		return FIFO_full;

	fifo->counter++; //increment the counter
	*(fifo->head)=item;
	//check if the head address become at the end of the array or not ?
	if(fifo->head == (fifo->base+fifo->length*(sizeof(element_type))))
		fifo->head = fifo->base ;
	else
		fifo->head++;

	return FIFO_no_error;

}
FIFO_status FIFO_dequeue(FIFO_Buf_t* fifo,element_type* item)
{
	//check if buffer is valid
	if(!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_null ;
	//check if buffer is empty
	if(fifo->counter == 0)
		return FIFO_empty;
	//pup the data to the item
	*item=*(fifo->tail);

	fifo->counter--; //decrement the counter
	//check if the tail address become at the end of the array or not ?
	if(fifo->tail == (fifo->base+fifo->length*(sizeof(element_type))))
		fifo->tail = fifo->base ;
	else
		fifo->tail++;
	return FIFO_no_error;
}
FIFO_status FIFO_Is_Full(FIFO_Buf_t* fifo)
{
	//check if buffer is valid
	if(!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_null ;
	//check if buffer is full
	if(fifo->counter == fifo->length)
		return FIFO_full;
	return FIFO_no_error;
}
void FIFO_Print(FIFO_Buf_t* fifo)
{
	element_type* temp;
	uint32_t i;
	if(fifo->counter == 0)
		printf("there is no data to print !\n");
	else
	{
		temp=fifo->tail;
		printf("======== FIFO Print ===========\n");
		for(i=0;i<(fifo->counter);i++)
		{
			printf("\t %X\n",*temp);
			temp++;
		}
		printf("===================\n");
	}
}

