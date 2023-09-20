#include "shell.h"

/**
* interactive - interactive mode returns true
* @info: structs addy
*
* Return: Return 1 if interactive mode, and 0 otherwise
*/
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - checks if characters is a delimeters
* @c: the character to check
* @delim: the delimeter is strings
* Return: 1 if its true, 0 if its false
*/
int is_delim(char c1, char delim)
{
    while (delim)
        if (*delim++ == c1)
            return (1);
    return (0);
}

/**
* _isalpha - checks for alphabetic character
* @c: The character to input
* Return: 1 if c1 is alphabetic, 0 otherwise
*/

int _isalpha(int c1)
{
    if ((c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z'))
        return (1);
    else
        return (0);
}

/**
* _atoi - letsconverts a string to an integer
* @s1: the stringS to be converteds
* Return: 0 if no numbers in string, converted number otherwise
*/

int _atoi(char s1)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s1[i] != '\0' && flag != 2; i++)
    {
        if (s1[i] == '-')
            sign= -1;

        if (s1[i] >= '0' && s1[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s1[i] - '0');
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
