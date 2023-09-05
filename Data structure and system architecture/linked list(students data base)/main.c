/*
  main.c

 *
 *  Created on: Sep 5, 2023
 *      Author: salah
 */

#include "linked_list.h"
int main()
{
	uint8_t temp_text[40];
	while(1)
	{
		printf("\n ========================");
		printf("\n choose one of this options \n");
		printf("\n 1-Add student ");
		printf("\n 2-delete student ");
		printf("\n 3-print list ");
		printf("\n 4-delete all list ");
		printf("\n Enter Option Number : ");
		gets(temp_text);
		printf("\n ========================");
		switch(atoi(temp_text))
		{
		case 1 :
			Add_Student();
			break;
		case 2 :
			delete_student();
			break;
		case 3 :
			print_list();
			break;
		case 4 :
			delete_All();
			break;
		default :
			printf("please enter correct option !\n");
			break;
		}
	}
	return 0;
}

