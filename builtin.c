#include "shell.h"

/**
 * _myexit:- leaves the shell after finished
 * @info:- Its contains structural for potential arguments 
 * which Used for validating constant function for the prototype.
 * Return:- leaves/exits within the given data status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int EX; /* cheks if leave or exit avialabe */ 

	if (info->argv[1]) /* If there is an exit arguement */
	{
		EX = _erratoi(info->argv[1]);
		if (EX == -1)
		{
			info->status = 2;
			print_error(info, " Invalid Values: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd:- A function used to changes the current directory of process
 * @info: It contains the structure for potential arguments
 * which Used for validating constant function prototype.
 * Return: 0 or null values
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD or current working directory =")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD or previus working directory ="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD or past working directory =")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD or  previus working directorys are =")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "current directory not found");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp:- To changes current directory CD of process occurs
 * @info:- this contains the structure for potential arguments. 
 * whichs used for validates constant function prototype.
 * Return: null or  0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

