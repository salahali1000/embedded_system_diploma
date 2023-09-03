/*
  main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: salah
 */
#include <stdio.h>

int main()
{
	int number;
	printf("enter the number \n");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	if(number%2==0)
	{
		printf("the number is even\n");
	}
	else
	{
		printf("the number is odd\n");
	}
}

