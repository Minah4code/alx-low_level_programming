#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - main block
 * Description: prints all single digit number of base 10
 * starting from 0, followed by new line.
 * Return: 0
 */
int main(void)
{
       	int i;
       
	for (i = 0; i < 10; i++)
	       	putchar(i + '0');
       
	putchar('\n');
       
	return (0);
}
