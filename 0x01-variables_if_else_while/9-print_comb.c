#include <stdio.h>
#include <stdlib.h>
/**
 * main - main block 
 * Description: prints all single digit number of base 10
 * strating from 0, followed by a new line
 * Return: 0 (Success)
 */
int main(void)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        putchar(i + '0');
        if (i != 9)
        {
            putchar(',');
            putchar(' ');
        }
    }
    putchar('\n');

    return (0);
}
