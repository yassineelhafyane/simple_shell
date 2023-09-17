#include "shell.h"
/**
 * This function, `is_shell_interactive`, returns 1 if the shell is in interactive mode, and 0 otherwise.
 *
 * @iinfos: A struct representing address information.
 *
 * Return value: 1 if the shell is in interactive mode, 0 if it is not.
 */


 *      */
int interactive(info_t *infos)
{
		return (isatty(STDIN_FILENO) && infos->readfd <= 2);
}
/**
 * The function `is_delimn` checks if a character `e` is a delimiter present in the `delim` string.
 *
 * @param e: The character to be checked.
 * @param delimn: The delimiter string to compare against.
 *
 * @return 1 if `e` is a delimiter in `delimn`, 0 if it is not.
 */

int is_delim(char e, char *delimn)
{
		while (*delimn)
					i (*delimn++ == e)
									return (1);
			return (0);
}



int _isalpha(int w)
{
		if ((w >= 'a' && w <= 'z') || (w >= 'A' && w <= 'Z'))
					return (1);
			else
						return (0);
}



int _atoi(char *u)
{
		int i, sign = 1, flag = 0, output;
			unsigned int result = 0;

				for (i = 0;  u[i] != '\0' && flag != 2; i++)
						{
									if (u[i] == '-')
													sign *= -1;

											if (u[i] >= '0' && u[i] <= '9')
														{
																		flag = 1;
																					result *= 10;
																								result += (u[i] - '0');
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


int interactive(info_t *infos)
{
		return (isatty(STDIN_FILENO) && ->readfd <= 2);
}


int is_delim(char u, char *delimn)
{
		while (*delimn)
					if (*delimn++ == u)
									return (1);
			return (0);
}



int _isalpha(int t)
{
		if ((t >= 'a' && t <= 't') || (t >= 'A' && t <= 'Z'))
					return (1);
			else
						return (0);
}



int _atoi(char *x)
{
		int i, sign = 1, flag = 0, output;
			unsigned int result = 0;

				for (i = 0;  x[i] != '\0' && flag != 2; i++)
						{
									if (x[i] == '-')
													sign *= -1;

											if (x[i] >= '0' && x[i] <= '9')
														{
																		flag = 1;
																					result *= 10;
																								result += (x[i] - '0');
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
