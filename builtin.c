#include "shell.h"

/**
<<<<<<< HEAD
 * _myexit - lets exit the shell
 * @info: Struct contain potential arguments.
 * const funct prototype.
 * Return: exit the given exit status
=======
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
<<<<<<< HEAD
	int extchck;

	if (info->argv[1]) /* there is an exit argmnts */
	{
		extchck = _erratoi(info->argv[1]);
		if (extchck == -1)
=======
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
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
<<<<<<< HEAD
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
=======
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
<<<<<<< HEAD
			_puts(s1);
=======
			_puts(s);
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
<<<<<<< HEAD
		chdira = /* TODO: what should this be? */
			chdir((dir1 = _getenv(info, "OLDPWD=")) ? dir1 : "/");
	}
	else
		chdira = chdir(info->argv[1]);
	if (chdira == -1)
=======
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
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
