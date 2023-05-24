#include "shell.h"

/**
 * bfree:- A Function that frees pointer and make emptty address
 * @ptr:- An address for the pointer to be free
 *
 * Return: 1 if pointers freed, 
 *         0 otherwise 
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

