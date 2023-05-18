#include "main.h"
#include <stdlib.h>

/*
 * malloc_checked - write a function to allocate malloc
 * @Return:  a pointer to the allocated memory
 *
 * function should cause normal process termination
 * with a status value of 98
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
