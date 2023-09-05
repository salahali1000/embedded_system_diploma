/*
linked_list.h
 *
 *  Created on: Sep 5, 2023
 *      Author: salah
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>

//effective data
struct SData {
	uint32_t ID;
	uint8_t name[40];
	float height;
};

//linked list node

struct SStudent {
	struct SData student;
	struct SStudent* PNextStudent;
};
 // head pointer of the list
struct SStudent* GPHead;

//prototypes of the functions
void Add_Student();
int delete_student();
void print_list();
void delete_All();
void Get_Element();
void Get_Nnodes();
void Get_Element_Last();
#endif /* LINKED_LIST_H_ */
