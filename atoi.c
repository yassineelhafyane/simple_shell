#include "shell.h"

/**
 *  * inter - it prints true if shell is in inter mode
 *   * @info: the struct address
 *    *
 *     * Return: 1 if inter mode, 0 if opposite
 *      */
int inter(info_t *info)
{
		return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *  * isDel - checks if character is a delimeter
 *   * @d:  char to checked
 *    * @delim:  delimeter string
 *     * Return: 1 if true, 0 if opposite
 *      */
int isDel(char d, char *delim)
{
		while (*delim)
					if (*delim++ == d)
									return (1);
			return (0);
}

/**
 *  *ISal - looks for alphabetic character
 *   *@d: character to input
 *    *Return: 1 if d is alphabetic, 0 opposite
 *     */

int ISal(int d)
{
		if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
					return (1);
			else
						return (0);
}

/**
 *  *atoi - function tht converts  string to  integer
 *   *@z: string to be converted
 *    *Return: 0 if no is still string, converted number otherwise
 *     */

int atoi(char *z)
{
		int i, sign = 1, flag = 0, output;
			unsigned int result = 0;

				for (i = 0;  z[i] != '\0' && flag != 2; i++)
						{
									if (z[i] == '-')
													sign *= -1;

											if (z[i] >= '0' && z[i] <= '9')
														{
																		flag = 1;
																					result *= 10;
																								result += (z[i] - '0');
																										}
													else if (flag == 1)
																	flag = 2;
														}

					if (sign == -1)
								output = -result;
						else
									output = result;

							return (output);
}#include "shell.h"

/**
 *  * inter - it prints true if shell is in inter mode
 *   * @info: the struct address
 *    *
 *     * Return: 1 if inter mode, 0 if opposite
 *      */
int inter(info_t *info)
{
		return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *  * isDel - checks if character is a delimeter
 *   * @d:  char to checked
 *    * @delim:  delimeter string
 *     * Return: 1 if true, 0 if opposite
 *      */
int isDel(char d, char *delim)
{
		while (*delim)
					if (*delim++ == d)
									return (1);
			return (0);
}

/**
 *  *ISal - looks for alphabetic character
 *   *@d: character to input
 *    *Return: 1 if d is alphabetic, 0 opposite
 *     */

int ISal(int d)
{
		if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
					return (1);
			else
						return (0);
}

/**
 *  *atoi - function tht converts  string to  integer
 *   *@z: string to be converted
 *    *Return: 0 if no is still string, converted number otherwise
 *     */

int atoi(char *z)
{
		int i, sign = 1, flag = 0, output;
			unsigned int result = 0;

				for (i = 0;  z[i] != '\0' && flag != 2; i++)
						{
									if (z[i] == '-')
													sign *= -1;

											if (z[i] >= '0' && z[i] <= '9')
														{
																		flag = 1;
																					result *= 10;
																								result += (z[i] - '0');
																										}
													else if (flag == 1)
																	flag = 2;
														}

					if (sign == -1)
								output = -result;
						else
									output = result;

							return (output);
}
