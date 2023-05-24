#include "shell.h"

/**
 * get_history_file:- A function that takes the history file
 *
 * Return: assigns all string containg history file
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}
/**
 * write_history:- A function that creates  file, or assigns to existing file
 *
 * Return: 1 for run successufully without error, 
 *        -1 if errors happens
 */
int write_history(info_t *info)
{
	ssize_t filed;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (filed == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfiled(node->str, filed);
		_putfiled('\n', ffiled);
	}
	_putfiled(BUF_FLUSH, fd);
	close(filed);
	return (1);
}
/**
 * read_history:- A function that read history from file
 *
 * Return: histcount on success, 
 *        0 or null values otherwise
 */
int read_history(info_t *info)
{
	int x, last = 0, linecount = 0;
	ssize_t filed, rdlen, fsize = 0;
	struct stat st1;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	filed = open(filename, O_RDONLY);
	free(filename);
	if (filed == -1)
		return (0);
	if (!fstat(filed, &st1))
		fsize = st1.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(filed, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, linecount++);
			last = x + 1;
		}
	if (last != x)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list:- A function that adds entry to a history linked list
 * @info:- The Structure containing potential arguments.
 * @buf:- the buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0 Null Values 
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history:-A function that renumbers history linked list after values  changes
 * @info: Structure containing potential arguments. 
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}





