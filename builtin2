#include "shell.h"


int _myhistory(info_t *info)
{
		print_list(info->history);
			return (0);
}


int unset_alias(info_t *info, char *str10)
{
		char *q, d;
			int re;

				q = _strchr(str10, '=');
					if (!q)
								return (1);
						d = *q;
							*q = 0;
								re = delete_node_at_index(&(info->alias),
												get_node_index(info->alias, node_starts_with(info->alias, str10, -1)));
									*q = d;
										return (re);
}


int set_alias(info_t *infos, char *str111)
{
		char *q;

			q = _strchr(str111, '=');
				if (!q)
							return (1);
					if (!*++q)
								return (unset_alias(infos, str111));

						unset_alias(infos, str111);
							return (add_node_end(&(infos->alias), str111, 0) == NULL);
}


int print_alias(list_t *node12)
{
		char *q = NULL, *a = NULL;

			if (node12)
					{
								q = _strchr(node12->str, '=');
										for (a = node12->str; a <= q; a++)
														_putchar(*a);
												_putchar('\'');
														_puts(q + 1);
																_puts("'\n");
																		return (0);
																			}
				return (1);
}


int _myalias(info_t *infos)
{
		int j = 0;
			char *q = NULL;
				list_t *node2 = NULL;

					if (infos->argc == 1)
							{
										node2 = infos->alias;
												while (node2)
															{
																			print_alias(node2);
																						node2 = node2->next;
																								}
														return (0);
															}
						for (j = 1; infos->argv[j]; j++)
								{
											q = _strchr(infos->argv[j], '=');
													if (q)
																	set_alias(infos, infos->argv[j]);
															else
																			print_alias(node_starts_with(infos->alias, info->argv[j], '='));
																}

							return (0);
}#include "shell.h"


int _myhistory(info_t *info)
{
		print_list(info->history);
			return (0);
}


int unset_alias(info_t *infos, char *strings)
{
		char *q, d;
			int re;

				q = _strchr(strings, '=');
					if (!q)
								return (1);
						d = *q;
							*q = 0;
								re = delete_node_at_index(&(infos->alias),
												get_node_index(infos->alias, node_starts_with(infos->alias, strings, -1)));
									*q = d;
										return (re);
}


int print_alias(list_t *node111)
{
		char *q = NULL, *a = NULL;

			if (node111)
					{
								q = _strchr(node111->str, '=');
										for (a = node111->str; a <= q; a++)
														_putchar(*a);
												_putchar('\'');
														_puts(q + 1);
																_puts("'\n");
																		return (0);
																			}
				return (1);
}


int _myalias(info_t *infos)
{
		int j = 0;
			char *q = NULL;
				list_t *node2 = NULL;

					if (infos->argc == 1)
							{
										node2 = infos->alias;
												while (node2)
															{
																			print_alias(node2);
																						node2 = node2->next;
																								}
														return (0);
															}
						for (j = 1; infos->argv[j]; j++)
								{
											q = _strchr(infos->argv[j], '=');
													if (q)
																	set_alias(infos, infos->argv[j]);
															else
																			print_alias(node_starts_with(infos->alias, info->argv[j], '='));
																}

							return (0);
}
