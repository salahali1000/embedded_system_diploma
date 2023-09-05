/*
linked_list.c
 *
 *  Created on: Sep 5, 2023
 *      Author: salah
 */
#include "linked_list.h"

void Add_Student()
{
	uint8_t temp_text[40];
	struct SStudent* PLastStudent;
	struct SStudent* PNewStudent;
	//check if list is empty
	if(GPHead == 0)
	{
		// create a new record
		PNewStudent=(struct SStudent* ) malloc(sizeof(struct SStudent));
		//assign the address of new record to head pointer
		GPHead = PNewStudent ;
	}
	else
	{
		//navigate until reach to last record
		PLastStudent = GPHead ;
		while(PLastStudent->PNextStudent)
		{
			PLastStudent = PLastStudent->PNextStudent;
		}
		//create a new record
		PNewStudent=(struct SStudent* ) malloc(sizeof(struct SStudent));
		PLastStudent->PNextStudent = PNewStudent;
	}
	//fill the record
	printf("\n enter the ID : ");
	gets(temp_text);
	PNewStudent->student.ID = atoi(temp_text);

	printf("\n enter the full name : ");
	gets(PNewStudent->student.name);

	printf("\n enter the height : ");
	gets(temp_text);
	PNewStudent->student.height = atof(temp_text);

	// set the next pointer to null
	PNewStudent->PNextStudent=0;

}
int delete_student()
{
	uint8_t temp_text[40];
	uint32_t selected_id;
	struct SStudent* selected_student = GPHead;
	struct SStudent* previous_student = 0;
	printf("\n enter the ID you want to delete : ");
	gets(temp_text);
	selected_id=atoi(temp_text);
	//check if list is empty
	if(GPHead)
	{
		struct SStudent* selected_student = GPHead;
		struct SStudent* previous_student = 0;
		while(selected_student)
		{
			if(selected_student->student.ID == selected_id)
			{
				if(previous_student) // the first node  don't have the selected id
				{
					previous_student->PNextStudent = selected_student->PNextStudent ;
				}
				else // the first node contains the selected id
				{
					GPHead = selected_student->PNextStudent;
				}
				free(selected_student);
				return 1 ;
			}
			previous_student = selected_student;
			selected_student = selected_student->PNextStudent;
		}
	}
	printf("cannot find this ID !\n");
	return 0;
}
void print_list()
{
	int32_t count = 0 ;
	struct SStudent* CurrentStudent = GPHead;
	if(CurrentStudent == 0)
	{
		printf("\t list is empty");
	}
	else{
		while(CurrentStudent)
		{
			printf("\n student number *%d* info \n",count+1);
			printf("\n\t ID : %d",CurrentStudent->student.ID);
			printf("\n\t name : %s",CurrentStudent->student.name);
			printf("\n\t ID : %f",CurrentStudent->student.height);
			CurrentStudent=CurrentStudent->PNextStudent;
			count++;
		}
	}
}
void delete_All()
{
	struct SStudent* CurrentStudent = GPHead;
	if(CurrentStudent == 0)
	{
		printf("\t list is empty");
	}
	else{
		while(CurrentStudent)
		{
			struct SStudent* TempStudent = CurrentStudent ;
			CurrentStudent=CurrentStudent->PNextStudent;
			free(TempStudent);
		}
		GPHead = 0 ;
	}
}
void Get_Element()
{
	int32_t index ;
	printf("\n enter the index of the element : ");
	scanf("%d",&index);
	int32_t count =0 ,value =0 ;
	struct SStudent* CurrentElement = GPHead;
	while(CurrentElement)
	{
		if(count == index )
		{
			value = CurrentElement->student.ID;
		}
		CurrentElement=CurrentElement->PNextStudent;
		count++;
	}
	fflush(stdout);
	fflush(stdin);
	printf("\n value of element %d  = %d",index,value);
	fflush(stdout);
	fflush(stdin);
}
void Get_Nnodes()
{
	struct SStudent* CurrentElement = GPHead ;
	int32_t count = 0 ;
	while(CurrentElement)
	{
		count ++;
		CurrentElement=CurrentElement->PNextStudent;

	}
	fflush(stdout);
	fflush(stdin);
	printf("number of nodes = %d",count);
	fflush(stdout);
	fflush(stdin);
}
void Get_Element_Last()
{
	int32_t index,i ;
	printf("\n enter the index of the element : ");
	scanf("%d",&index);
	struct SStudent* MainStudent=GPHead;
	struct SStudent* RefStudent=GPHead;
	for(i=0 ; i<index ; i++)
	{
		RefStudent=RefStudent->PNextStudent;
	}
	while(RefStudent)
	{
		RefStudent=RefStudent->PNextStudent;
		MainStudent=MainStudent->PNextStudent;
	}
	fflush(stdout);
	fflush(stdin);
	printf("the value of ID in this index from lase = %u",MainStudent->student.ID);
	fflush(stdout);
	fflush(stdin);
}
