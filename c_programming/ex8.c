/*
  main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: salah
 */
#include <stdio.h>

int main()
{
	int n,i,elem;
	printf("please enter number of elements\n");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the elemnt to be searched :");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&elem);4
	for(i=0;i<n;i++)
	{
		if(elem==a[i])
		{
			printf("the elemnet %d in location %d",elem,i+1);
			break;
		}
	}
	if(i==n)
	{
		printf("the elemnt not found !\n");
	}
}


