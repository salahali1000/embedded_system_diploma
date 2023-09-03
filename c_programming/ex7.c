/*
  main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: salah
 */

#include <stdio.h>

int main()
{
	int n,i;
	float sum=0;
	printf("please enter the number of data");
    fflush(stdout);     fflush(stdin);
	scanf("%d",&n);
	float a[n];
	for(i=0;i<n;i++)
	{
		printf("%d-enter a number :",i+1);
		fflush(stdin);  fflush(stdout);
		scanf("%f",a+i);
		sum+=a[i];
	}
	printf("the average equal %f",sum/n);

}


