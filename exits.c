#include "shell.h"

/**
 **_strncpy:- a function that Copies a string
 *@dest:- A String to be copied from the destination folder
 *@src:- String Source where it found
 *@m:- Amount of characters to be copied from source to distination
 *Return:- Concatenated string 
 */
char *_strncpy(char *dest, char *src, int m)
{
	int x, y;
	char *k= dest;

	x = 0;
	while (src[x] != '\0' && x < m - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < m)
	{
		y = x;
		while (y < m)
		{
			des [y] = '\0';
			y++;
		}
	}
	return (k);
}
/**
 **_strncat:- A function used to Concatenates two strings
 *@dest:- A String to be copied from the destination folder
 *@src:- String Source where it found
 **@m:- Amount of characters to be copied from source to distination
 *Return:- Concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int x, y;
	char *k = dest;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < m)
		dest[x] = '\0';
	return (k);
}

/**
 **_strchr:- A function to locates character that found in a string
 *@p:- String to be parsed
 *@l:-  Character to be look for
 *Return:- Pointer for the memory areas
 */
char *_strchr(char *p, char l)
{
	do {
		if (*p == l)
			return (p);
	} while (*p++ != '\0');

	return (NULL);
}



