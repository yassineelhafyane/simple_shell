#include "shell.h"

/**
 *  * add_node - funct adds a node to the start of the list
 *   * @heaad: addy pointer to heaad node
 *    * @strr: strr field of node
 *     * @nuum: node index used by history
 *      *
 *       * Return: size of list
 *        */
list_t *add_node(list_t **heaad, const char *strr, int nuum)
{
		list_t *new_heaad;

			if (!heaad)
						return (NULL);
				new_heaad = malloc(sizeof(list_t));
					if (!new_heaad)
								return (NULL);
						_memset((void *)new_heaad, 0, sizeof(list_t));
							new_heaad->nuum = nuum;
								if (strr)
										{
													new_heaad->strr = _strrdup(strr);
															if (!new_heaad->strr)
																		{
																						free(new_heaad);
																									return (NULL);
																											}
																}
									new_heaad->next = *heaad;
										*heaad = new_heaad;
											return (new_heaad);
}

/**
 *  * print_list_strr - funct that prints only the strr element
 *   * of a list_t linked list
 *    * @h: pointer to first node of the linked_list
 *     *
 *      * Return: size of list
 *       */
size_t print_list_strr(const list_t *h)
{
		size_t t = 0;

			while (h)
					{
								_puts(h->strr ? h->strr : "(nil)");
										_puts("\n");
												h = h->next;
														t++;
															}
				return (t);
}

/**
 *  * addnodeend - funct adds a node at end of the list
 *   * @heaad: addy of pointer to heaad node
 *    * @strr: strr field of node
 *     * @nuum: node index used by history
 *      *
 *       * Return: size of list
 *        */
list_t *addnodeend(list_t **heaad, const char *strr, int nuum)
{
		list_t *new__node, *node;

			if (!heaad)
						return (NULL);

				node = *heaad;
					new__node = malloc(sizeof(list_t));
						if (!new__node)
									return (NULL);
							_memset((void *)new__node, 0, sizeof(list_t));
								new__node->nuum = nuum;
									if (strr)
											{
														new__node->strr = _strrdup(strr);
																if (!new__node->strr)
																			{
																							free(new__node);
																										return (NULL);
																												}
																	}
										if (node)
												{
															while (node->next)
																			node = node->next;
																	node->next = new__node;
																		}
											else
														*heaad = new__node;
												return (new__node);
}

/**
 *  * delete_nodee_at_indexx - funct that deletes node
 *   * at given index
 *    * @heaad: addy of pointer to first node
 *     * @index: index of node to delete
 *      *
 *       * Return: 1 on success, 0 on failure
 *        */
int delete_nodee_at_indexx(list_t **heaad, unsigned int index)
{
		list_t *node, *prev_node;
			unsigned int t = 0;

				if (!heaad || !*heaad)
							return (0);

					if (!index)
							{
										node = *heaad;
												*heaad = (*heaad)->next;
														free(node->strr);
																free(node);
																		return (1);
																			}
						node = *heaad;
							while (node)
									{
												if (t == index)
															{
																			prev_node->next = node->next;
																						free(node->strr);
																									free(node);
																												return (1);
																														}
														t++;
																prev_node = node;
																		node = node->next;
																			}
								return (0);
}

/**
 *  * free_listt - funct that frees all nodes of a list
 *   * @heaad_ptr: addy of pointer to heaad node
 *    *
 *     * Return: nothing
 *      */
void free_listt(list_t **heaad_ptr)
{
		list_t *node, *next_node, *heaad;

			if (!heaad_ptr || !*heaad_ptr)
						return;
				heaad = *heaad_ptr;
					node = heaad;
						while (node)
								{
											next_node = node->next;
													free(node->strr);
															free(node);
																	node = next_node;
																		}
							*heaad_ptr = NULL;
}#include "shell.h"

/**
 *  * addnodeend - funct adds a node at end of the list
 *   * @heaad: addy of pointer to heaad node
 *    * @strr: strr field of node
 *     * @nuum: node index used by history
 *      *
 *       * Return: size of list
 *        */
list_t *addnodeend(list_t **heaad, const char *strr, int nuum)
{
		list_t *new__node, *node;

			if (!heaad)
						return (NULL);

				node = *heaad;
					new__node = malloc(sizeof(list_t));
						if (!new__node)
									return (NULL);
							_memset((void *)new__node, 0, sizeof(list_t));
								new__node->nuum = nuum;
									if (strr)
											{
														new__node->strr = _strrdup(strr);
																if (!new__node->strr)
																			{
																							free(new__node);
																										return (NULL);
																												}
																	}
										if (node)
												{
															while (node->next)
																			node = node->next;
																	node->next = new__node;
																		}
											else
														*heaad = new__node;
												return (new__node);
}

/**
 *  * add_node - funct adds a node to the start of the list
 *   * @heaad: addy of pointer to heaad node
 *    * @strr: strr field of node
 *     * @nuum: node index used by history
 *      *
 *       * Return: size of list
 *        */
list_t *add_node(list_t **heaad, const char *strr, int nuum)
{
		list_t *new_heaad;

			if (!heaad)
						return (NULL);
				new_heaad = malloc(sizeof(list_t));
					if (!new_heaad)
								return (NULL);
						_memset((void *)new_heaad, 0, sizeof(list_t));
							new_heaad->nuum = nuum;
								if (strr)
										{
													new_heaad->strr = _strrdup(strr);
															if (!new_heaad->strr)
																		{
																						free(new_heaad);
																									return (NULL);
																											}
																}
									new_heaad->next = *heaad;
										*heaad = new_heaad;
											return (new_heaad);
}

/**
 *  * print_list_strr - funct that prints only the strr element
 *   * of a list_t linked list
 *    * @h: pointer to first node of the linked_list
 *     *
 *      * Return: size of list
 *       */
size_t print_list_strr(const list_t *h)
{
		size_t t = 0;

			while (h)
					{
								_puts(h->strr ? h->strr : "(nil)");
										_puts("\n");
												h = h->next;
														t++;
															}
				return (t);
}

/**
 *  * free_listt - funct that frees all nodes of a list
 *   * @heaad_ptr: addy of pointer to heaad node
 *    *
 *     * Return: nothing
 *      */
void free_listt(list_t **heaad_ptr)
{
		list_t *node, *next_node, *heaad;

			if (!heaad_ptr || !*heaad_ptr)
						return;
				heaad = *heaad_ptr;
					node = heaad;
						while (node)
								{
											next_node = node->next;
													free(node->strr);
															free(node);
																	node = next_node;
																		}
							*heaad_ptr = NULL;
}

/**
 *  * delete_nodee_at_indexx - funct that deletes node
 *   * at given index
 *    * @heaad: addy of pointer to first node
 *     * @index: index of node to delete
 *      *
 *       * Return: 1 on success, 0 on failure
 *        */
int delete_nodee_at_indexx(list_t **heaad, unsigned int index)
{
		list_t *node, *prev_node;
			unsigned int t = 0;

				if (!heaad || !*heaad)
							return (0);

					if (!index)
							{
										node = *heaad;
												*heaad = (*heaad)->next;
														free(node->strr);
																free(node);
																		return (1);
																			}
						node = *heaad;
							while (node)
									{
												if (t == index)
															{
																			prev_node->next = node->next;
																						free(node->strr);
																									free(node);
																												return (1);
																														}
														t++;
																prev_node = node;
																		node = node->next;
																			}
								return (0);
}