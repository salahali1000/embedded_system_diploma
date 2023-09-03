/*
  main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <string.h>

struct student
{
	char name[30];
	int roll;
	float marks;
};

int main()
{
	int i;
	struct student list[10];
	for(i=0;i<10;i++)
	{
		printf("enter name of student %d :",i+1);
		fflush(stdin);   fflush(stdout);
		gets(list[i].name);
		printf("enter roll number of student %d :",i+1);
		fflush(stdin);   fflush(stdout);
		scanf("%d",&list[i].roll);
		printf("enter marks number of student %d :",i+1);
		fflush(stdin);   fflush(stdout);
		scanf("%f",&list[i].marks);
	}
	for(i=0;i<10;i++)
	{
		printf("name of student %d :%s\n",i+1,list[i].name);
		printf("name of student %d :%d\n",i+1,list[i].roll);
		printf("name of student %d :%.1f\n",i+1,list[i].marks);
	}
}
