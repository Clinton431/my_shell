#include "shell.h"

/**
 * bfree - frees a pointer and NULLS the addresses
 * @ptr: addresses of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
