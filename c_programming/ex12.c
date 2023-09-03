/*
  main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: salah
 */
#include <stdio.h>
void prime_numbers(int x,int y);
int main(void)
{
	prime_numbers(1,20);
}
void prime_numbers(int x,int y)
{
	int i,flag=0,j;
	for(i=x;i<=y;i++)
	{
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				flag++;
				break;
			}
		}
		if(flag==0)
		{
			printf("%d\t",i);
		}
		else
		{
			flag=0;
		}
	}
}

