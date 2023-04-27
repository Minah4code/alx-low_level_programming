#include <stdio.h>

/**
 * main - finds the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
    long num = 612852475143;
    long factor = 2;

    while (num > 1)
    {
        if (num % factor == 0)
        {
            num /= factor;
        }
        else
        {
            factor++;
        }
    }

    printf("%ld\n", factor);

    return (0);
}
