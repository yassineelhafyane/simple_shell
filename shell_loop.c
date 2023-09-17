#include "shell.h"

/**
 *  * hsh - main shell loop func
 *   * @inf: the parameter & return inf struct
 *    * @av: the argument vector from main() func
 *     *
 *      * Return: 0 on success, 1 on error,
 *       * or NULL
 *        */
int hsh(inf_t *inf, char **av)
{
		sizee_t r = 0;
			int builtiin_rett = 0;

				while (r != -1 && builtiin_rett != -2)
						{
									clear_inf(inf);
											if (interactive(inf))
															_puts("$ ");
													_eputchar(BUF_FLUSH);
															r = get_input(inf);
																	if (r != -1)
																				{
																								set_inf(inf, av);
																											builtiin_rett = find_builtiin(inf);
																														if (builtiin_rett == -1)
																																			find_cmd(inf);
																																}
																			else if (interactive(inf))
																							_putchar('\n');
																					free_inf(inf, 0);
																						}
					write_history(inf);
						free_inf(inf, 1);
							if (!interactive(inf) && inf->status)
										exit(inf->status);
								if (builtiin_rett == -2)
										{
													if (inf->err_num == -1)
																	exit(inf->status);
															exit(inf->err_num);
																}
									return (builtiin_rett);
}

/**
 *  * find_builtiin - func that finds a builtiin cmd
 *   * @inf: the parameter & return inf struct
 *    *
 *     * Return: -1 if builtiin is not found,
 *      *	0 if builtiin executed successfully,
 *       *	1 if builtiin found but not successful,
 *        *	-2 if builtiin signals exit()
 *         */
int find_builtiin(inf_t *inf)
{
		int x, built_in_ret = -1;
			builtiin_table builtiintbl[] = {
						{"exit", _myexit},
								{"env", _myenv},
										{"help", _myhelp},
												{"history", _myhistory},
														{"setenv", _mysetenv},
																{"unsetenv", _myunsetenv},
																		{"cd", _mycd},
																				{"alias", _myalias},
																						{NULL, NULL}
							};

				for (x = 0; builtiintbl[x].type; x++)
							if (_strcmp(inf->argv[0], builtiintbl[x].type) == 0)
										{
														inf->line_count++;
																	built_in_ret = builtiintbl[x].func(inf);
																				break;
																						}
					return (built_in_ret);
}

/**
 *  * hsh - main shell loop func
 *   * @inf: the parameter & return inf struct
 *    * @av: the argument vector from main() func
 *     *
 *      * Return: 0 on success, 1 on error,
 *       * or NULL
 *        */
int hsh(inf_t *inf, char **av)
{
		sizee_t r = 0;
			int builtiin_rett = 0;

				while (r != -1 && builtiin_rett != -2)
						{
									clear_inf(inf);
											if (interactive(inf))
															_puts("$ ");
													_eputchar(BUF_FLUSH);
															r = get_input(inf);
																	if (r != -1)
																				{
																								set_inf(inf, av);
																											builtiin_rett = find_builtiin(inf);
																														if (builtiin_rett == -1)
																																			find_cmd(inf);
																																}
																			else if (interactive(inf))
																							_putchar('\n');
																					free_inf(inf, 0);
																						}
					write_history(inf);
						free_inf(inf, 1);
							if (!interactive(inf) && inf->status)
										exit(inf->status);
								if (builtiin_rett == -2)
										{
													if (inf->err_num == -1)
																	exit(inf->status);
															exit(inf->err_num);
																}
									return (builtiin_rett);
}

/**
 *  * find_cmd - func that finds a cmd in PATH
 *   * @inf: the parameter & return inf struct
 *    *
 *     * Return: void
 *      */
void find_cmd(inf_t *inf)
{
		char *path = NULL;
			int x, y;

				inf->path = inf->argv[0];
					if (inf->linecount_flag == 1)
							{
										inf->line_count++;
												inf->linecount_flag = 0;
													}
						for (x = 0, y = 0; inf->arg[x]; x++)
									if (!is_delim(inf->arg[x], " \t\n"))
													y++;
							if (!y)
										return;

								path = find_path(inf, _getenv(inf, "PATH="), inf->argv[0]);
									if (path)
											{
														inf->path = path;
																fork__cmd(inf);
																	}
										else
												{
															if ((interactive(inf) || _getenv(inf, "PATH=")
																					|| inf->argv[0][0] == '/') && is_cmd(inf, inf->argv[0]))
																			fork__cmd(inf);
																	else if (*(inf->arg) != '\n')
																				{
																								inf->status = 127;
																											print_error(inf, "not found\n");
																													}
																		}
}

/**
 *  * fork__cmd - func that forks a an exec cmd
 *   * @inf: the parameter & return inf struct containing arguments
 *    *
 *     * Return: void
 *      */
void fork__cmd(inf_t *inf)
{
		pid_t child_pid;

			child_pid = fork();
				if (child_pid == -1)
						{
									/*  PUT ERROR func */
									perror("Error:");
											return;
												}
					if (child_pid == 0)
							{
										if (execve(inf->path, inf->argv, get_environ(inf)) == -1)
													{
																	free_inf(inf, 1);
																				if (errno == EACCES)
																									exit(126);
																							exit(1);
																									}
												/*  PUT ERROR func */
											}
						else
								{
											wait(&(inf->status));
													if (WIFEXITED(inf->status))
																{
																				inf->status = WEXITSTATUS(inf->status);
																							if (inf->status == 126)
																												print_error(inf, "Permission denied\n");
																									}
														}
}#include "shell.h"

/**
 *  * find_builtiin - func that finds a builtiin cmd
 *   * @inf: the parameter & return inf struct
 *    *
 *     * Return: -1 if builtiin is not found,
 *      *	0 if builtiin executed successfully,
 *       *	1 if builtiin found but not successful,
 *        *	-2 if builtiin signals exit()
 *         */
int find_builtiin(inf_t *inf)
{
		int x, built_in_ret = -1;
			builtiin_table builtiintbl[] = {
						{"exit", _myexit},
								{"env", _myenv},
										{"help", _myhelp},
												{"history", _myhistory},
														{"setenv", _mysetenv},
																{"unsetenv", _myunsetenv},
																		{"cd", _mycd},
																				{"alias", _myalias},
																						{NULL, NULL}
							};

				for (x = 0; builtiintbl[x].type; x++)
							if (_strcmp(inf->argv[0], builtiintbl[x].type) == 0)
										{
														inf->line_count++;
																	built_in_ret = builtiintbl[x].func(inf);
																				break;
																						}
					return (built_in_ret);
}

/**
 *  * fork__cmd - func that forks a an exec cmd
 *   * @inf: the parameter & return inf struct containing arguments
 *    *
 *     * Return: void
 *      */
void fork__cmd(inf_t *inf)
{
		pid_t child_pid;

			child_pid = fork();
				if (child_pid == -1)
						{
									/*  PUT ERROR func */
									perror("Error:");
											return;
												}
					if (child_pid == 0)
							{
										if (execve(inf->path, inf->argv, get_environ(inf)) == -1)
													{
																	free_inf(inf, 1);
																				if (errno == EACCES)
																									exit(126);
																							exit(1);
																									}
												/*  PUT ERROR func */
											}
						else
								{
											wait(&(inf->status));
													if (WIFEXITED(inf->status))
																{
																				inf->status = WEXITSTATUS(inf->status);
																							if (inf->status == 126)
																												print_error(inf, "Permission denied\n");
																									}
														}
}

/**
 *  * find_cmd - func that finds a cmd in PATH
 *   * @inf: the parameter & return inf struct
 *    *
 *     * Return: void
 *      */
void find_cmd(inf_t *inf)
{
		char *path = NULL;
			int x, y;

				inf->path = inf->argv[0];
					if (inf->linecount_flag == 1)
							{
										inf->line_count++;
												inf->linecount_flag = 0;
													}
						for (x = 0, y = 0; inf->arg[x]; x++)
									if (!is_delim(inf->arg[x], " \t\n"))
													y++;
							if (!y)
										return;

								path = find_path(inf, _getenv(inf, "PATH="), inf->argv[0]);
									if (path)
											{
														inf->path = path;
																fork__cmd(inf);
																	}
										else
												{
															if ((interactive(inf) || _getenv(inf, "PATH=")
																					|| inf->argv[0][0] == '/') && is_cmd(inf, inf->argv[0]))
																			fork__cmd(inf);
																	else if (*(inf->arg) != '\n')
																				{
																								inf->status = 127;
																											print_error(inf, "not found\n");
																													}
																		}
}
