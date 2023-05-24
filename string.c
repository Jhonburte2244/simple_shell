#include "shell.h"

/**
 * _strlen:- A function that return length of string
 * @l:- length of the string to check
 *
 * Return: integer length of string
 */
int _strlen(char *l)
{
	int m = 0;

	if (!l)
		return (0);

	while (*l++)
		m++;
	return (m);
}

/**
 * _strcmp:- A function that performs lexicogarphic comparison of two strangs.
 * @l1:- The first strang
 * @l2:- The second strang
 *
 * Return: negative for s1 < s2, 
 *         positive for s1 > s2,
 *         zero for s1 == s2
 */

int _strcmp(char *l1, char *l2)
{
	while (*l1 && *l2)
	{
		if (*l1 != *l2)
			return (*l1 - *l2);
		l1++;
		l2++;
	}
	if (*l1 == *l2)
		return (0);
	else
		return (*l1 < *l2 ? -1 : 1);
}

/**
 * starts_with:- A function that checks if needle starts with haystack
 * @haystack:- The string to be searched
 * @needle:- The substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat:- A function that concatenates two strings
 * @dest:- Buffers for the Destination
 * @src:- Buffer for the source file
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

