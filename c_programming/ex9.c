/*
  main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <string.h>
int main()
{
	int value=0,i=0;
	char String[30];
	printf("enter the string :");
	fflush(stdin);   fflush(stdout);
	gets(String);
	while(String[i]!=0)
	{
		value++;
		i++;
	}
	printf("length of string %d",value);
}

