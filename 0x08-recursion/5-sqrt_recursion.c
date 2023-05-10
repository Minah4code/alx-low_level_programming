#include "main.h"
#include <stdio.h>

/**
 * sqrt_helper - Recursive helper function to find the square root
 * @n: The number to find the square root of
 * @start: The starting point for searching the square root
 * @end: The ending point for searching the square root
 *
 * Return: The square root of the number, or -1 if it does not have a
 * natural square root
 */

int sqrt_helper(int n, int start, int end)
{
	if (start > end)
		return (-1);
	int mid = (start + end) / 2;
	if (mid * mid == n)
	{
		return (mid);
	}
	else if (mid * mid < n)
	{
		return (sqrt_helper(n, mid + 1, end));
	}
	else
		return (sqrt_helper(n, start, mid - 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The square root of the number, or -1 if it does not have a
 * natural square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0, n));
}
