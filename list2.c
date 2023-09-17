#include "shell.h"

/**
 *  * list__to_strings - func returns an array
 *   * of strings of the list->str
 *    * @_head: address of pointer to first node
 *     *
 *      * Return: array of strings
 *       */
char **list__to_strings(list__t *_head)
{
		list__t *node = _head;
			size__t x = lst__len(_head), y;
				char **strs;
					char *str;

						if (!_head || !x)
									return (NULL);
							strs = malloc(sizeof(char *) * (x + 1));
								if (!strs)
											return (NULL);
									for (x = 0; node; node = node->next, x++)
											{
														str = malloc(_strlen(node->str) + 1);
																if (!str)
																			{
																							for (y = 0; y < x; y++)
																												free(strs[y]);
																										free(strs);
																													return (NULL);
																															}

																		str = _strcpy(str, node->str);
																				strs[x] = str;
																					}
										strs[x] = NULL;
											return (strs);
}

/**
 *  * lst__len - func determines length of linked list
 *   * @h: pointer to first node
 *    *
 *     * Return: size of listt
 *      */
size__t lst__len(const list__t *h)
{
		size__t t = 0;

			while (h)
					{
								h = h->next;
										t++;
											}
				return (t);
}

/**
 *  * print_list - func prints all elements
 *   * of a list__t linked list
 *    * @h: pointer to first node
 *     *
 *      * Return: size of list
 *       */
size__t print_list(const list__t *h)
{
		size__t t = 0;

			while (h)
					{
								_puts(convert_number(h->num, 10, 0));
										_putchar(':');
												_putchar(' ');
														_puts(h->str ? h->str : "(nil)");
																_puts("\n");
																		h = h->next;
																				t++;
																					}
				return (t);
}

/**
 *  * node_startswith - func returns node
 *   * whose string starts with prefix
 *    * @node: address of pointer to list _head
 *     * @prefix: string to match
 *      * @c: the next character after prefix to match
 *       *
 *        * Return: match node or null
 *         */
list__t *node_startswith(list__t *node, char *prefix, char c)
{
		char *p = NULL;

			while (node)
					{
								p = starts_with(node->str, prefix);
										if (p && ((c == -1) || (*p == c)))
														return (node);
												node = node->next;
													}
				return (NULL);
}

/**
 *  * list__to_strings - func returns an array
 *   * of strings of the list->str
 *    * @_head: address of pointer to first node
 *     *
 *      * Return: array of strings
 *       */
char **list__to_strings(list__t *_head)
{
		list__t *node = _head;
			size__t x = lst__len(_head), y;
				char **strs;
					char *str;

						if (!_head || !x)
									return (NULL);
							strs = malloc(sizeof(char *) * (x + 1));
								if (!strs)
											return (NULL);
									for (x = 0; node; node = node->next, x++)
											{
														str = malloc(_strlen(node->str) + 1);
																if (!str)
																			{
																							for (y = 0; y < x; y++)
																												free(strs[y]);
																										free(strs);
																													return (NULL);
																															}

																		str = _strcpy(str, node->str);
																				strs[x] = str;
																					}
										strs[x] = NULL;
											return (strs);
}

/**
 *  * get_node_index - func gets the index of a node
 *   * @_head: address of tha pointer to list _head
 *    * @node: pointer to the node
 *     *
 *      * Return: index of node or -1
 *       */
ssize__t get_node_index(list__t *_head, list__t *node)
{
		size__t t = 0;

			while (_head)
					{
								if (_head == node)
												return (t);
										_head = _head->next;
												t++;
													}
				return (-1);
}#include "shell.h"

/**
 *  * lst__len - func determines length of linked list
 *   * @h: pointer to first node
 *    *
 *     * Return: size of list
 *      */
size__t lst__len(const list__t *h)
{
		size__t t = 0;

			while (h)
					{
								h = h->next;
										t++;
											}
				return (t);
}

/**
 *  * print_list - func prints all elements
 *   * of a list__t linked list
 *    * @h: pointer to first node
 *     *
 *      * Return: size of list
 *       */
size__t print_list(const list__t *h)
{
		size__t t = 0;

			while (h)
					{
								_puts(convert_number(h->num, 10, 0));
										_putchar(':');
												_putchar(' ');
														_puts(h->str ? h->str : "(nil)");
																_puts("\n");
																		h = h->next;
																				t++;
																					}
				return (t);
}

/**
 *  * get_node_index - func gets the index of a node
 *   * @_head: address of tha pointer to list _head
 *    * @node: pointer to the node
 *     *
 *      * Return: index of node or -1
 *       */
ssize__t get_node_index(list__t *_head, list__t *node)
{
		size__t t = 0;

			while (_head)
					{
								if (_head == node)
												return (t);
										_head = _head->next;
												t++;
													}
				return (-1);
}

/**
 *  * node_startswith - func returns node
 *   * whose string starts with prefix
 *    * @node: address of pointer to list _head
 *     * @prefix: string to match
 *      * @c: the next character after prefix to match
 *       *
 *        * Return: match node or null
 *         */
list__t *node_startswith(list__t *node, char *prefix, char c)
{
		char *p = NULL;

			while (node)
					{
								p = starts_with(node->str, prefix);
										if (p && ((c == -1) || (*p == c)))
														return (node);
												node = node->next;
													}
				return (NULL);
}


