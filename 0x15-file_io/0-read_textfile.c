#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and
 * prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters
 * read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	ssize_t chars_read, chars_printed;
	char *buffer;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);
	file = fopen(filename, "r");
	if (file == NULL)
	{
		free(buffer);
		return (0);
	}
	chars_read = fread(buffer, sizeof(char), letters, file);
	if (chars_read == -1)
	{
		free(buffer);
		fclose(file);
		return (0);
	}
	buffer[chars_read] = '\0';
	chars_printed = printf("%s", buffer);
	free(buffer);
	fclose(file);
	if (chars_printed != chars_read)
		return (0);
	return (chars_printed);
}
