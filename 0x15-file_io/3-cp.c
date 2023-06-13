#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024

/**
 * error_exit - Print error message and
 * exit with given exit code.
 * @exit_code: The exit code.
 * @message: The error message.
 */
void error_exit(int exit_code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}
/**
 * cp - Copy the content of a file to another file.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buf[BUF_SIZE];

	if (file_from == NULL)
		error_exit(97, "Usage: cp file_from file_to");
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file");
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to file");
	while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buf, bytes_read);
		if (bytes_written == -1)
			error_exit(99, "Error: Can't write to file");
	}
	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file");
	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close file descriptor");
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close file descriptor");
}

/**
 * main - Entry point. Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");
	cp(argv[1], argv[2]);
	return (0);
}
