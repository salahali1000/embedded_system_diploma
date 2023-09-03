/*
  main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <string.h>
struct student{
	char name[25];
	int roll;
	float marks;
};
 int main()
 {
	 struct student student1;
	 printf("enter the name :");
	 fflush(stdin);   fflush(stdout);
	 gets(student1.name);
	 printf("please enter the roll number:");
	 fflush(stdin);   fflush(stdout);
	 scanf("%d",&student1.roll);
	 printf("please enter the marks :");
	 fflush(stdin);   fflush(stdout);
	 scanf("%f",&student1.marks);
	 printf("name :%s\n",student1.name);
	 printf("roll number :%d\n",student1.roll);
	 printf("marks :%.1f",student1.marks);
 }


