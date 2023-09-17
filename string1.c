#include "shell.h"
/**
 *  * starts__with - funct that checks whether  needle_ begins with hay_stack
 *   * @hay_stack: strings to be searched for
 *    * @needle_: the substrings to be soughtn
 *     *
 *      * Return: hay_stack address or NULL if otherwise
 *       */
char *starts__with(const char *hay_stack, const char *needle_)
{
		while (*needle_)
					if (*needle_++ != *hay_stack++)
									return (NULL);
			return ((char *)hay_stack);
}

/**
 *  * _strlen - funct that prints length of a string
 *   * @r:  string length to be printed
 *    *
 *     * Return: int length of string
 *      */
int _strlen(char *r)
{
		int j = 0;

			if (!r)
						return (0);

				while (*r++)
							j++;
					return (j);
}

/**
 *  * _strcat - funct that concatenates destination and sources
 *   * @destin: destinnation of buffer
 *    * @srces:  source of buffer
 *     *
 *      * Return: ptr to destin buffer
 *       */
char *_strcat(char *destin, char *srces)
{
		char *p = destin;

			while (*destin)
						destin++;
				while (*srces)
							*destin++ = *srces++;
					*destin = *srces;
						return (p);
}

/**
 *  * _strcmp -  funct that compares of two strangs.
 *   * @str_1:  firsts string
 *    * @str_2:  second string
 *     *
 *      * Return: negative if str_1 < str_2,
 *       *	positive if str_1 > str_2,
 *        *	zero if str_1 == str_2
 *         */
int _strcmp(char *str_1, char *str_2)
{
		while (*str_1 && *str_2)
				{
							if (*str_1 != *str_2)
											return (*str_1 - *str_2);
									str_1++;
											str_2++;
												}
			if (*str_1 == *str_2)
						return (0);
				else
							return (*str_1 < *str_2 ? -1 : 1);
}#include "shell.h"

/**
 *  * _strcat - funct that concatenates destin and srces
 *   * @destin: destinnation buffer
 *    * @srces:  source buffer
 *     *
 *      * Return: ptr to destin buffer
 *       */
char *_strcat(char *destin, char *srces)
{
		char *p = destin;

			while (*destin)
						destin++;
				while (*srces)
							*destin++ = *srces++;
					*destin = *srces;
						return (p);
}

/**
 *  * _strcmp -  funct that compares of two striings.
 *   * @str_1:  first string
 *    * @str_2:  second striing
 *     *
 *      * Return: negative if str_1 < str_2,
 *       *	positive if str_1 > str_2,
 *        *	zero if str_1 == str_2
 *         */
int _strcmp(char *str_1, char *str_2)
{
		while (*str_1 && *str_2)
				{
							if (*str_1 != *str_2)
											return (*str_1 - *str_2);
									str_1++;
											str_2++;
												}
			if (*str_1 == *str_2)
						return (0);
				else
							return (*str_1 < *str_2 ? -1 : 1);
}

/**
 *  * _strlen - funct that prints length of a string
 *   * @r:  string whose length to be printed
 *    *
 *     * Return: int length of string
 *      */
int _strlen(char *r)
{
		int j = 0;

			if (!r)
						return (0);

				while (*r++)
							j++;
					return (j);
}

/**
 *  * starts__with - funct checks whether  needle_ begins with hay_stack
 *   * @hay_stack: strings to be searcheds for
 *    * @needle_: the substring to be sought
 *     *
 *      * Return: hay_stack address or NULL if otherwise
 *       */
char *starts__with(const char *hay_stack, const char *needle_)
{
		while (*needle_)
					if (*needle_++ != *hay_stack++)
									return (NULL);
			return ((char *)hay_stack);
}
