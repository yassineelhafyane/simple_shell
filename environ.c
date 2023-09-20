#include "shell.h"

/**
 * _myenv - print the currents env
 * @info: strct cont potential argument. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p1;

	while (node)
	{
		p1 = starts_with(node->str, name);
		if (p1 && *p1)
			return (p1);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Inis a news environment variables,
 *             or modifys an existing ones
 * @info: strct containing potentials argmnt. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an envrmnt variables
 * @info: strct containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i1;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i1 = 1; i1 <= info->argc; i1++)
		_unsetenv(info, info->argv[i1]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i1;

	for (i1 = 0; environ[i1]; i1++)
		add_node_end(&node, environ[i1], 0);
	info->env = node;
	return (0);
}
