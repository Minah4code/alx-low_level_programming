#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Checks if a character is a digit
 * @c: The character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number as a string
 * @num2: The second number as a string
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0;
	int *result;
	int i, j, carry, n1, n2, sum;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;
	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = (n1 * n2) + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	i = 0;
	while (result[i] == 0 && i < len1 + len2 - 1)
		i++;
	while (i < len1 + len2)
	{
		printf("%d", result[i]);
		i++;
	}
	printf("\n");
	free(result);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!_isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (98);
			}
		}
	}
	multiply(argv[1], argv[2]);
	return (0);
}
