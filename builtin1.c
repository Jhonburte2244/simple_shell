#include "shell.h"

/**
 * _myhistory:- Displays output of history list, Line by line,
 *     Continues with line numbers, starts from 0.
 * @info:- displays Structure with potential arguments.
 * which Used to build constant function prototype.
 *  Return: Always NULL or 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias:- Used to set alias for string
 * @info: Struct for Parameters
 * @str:- Alias for the given String
 *
 * Return: Always 1 when error happens
 *                0 when successfully compilled
 *
 */

int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int val;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	val = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (val);
}

/**
 * set_alias:- Used to set alias for string
 * @info:- Struct for the parameters
 * @str:- Alias for the given Strings
 *
 *  Return: Always 1 when error happens
 *                0 when successfully compilled
 */
int set_alias(info_t *info, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias:- Dispalys Alias string
 * @node:- Node for the Alias
 *
 *  Return: Always 1 when error happens
 *                0 when successfully compilled
 */

int print_alias(list_t *node)
{
	char *x = NULL, *w = NULL;

	if (node)
	{
		x = _strchr(node->str, '=');
		for (w = node->str; w <= x; w++)
		_putchar(*w);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias:- Alias builtin (man alias)
 * @info: Structure that contaits potential arguments.
 * Which Used to build constant function prototype.
 *  Return: Always Null Values or 0 
 */
int _myalias(info_t *info)
{
	int m = 0;
	char *x = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (m = 1; info->argv[m]; m++)
	{
		x = _strchr(info->argv[m], '=');
		if (x)
			set_alias(info, info->argv[m]);
		else
			print_alias(node_starts_with(info->alias, info->argv[m], '='));
	}

	return (0);
}

