/*
  main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: salah
 */
#include <stdio.h>
int main()
{
	char letter;
	printf("please enter the charcter \n");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&letter);
	if(letter>='A'&&letter<='z')
	{
		printf("this is alphapet\n");
	}
	else
	{
		printf("this is not alphapet\n");
	}
}


