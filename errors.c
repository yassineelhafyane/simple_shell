#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
	}
}

/**
<<<<<<< HEAD
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
=======
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
	return (1);
}

/**
<<<<<<< HEAD
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
=======
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
	return (1);
}

/**
<<<<<<< HEAD
 * _putsfd - prints input strings
 * @str: strings to be prints
 * @fd: filedescriptor writes to
 *
 * Return: the numbers of chars puts
 */
int _putsfd(char *str, int fd)
{
	int i1 = 0;
=======
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c

	if (!str)
		return (0);
	while (*str)
	{
<<<<<<< HEAD
		i1 += _putfd(*str++, fd);
	}
	return (i1);
=======
		i += _putfd(*str++, fd);
	}
	return (i);
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
}
