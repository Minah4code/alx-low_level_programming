#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated
 * space in memory containing a copy of the string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string,
 * or NULL if insufficient memory was available or str is NULL.
 */
char *_strdup(char *str)
{
	char *duplicate;
	int length = 0;
	int i;
	if (str == NULL)
		return (NULL);
	while (str[length] != '\0')
		length++;
	duplicate = malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];
	return (duplicate);
}
