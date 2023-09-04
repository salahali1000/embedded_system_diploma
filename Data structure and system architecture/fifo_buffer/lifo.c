/*
 lifo.c
 *
 *  Created on: Sep 4, 2023
 *      Author: salah
 */
#include "lifo.h"

LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf,unsigned int item)
{
	//check if lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return Lifo_Null;

	// check if buffer is full
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_Full;

	//Add (Push) the item
	*(lifo_buf->head) = item ; //assign the item at head address
	lifo_buf->head++;  // increment the head address to point in next Element
	lifo_buf->count++; // increment the counter
	return LIFO_no_error;
}

LIFO_status LIFO_Get_item(LIFO_Buf_t* lifo_buf,unsigned int* item)
{
	//check if LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return Lifo_Null;

	// check if buffer is empty
	if(!lifo_buf->count)
		return LIFO_empty;
	//Get(Pop) the item
	lifo_buf->head-- ;  //decrement the head address to point in previous Element
	*item = *(lifo_buf->head); // assign the value of the Element in item( argument function )
	lifo_buf->count-- ;  // decrement the counter
	return LIFO_no_error;
}

LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf,unsigned int* buf,unsigned int length)
{
	//check if buffer is valid
	if(buf == 0)
		return Lifo_Null;

	lifo_buf->base = buf ;  //assign the address of buffer in base address
	lifo_buf->head = buf ;  //assign the address of buffer in head address
	lifo_buf->length = length ;  //assign the length of buffer in member length
	lifo_buf->count = 0 ;  //initialize the count to zero
	return LIFO_no_error;

}


