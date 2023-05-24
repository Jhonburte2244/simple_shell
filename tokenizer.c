#include "shell.h"

/**
 * **strtow:- A function that split string into words.
 * Repeat delimiters are ignored
 * @str:- Input string
 * @dl:- Delimeter string
 * Return: 1 pointer to array of strings, 
 *        0 or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, y, b, z, numwords = 0;
	char **l;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	l = malloc((1 + numwords) * sizeof(char *));
	if (!l)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], d))
			x++;
		b = 0;
		while (!is_delim(str[x + b], d) && str[x + b])
			b++;
		s[y] = malloc((b + 1) * sizeof(char));
		if (!l[b])
		{
			for (b = 0; b < y; b++)
				free(l[b]);
			free(l);
			return (NULL);
		}
		for (z = 0; z < b; z++)
			s[y][z] = str[x++];
		l[y][z] = 0;
	}
	l[j] = NULL;
	return (l);
}

/**
 * **strtow2:- A function that split string into words
 * @str:- Input String
 * @dl;- Delimeter
 * Return:- Pointer to array of strings, 
 *          NULL or 0 for failure
 */
char **strtow2(char *str, char dl)
{
	int x, y, b, z, numwords = 0;
	char **l;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != dl && str[x + 1] == dl) ||
				    (str[x] != dl && !str[x + 1]) || str[x + 1] == dl)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!l)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == dl && str[x] != dl)
			x++;
		b = 0;
		while (str[x + b] != dl && str[x + b] && str[x + b] != dl)
			b++;
		l[y] = malloc((b + 1) * sizeof(char));
		if (!l[y])
		{
			for (b = 0; b< y; b++)
				free(l[b]);
			free(l);
			return (NULL);
		}
		for (z = 0; z < b; z++)
			l[y][z] = str[x++];
		l[y][z] = 0;
	}
	l[y] = NULL;
	return (l);
}


