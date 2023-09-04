/*
 lifo.h
 *
 *  Created on: Sep 4, 2023
 *      Author: salah
 */

#ifndef LIFO_H_
#define LIFO_H_

//data types definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_Full,
	LIFO_empty,
	Lifo_Null
}LIFO_status;

//declaration of the functions
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf,unsigned int item);
LIFO_status LIFO_Get_item(LIFO_Buf_t* lifo_buf,unsigned int* item);
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf,unsigned int* buf,unsigned int length);

#endif /* LIFO_H_ */
