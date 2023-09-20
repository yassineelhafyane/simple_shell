#include "shell.h"

/**
 * _myexit - lets exit the shell
 * @info: Struct contain potential arguments.
 * const funct prototype.
 * Return: exit the given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int extchck;

	if (info->argv[1]) /* there is an exit argmnts */
	{
		extchck = _erratoi(info->argv[1]);
		if (extchck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
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
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s1, *dir1, buffer[1024];
	int chdira;

	s1 = getcwd(buffer, 1024);
	if (!s1)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir1 = _getenv(info, "HOME=");
		if (!dir1)
			chdira = /* TODO: what should this be? */
				chdir((dir1 = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdira = chdir(dir1);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s1);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdira = /* TODO: what should this be? */
			chdir((dir1 = _getenv(info, "OLDPWD=")) ? dir1 : "/");
	}
	else
		chdira = chdir(info->argv[1]);
	if (chdira == -1)
	{
		print_error(info, "can't cd to ");
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
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
