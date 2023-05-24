#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - entry point
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 98 on wrong number of arguments,
 * 99 on invalid operator, or 100 on division/modulo by 0.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
}
