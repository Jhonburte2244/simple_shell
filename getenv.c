#include "shell.h"

/**
 * get_environ:- A function that return string array copy of environ
 * @info:- This Structure contains potential arguments.
 * which Used to build constant function prototype.
 * Return: Always Null Value or 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv: A function that Remove environment variable
 * @info: this Structure contains potential arguments. 
 * which Used to build constant function prototype.
 *  Return: 1 return  delete
 *          0 else displays null
 * @var:- An Env var String property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t m = 0;
	char *k;

	if (!node || !var)
		return (0);

	while (node)
	{
		k = starts_with(node->str, var);
		if (k && *k == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), m);
			m = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		m++;
	}
	return (info->env_changed);
}

/**
 * _setenv:- A function which startup new environment variable,
 *             or modify existing variable
 * @info:- This Structure contains a potential arguments. 
 *        which Used to build constant function prototype.
 * @var1:- Env var strings of property
 * @val1:- Env var string value
 *  Return:- Always 0 or null values 
 */
int _setenv(info_t *info, char *var1, char *val1)
{
	char *buf = NULL;
	list_t *node;
	char *k;

	if (!var1 || !val1)
		return (0);

	buf = malloc(_strlen(var1) + _strlen(val1) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var1);
	_strcat(buf, "=");
	_strcat(buf, val1);
	node = info->env;
	while (node)
	{
		k = starts_with(node->str, var);
		if (k && *k == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}



