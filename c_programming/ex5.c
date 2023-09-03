/*
  main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: salah
 */
#include <stdio.h>

int main()
{
	int i,j;
	float a[3][3];
	float t[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("enter the item(%d,%d):",i,j);
			printf("\n");
			fflush(stdin);  fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[i][j]=a[j][i];
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%.2f\t",t[i][j]);
		}
		printf("\n");
	}
}

