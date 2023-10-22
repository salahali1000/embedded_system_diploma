/*
  fifo.h
 *
 *  Created on: Sep 4, 2023
 *      Author: salah
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>
#include <stdio.h>

//USEER Configuration
//select the element type(uint8_t , uint16_t , uint32_t , ...)
#define element_type uint8_t
//create buffer1
#define width 5
element_type uart_buffer[width];

//FIFO data types
typedef struct{
	uint32_t counter;
	uint32_t length;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_status;


//prototypes of the functions
FIFO_status FIFO_init(FIFO_Buf_t* fifo,element_type* buf,int32_t length);
FIFO_status FIFO_enqueue(FIFO_Buf_t* fifo,element_type item);
FIFO_status FIFO_dequeue(FIFO_Buf_t* fifo,element_type* item);
FIFO_status FIFO_Is_Full(FIFO_Buf_t* fifo);
void FIFO_Print(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */
