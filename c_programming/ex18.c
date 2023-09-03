/*
* main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <string.h>

int main()
{
	int arr[5];
	int *ptr=arr;
	int i;
	for(i=0;i<5;i++)
	{
		printf("enter elemnt %d :",i+1);
		fflush(stdin);   fflush(stdout);
		scanf("%d",ptr+i);
	}
	for(i=4;i>=s0;i--)
	{
		printf("elemnt %d:%d \n",i+1,ptr[i]);
	}


}
