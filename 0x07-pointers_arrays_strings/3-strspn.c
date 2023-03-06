#include "main.h"

/**
* _strspn - Entry point
* @s: input
* @accept: input
* Return: Always 0 (Success)
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *p = s;
	while (*p != '\0' && strchr(accept, *p) != NULL)
	{
		count++;
		p++;
	}
	return count;
}
