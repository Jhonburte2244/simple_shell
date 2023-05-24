#include "shell.h"

/**
 * _memset:- A function that fill memory with a constant byte
 * @d:- the memory area pointers
 * @y:- The byte to fill *d with pointers
 * @f:- Amount of bytes filled
 * Return: pointer to memory area 
 */
char *_memset(char *d, char y, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < f; m++)
		d[m] = y;
	return (d);
}

/**
 * ffree:-  A function that free string of strings
 * @bb: string of strings
 */
void ffree(char **bb)
{
	char **d = bb;

	if (!bb)
		return;
	while (*bb)
		free(*bb++);
	free(d);
}

/**
 * _realloc:- a function that reallocates block of memory
 * @ptr: pointer to previous malloc block
 * @old_size: byte size of old block
 * @new_size: byte size of new block
 *
 * Return: pointer to da oldblock
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *y;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!y)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return(y);
}


