#include "main.h"

/**
 * path_cmd -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		path_cmd = build(*cmd, value);
		if (stat(path_cmd, &buf) == 0)
		{
			*cmd = _strdup(path_cmd);
			free(path_cmd);
			free(cmd);
			return (0);
		}
		free(path_cmd);
		value = _strtok(NULL, ":");
	}
	free(cmd);

	return (1);
}
/**
 * build - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}
