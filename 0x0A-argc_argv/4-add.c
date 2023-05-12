#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, number, sum = 0;
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		char *arg = argv[i];
		
		int j = 0;
		
		while (arg[j] != '\0')
		{
			if (arg[j] < '0' || arg[j] > '9')
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		number = atoi(arg);
		sum += number;
	}
	printf("%d\n", sum);
	return (0);
}
