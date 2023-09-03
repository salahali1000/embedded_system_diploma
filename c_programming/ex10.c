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
	int n,i,elem,number,index;
	printf("please enter the number of elements :");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&n);
	int arr[n+1];
	printf("please enter the elements\n");
	fflush(stdin);   fflush(stdout);
	for(i=0;i<n;i++)
	{
		scanf("%i",arr+i);
	}
	printf("please enter the element to be inserted :");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&elem);
	printf("please enter the number of location :");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&number);
	index=n-1;
	for(index;index>=number-1;index--)
	{
		arr[index+1]=arr[index];
	}
	arr[number-1]=elem;
	for(i=0;i<n+1;i++)
	{
		printf("%i\t",arr[i]);
	}

}

