#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);
	current = *h;
	while (current)
	{
		count++;
		next = current->next;
		free(current);
		current = next;
		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}
	return (count);
}
