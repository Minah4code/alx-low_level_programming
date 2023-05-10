#include "main.h"
#include <stdio.h>


/**
 * sqrt_check - Recursive helper function to find the square root
 * @n: The number to find the square root of
 * @start: The starting point for the search
 * @end: The ending point for the search
 *
 * Return: The square root of n if found, otherwise -1
 */
int sqrt_check(int n, int start, int end)
{
	if (start > end)
		return (-1);
	int mid = (start + end) / 2;
	long long square = (long long)mid * mid;

	if (square == n)
		return (mid);
	else if (square > n)
		return (sqrt_check(n, start, mid - 1));
	else
		return (sqrt_check(n, mid + 1, end));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The square root of n if found, otherwise -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_check(n, 0, n));
}
