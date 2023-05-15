#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to a newly allocated space in memory containing the concatenated string,
 *         or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	int length1 = 0, length2 = 0;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[length1] != '\0')
		length1++;
	while (s2[length2] != '\0')
		length2++;
	concatenated = malloc((length1 + length2 + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);
	for (i = 0; i < length1; i++)
		concatenated[i] = s1[i];
	for (j = 0; j < length2; j++)
		concatenated[length1 + j] = s2[j];
	concatenated[length1 + length2] = '\0';
	return (concatenated);
}
