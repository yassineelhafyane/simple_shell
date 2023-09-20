#include "shell.h"

/**
 *  *epu - function that prints an input string
 *   * @string: the string tht is to be printed
 *    *
 *     * Return: Nothing
 *      */
void epu(char *string)
{
		int j = 0;

			if (!string)
						return;
				while (string[j] != '\0')
						{
									eput(string[j]);
											j++;
												}
}

/**
 *  * eput - function that writes the char d to stderr
 *   * @d: The character to written
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno  printed.
 *       */
int eput(char d)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(2, buf, j);
											j = 0;
												}
					if (d != BUF_FLUSH)
								buf[j++] = d;
						return (1);
}

/**
 *  * put - function tht writes the character d to  fd
 *   * @d:  character to be printed
 *    * @fd:  filedescriptor to write to or modify
 *     *
 *      * Return: On success 1.
 *       * On error, -1 is returned, and errno is returned.
 *        */
int put(char d, int fd)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(fd, buf, j);
											j = 0;
												}
					if (d != BUF_FLUSH)
								buf[j++] = d;
						return (1);
}

/**
 *  *putss -function tht  prints  input string
 *   * @string: the string to  print
 *    * @fd:  filedescriptor to write or modify
 *     *
 *      * Return: the number of chars put
 *       */
int putss(char *string, int fd)
{
		int j = 0;

			if (!string)
						return (0);
				while (*string)
						{
									j += put(*string++, fd);
										}
					return (j);
}#include "shell.h"

/**
 *  *epu - function that prints an input string
 *   * @string: the string tht is to be printed
 *    *
 *     * Return: Nothing
 *      */
void epu(char *string)
{
		int j = 0;

			if (!string)
						return;
				while (string[j] != '\0')
						{
									eput(string[j]);
											j++;
												}
}

/**
 *  * eput - function that writes the char d to stderr
 *   * @d: The character to written
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno  printed.
 *       */
int eput(char d)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(2, buf, j);
											j = 0;
												}
					if (d != BUF_FLUSH)
								buf[j++] = d;
						return (1);
}

/**
 *  * put - function tht writes the character d to  fd
 *   * @d:  character to be printed
 *    * @fd:  filedescriptor to write to or modify
 *     *
 *      * Return: On success 1.
 *       * On error, -1 is returned, and errno is returned.
 *        */
int put(char d, int fd)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(fd, buf, j);
											j = 0;
												}
					if (d != BUF_FLUSH)
								buf[j++] = d;
						return (1);
}

/**
 *  *putss -function tht  prints  input string
 *   * @string: the string to  print
 *    * @fd:  filedescriptor to write or modify
 *     *
 *      * Return: the number of chars put
 *       */
int putss(char *string, int fd)
{
		int j = 0;

			if (!string)
						return (0);
				while (*string)
						{
									j += put(*string++, fd);
										}
					return (j);
}
