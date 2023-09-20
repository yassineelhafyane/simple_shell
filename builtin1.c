#include "shell.h"

/**
<<<<<<< HEAD
 * _myhistory - displays hist list, one cmd by line, preceded
 *              with line numbers, starting at 0.
 * @info: strct contain potential argms. Used to maintain
 *        const func prototype.
=======
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
<<<<<<< HEAD
	char *p1, c1;
	int ret;

	p1 = _strchr(str, '=');
	if (!p1)
		return (1);
	c1 = *p1;
	*p1 = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p1 = c1;
=======
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
<<<<<<< HEAD
	char *p1;

	p1 = _strchr(str, '=');
	if (!p1)
		return (1);
	if (!*++p1)
=======
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
<<<<<<< HEAD
	char *p1 = NULL, *a = NULL;

	if (node)
	{
		p1 = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p1 + 1);
=======
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
<<<<<<< HEAD
	char *p1 = NULL;
=======
	char *p = NULL;
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
<<<<<<< HEAD
		p1 = _strchr(info->argv[i], '=');
		if (p1)
=======
		p = _strchr(info->argv[i], '=');
		if (p)
>>>>>>> dd2ed112a0eb4044e10170d85d5d6f35f8821f0c
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
