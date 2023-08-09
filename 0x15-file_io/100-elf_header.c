#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * print_magic - Prints the magic number from the ELF header.
 * @e_ident: The ELF identification array.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the ELF header class.
 * @e_ident: The ELF identification array.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - Prints the ELF header data encoding.
 * @e_ident: The ELF identification array.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			break;
	}
}

/**
 * print_version - Prints the ELF header version.
 * @e_ident: The ELF identification array.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:   %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the ELF header OS/ABI.
 * @e_ident: The ELF identification array.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - Prints the ELF header ABI version.
 * @e_ident: The ELF identification array.
 */
void print_abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:      %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF header type.
 * @e_type: The ELF header type.
 */
void print_type(unsigned int e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			break;
	}
}

/**
 * print_entry - Prints the ELF header entry point address.
 * @e_entry: The ELF header entry point address.
 */
void print_entry(unsigned long int e_entry)
{
	printf("  Entry point address:               %#lx\n", e_entry);
}

/**
 * elf_header - Displays the information contained in the ELF header.
 * @filename: The name of the ELF file.
 */
void elf_header(char *filename)
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Cannot read from file '%s'\n", filename);
		exit(98);
	}
	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1)
	{
		dprintf(2, "Error: Cannot read from file '%s'\n", filename);
		close(fd);
		exit(98);
	}
	if (bytes_read < (ssize_t)sizeof(header))
	{
		dprintf(2, "Error: Invalid ELF file '%s'\n", filename);
		close(fd);
		exit(98);
	}
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abiversion(header.e_ident);
	print_type(header.e_type);
	print_entry(header.e_entry);
	close(fd);
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}
	elf_header(argv[1]);
	return (0);
}
