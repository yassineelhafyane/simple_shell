#include "shell.h"


int _myenv(info_t *infos)
{
		print_list_str(infos->env);
			return (0);
}


char *_getenv(info_t *infos, const char *mn)
{
		list_t *node1 = infos->env;
			char *q;

				while (node1)
						{
									q = starts_with(node1->str, mn);
											if (q && *q)
															return (q);
													node1 = node1->next;
														}
					return (NULL);
}


int _mysetenv(info_t *infos)
{
		if (infos->argc != 3)
				{
							_eputs("Incorrect number of arguements\n");
									return (1);
										}
			if (_setenv(infos, infos->argv[1], infos->argv[2]))
						return (0);
				return (1);
}


int _myunsetenv(info_t *infos)
{
		int j;

			if (infos->argc == 1)
					{
								_eputs("Too few arguements.\n");
										return (1);
											}
				for (j = 1; j <= infos->argc; j++)
							_unsetenv(infos, infos->argv[j]);

					return (0);
}


int populate_env_list(info_t *infos)
{
		list_t *node = NULL;
			size_t j;

				for (j = 0; environ[j]; j++)
							add_node_end(&node, environ[j], 0);
					infos->env = node;
						return (0);
}#include "shell.h"


int _myenv(info_t *infos)
{
		print_list_str(infos->env);
			return (0);
}


char *_getenv(info_t *infos, const char *mn)
{
		list_t *node1 = infos->env;
			char *q;

				while (node1)
						{
									q = starts_with(node1->str, mn);
											if (q && *q)
															return (q);
													node1 = node1->next;
														}
					return (NULL);
}


int _mysetenv(info_t *infos)
{
		if (infos->argc != 3)
				{
							_eputs("Incorrect number of arguements\n");
									return (1);
										}
			if (_setenv(infos, infos->argv[1], infos->argv[2]))
						return (0);
				return (1);
}


int _myunsetenv(info_t *infos)
{
		int j;

			if (infos->argc == 1)
					{
								_eputs("Too few arguements.\n");
										return (1);
											}
				for (j = 1; j <= infos->argc; j++)
							_unsetenv(infos, infos->argv[j]);

					return (0);
}


int populate_env_list(info_t *infos)
{
		list_t *node = NULL;
			size_t j;

				for (j = 0; environ[j]; j++)
							add_node_end(&node, environ[j], 0);
					infos->env = node;
						return (0);
}
