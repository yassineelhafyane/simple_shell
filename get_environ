#include "shell.h"


char **get_environ(info_t *infos)
{
		if (!infos->environ || infos->env_changed)
				{
							infos->environ = list_to_strings(infos->env);
									infos->env_changed = 0;
										}

			return (infos->environ);
}


int _unsetenv(info_t *infos, char *variable)
{
		list_t *node = infos->env;
			size_t j = 0;
				char *q;

					if (!node || !variable)
								return (0);

						while (node)
								{
											q = starts_with(node->str, variable);
													if (q && *q == '=')
																{
																				infos->env_changed = delete_node_at_index(&(infos->env), j);
																							j = 0;
																										node = infos->env;
																													continue;
																															}
															node = node->next;
																	j++;
																		}
							return (infos->env_changed);
}


int _setenv(info_t *information, char *variable, char *val)
{
		char *buff = NULL;
			list_t *node;
				char *q;

					if (!variable || !val)
								return (0);

						buff = malloc(_strlen(variable) + _strlen(val) + 2);
							if (!buff)
										return (1);
								_strcpy(buff, variable);
									_strcat(buff, "=");
										_strcat(buff, val);
											node = information->env;
												while (node)
														{
																	q = starts_with(node->str, variable);
																			if (q && *q == '=')
																						{
																										free(node->str);
																													node->str = buff;
																																information->env_changed = 1;
																																			return (0);
																																					}
																					node = node->next;
																						}
													add_node_end(&(information->env), buff, 0);
														free(buff);
															information->env_changed = 1;
																return (0);
}#include "shell.h"


char **get_environ(info_t *infos)
{
		if (!infos->environ || infos->env_changed)
				{
							infos->environ = list_to_strings(infos->env);
									infos->env_changed = 0;
										}

			return (infos->environ);
}


int _unsetenv(info_t *infos, char *variable)
{
		list_t *node = infos->env;
			size_t j = 0;
				char *q;

					if (!node || !variable)
								return (0);

						while (node)
								{
											q = starts_with(node->str, variable);
													if (q && *q == '=')
																{
																				infos->env_changed = delete_node_at_index(&(infos->env), j);
																							j = 0;
																										node = infos->env;
																													continue;
																															}
															node = node->next;
																	j++;
																		}
							return (infos->env_changed);
}


int _setenv(info_t *infos, char *variable, char *val)
{
		char *buff = NULL;
			list_t *node;
				char *q;

					if (!variable || !val)
								return (0);

						buff = malloc(_strlen(variable) + _strlen(val) + 2);
							if (!buff)
										return (1);
								_strcpy(buff, variable);
									_strcat(buff, "=");
										_strcat(buff, val);
											node = infos->env;
												while (node)
														{
																	q = starts_with(node->str, variable);
																			if (q && *q == '=')
																						{
																										free(node->str);
																													node->str = buff;
																																infos->env_changed = 1;
																																			return (0);
																																					}
																					node = node->next;
																						}
													add_node_end(&(infos->env), buff, 0);
														free(buff);
															infos->env_changed = 1;
																return (0);
}
