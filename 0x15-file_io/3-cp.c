#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits the program.
 * @message: The error message to print.
 * @status: The exit status.
 */
void error_exit(const char *message, int status)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(status);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		error_exit("Usage: cp file_from file_to", 97);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit("Error: Can't read from file", 98);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit("Error: Can't write to file", 99);
	}
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			error_exit("Error: Can't write to file", 99);
		}
	}
	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit("Error: Can't read from file", 98);
	}
	if (close(fd_from) == -1)
		error_exit("Error: Can't close file descriptor", 100);
	if (close(fd_to) == -1)
		error_exit("Error: Can't close file descriptor", 100);
	return (0);
}

