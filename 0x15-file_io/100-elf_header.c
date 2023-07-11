#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <elf.h>
#include "main.h"

/**
 * print_magic - Prints the magic number of the ELF header.
 * @e_ident: The ELF identification array.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - Prints the ELF file class.
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
			printf("<unknown>\n");
			break;
	}
}

/**
 * print_data - Prints the data encoding of the ELF file.
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
			printf("<unknown>\n");
			break;
	}
}

/**
 * print_version - Prints the ELF file version.
 * @e_ident: The ELF identification array.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:            %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the OS/ABI of the ELF file.
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
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %d>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - Prints the ABI version of the ELF file.
 * @e_ident: The ELF identification array.
 */
void print_abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:              %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of the ELF file.
 * @e_type: The ELF file type.
 */
void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
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
			printf("<unknown>\n");
			break;
	}
}

/**
 * print_entry - Prints the entry point address of the ELF file.
 * @e_entry: The entry point address.
 */
void print_entry(Elf64_Addr e_entry)
{
	printf("  Entry point address      %#lx\n", (unsigned long) e_entry);
}

/**
 * elf_header - Displays the information contained in the ELF header of a file.
 * @filename: The name of the ELF file.
 */
void elf_header(const char *filename)
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr elf_header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", filename);
		exit(98);
	}
	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Cannot read from file '%s'\n", filename);
		exit(98);
	}
	if (bytes_read < sizeof(Elf64_Ehdr))
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Invalid ELF file '%s'\n", filename);
		exit(98);
	}
	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Invalid ELF file '%s'\n", filename);
		exit(98);
	}
	printf("ELF Header:\n");
	print_magic(elf_header.e_ident);
	print_class(elf_header.e_ident);
	print_data(elf_header.e_ident);
	print_version(elf_header.e_ident);
	print_osabi(elf_header.e_ident);
	print_abiversion(elf_header.e_ident);
	print_type(elf_header.e_type);
	print_entry(elf_header.e_entry);
	close(fd);
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	elf_header(argv[1]);
	return (0);
}
