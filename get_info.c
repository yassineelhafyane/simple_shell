#include "shell.h"

/**
 *  * free_inf - free the inf_t
 *   * @inf: structt address
 *    * @al: its true if free all
 *     */
void free_inf(inf_t *inf, int al)
{
		f_free(inf->argv);
			inf->argv = NULL;
				inf->path = NULL;
					if (al)
							{
										if (!inf->cmd_buf)
														free(inf->arg);
												if (inf->env)
																free_listt(&(inf->env));
														if (inf->history)
																		free_listt(&(inf->history));
																if (inf->alias)
																				free_listt(&(inf->alias));
																		f_free(inf->environ);
																					inf->environ = NULL;
																							bfree((void **)inf->cmd_buf);
																									if (inf->readfd > 2)
																													close(inf->readfd);
																											_putchar(BUF_FLUSH);
																												}
}#include "shell.h"

/**
 *  * clr_inf - initializies the inf_t
 *   * @inf: struct address
 *    */
void clr_inf(inf_t *inf)
{
		inf->arg = NULL;
			inf->argv = NULL;
				inf->path = NULL;
					inf->argc = 0;
}



/**
 *  * clr_inf - initializies the inf_t
 *   * @inf: its the structt  address
 *    */
void clr_inf(inf_t *inf)
{
		inf->arg = NULL;
			inf->argv = NULL;
				inf->path = NULL;
					inf->argc = 0;
}

/**
 *  * set_inf - initializies the inf_t
 *   * @inf: this is the structt address
 *    * @av: argumnt vector
 *     */
void set_inf(inf_t *inf, char **av)
{
		int j = 0;

			inf->fname = av[0];
				if (inf->arg)
						{
									inf->argv = strtow(inf->arg, " \t");
											if (!inf->argv)
														{

																		inf->argv = malloc(sizeof(char *) * 2);
																					if (inf->argv)
																									{
																														inf->argv[0] = _strdup(inf->arg);
																																		inf->argv[1] = NULL;
																																					}
																							}
													for (j = 0; inf->argv && inf->argv[j]; j++)
																	;
															inf->argc = j;

																	replace_alias(inf);
																			replace_vars(inf);
																				}
}




/**
 *  * free_inf - free the inf_t
 *   * @inf: is struct address
 *    * @al: true if freeing all
 *     */
void free_inf(inf_t *inf, int al)
{
		f_free(inf->argv);
			inf->argv = NULL;
				inf->path = NULL;
					if (al)
							{
										if (!inf->cmd_buf)
														free(inf->arg);
												if (inf->env)
																free_listt(&(inf->env));
														if (inf->history)
																		free_listt(&(inf->history));
																if (inf->alias)
																				free_listt(&(inf->alias));
																		f_free(inf->environ);
																					inf->environ = NULL;
																							bfree((void **)inf->cmd_buf);
																									if (inf->readfd > 2)
																													close(inf->readfd);
																											_putchar(BUF_FLUSH);
																												}
}

/**
 *  * set_inf - initializies the inf_t
 *   * @inf: the struct address
 *    * @av: the argmnt vector
 *     */
void set_inf(inf_t *inf, char **av)
{
		int j = 0;

			inf->fname = av[0];
				if (inf->arg)
						{
									inf->argv = strtow(inf->arg, " \t");
											if (!inf->argv)
														{

																		inf->argv = malloc(sizeof(char *) * 2);
																					if (inf->argv)
																									{
																														inf->argv[0] = _strdup(inf->arg);
																																		inf->argv[1] = NULL;
																																					}
																							}
													for (j = 0; inf->argv && inf->argv[j]; j++)
																	;
															inf->argc = j;

																	replace_alias(inf);
																			replace_vars(inf);
																				}
}