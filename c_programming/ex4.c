/*
  main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: salah
 */
#include <stdio.h>
int main()
{
	int i,number,fact=1;
	printf("please enter the number\n");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&number);
	for(i=number;i>1;i--)
	{
		fact*=i;
	}
	printf("factorial=%d",fact);
}


