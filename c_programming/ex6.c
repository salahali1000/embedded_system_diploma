/*
  main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: salah
 */
#include <stdio.h>

int main()
{
	int i,j;
	float a[2][2];
	float b[2][2];
	float c[2][2];
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("enter item(%d,%d)\n",i,j);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("enter item(%d,%d)\n",i,j);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%f\t",c[i][j]);
		}
		printf("\n");
	}
}

