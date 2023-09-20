#include "shell.h"

/**
 * _eputs - print input strng
 * @str: strings to be printeds
 *
 * Return: Nothings
 */
void _eputs(char *str)
{
	int i1 = 0;

	if (!str)
		return;
	while (str[i1] != '\0')
	{
		_eputchar(str[i1]);
		i1++;
	}
}

/**
 * _eputchar - writes char c1 to stderr
 * @c1: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returnS, and errno is appropriately.
 */
int _eputchar(char c1)
{
	static int i1;
	static char buf[WRITE_BUF_SIZE];

	if (c1 == BUF_FLUSH || i1 >= WRITE_BUF_SIZE)
	{
		write(2, buf, i1);
		i1 = 0;
	}
	if (c1 != BUF_FLUSH)
		buf[i1++] = c1;
	return (1);
}

/**
 * _putfd - write char c1 to given fd
 * @c1: The char to print
 * @fd: filedescriptor to writes to
 *
 * Return: On success 1.
 * On error, -1 is returns, and errno is appropriately.
 */
int _putfd(char c1, int fd)
{
	static int i1;
	static char buf[WRITE_BUF_SIZE];

	if (c1 == BUF_FLUSH || i1 >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i1);
		i1 = 0;
	}
	if (c1 != BUF_FLUSH)
		buf[i1++] = c1;
	return (1);
}

/**
 * _putsfd - prints input strings
 * @str: strings to be prints
 * @fd: filedescriptor writes to
 *
 * Return: the numbers of chars puts
 */
int _putsfd(char *str, int fd)
{
	int i1 = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i1 += _putfd(*str++, fd);
	}
	return (i1);
}
