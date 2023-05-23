#include "shell.h"

/**
 * _eputs:- A function that prints input string
 * @str:- String that Displayed or printed
 *
 * Return: 0 null or nothing
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar:- Displays the character g to stderr
 * @g:- Character to be printed or diplayed
 *
 * Return: 1 when successfull compilled
 *        -1 is returned, when errors happened.
 */
int _eputchar(char g)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(2, buf, m);
		m = 0;
	}
	if (g != BUF_FLUSH)
		buf[m++] = g;
	return (1);
}

/**
 * _putfd:- Diplays the character g to given df
 * @g: The character to be displayed
 * @df: The filedescriptor to write to
 *
 *  Return: 1 when successfull compilled
 *        -1 is returned, when errors happened.
 */
int _putfd(char g, int df)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(df, buf, m);
		m = 0;
	}
	if (g != BUF_FLUSH)
		buf[m++] = g;
	return (1);
}

/**
 * _putsfd:- Displays Input String to Screen
 * @str:- String to be Displayed
 * @df:- File Descriptor to write to
 *
 * Return: Number of charcters put
 */
int _putsfd(char *str, int df)
{
	int m = 0;

	if (!str)
		return (0);
	while (*str)
	{
		m += _putfd(*str++, df);
	}
	return (m);
}


