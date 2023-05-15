#include "main.h"
#include <stdlib.h>

/**
 * word_count - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int word_count(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
	char **words;
	int word_index = 0;
	int word_length = 0;
	int i, j, k;

	if (str == NULL || *str == '\0')
		return (NULL);
		words = malloc(sizeof(char *) * (word_count(str) + 1));
	if (words == NULL)
		return (NULL);
		for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
			word_length++;
		if ((str[i] != ' ' && str[i + 1] == ' ') ||
				(str[i] != ' ' && str[i + 1] == '\0'))
		{
			words[word_index] = malloc(sizeof(char) * (word_length + 1));
			if (words[word_index] == NULL)
			{
				for (k = 0; k < word_index; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < word_length; j++)
			{
				words[word_index][j] = str[i - word_length + j + 1];
			}
			words[word_index][j] = '\0';
			word_index++;
			word_length = 0;
		}
	}
	words[word_index] = NULL;
	return (words);
}
