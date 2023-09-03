/*
  main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[50];
	char str2[50];
	char* ptr1=str1;
	char* ptr2=str2;
	int i=0;
	printf("enter the string :");
	fflush(stdin);  fflush(stdout);
	gets(str1);
	while(*ptr1)
	{
		i++;
		ptr1++;
	}
	while(i>0)
	{
		ptr1--;
	    *ptr2=*ptr1;
		ptr2++;
		i--;
	}
	*ptr2=0;
	printf("%s",str2);
}
