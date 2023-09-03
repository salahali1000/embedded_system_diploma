/*
  main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: salah
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char alpha[27];
	char* ptr=alpha;
	int i;
	for(i=0;i<26;i++)
	{
		*ptr='A'+i;
		ptr++;
	}
	ptr=alpha;
	for(i=0;i<26;i++)
		{
			printf("%c\t",*ptr);
			ptr++;
		}
}
