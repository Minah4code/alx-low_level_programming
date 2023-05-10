#include "main.h"
#include <stdio.h>

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to calculate the square root of
 *
 * Return: the natural square root of n,
 * or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		int i = 1;

		while (i * i <= n)
		{
			i++;
		}
		i--;
		if (i * i == n)
		{
			return (i);
		}
		else
		{
			return (-1);
		}
	}
}
