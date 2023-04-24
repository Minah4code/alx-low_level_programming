#include <stdio.h>
#include <stdlib.h>
/**
* main - main block
* Description: prints all single digit number of base 10
* strating from 0, followed by a new line
* Return: always 0 (Success)
*/
int main(void)
{
    char c;

    for (c = '0'; c <= '9'; c++)
        putchar(c);
    for (c = 'a'; c <= 'f'; c++)
        putchar(c);
    putchar('\n');

    return (0);
}
