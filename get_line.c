#include "shell.h"


/**
 *  * get_input - func gets line minus a newline
 *   * @inff: param struct containing argmnts
 *    *
 *     * Return: bytes read
 *      */
ssize_t get_input(inff_t *inff)
{
		static char *buf; /* command chain buffer */
			static size_t x, y, len;
				ssize_t t = 0;
					char **buf_p = &(inff->arg), *p;

						_putchar(BUF_FLUSH);
							t = inpt_buff(inff, &buf, &len);
								if (t == -1) /* EOF */
											return (-1);
									if (len)	/* commands left in chain buffer */
											{
														y = x; /*  iterator to current buf pos */
																p = buf + x; /* get pointer return */

																		check_chain(inff, buf, &y, x, len);
																				while (y < len) /* iterate semicolon or end */
																							{
																											if (is_chain(inff, buf, &y))
																																break;
																														y++;
																																}

																						x = y + 1; /* increment past nulled ';'' */
																								if (x >= len) /* reached end of buffer? */
																											{
																															x = len = 0; /* reset pos and length */
																																		inff->cmd_buf_type = CMD_NORM;
																																				}

																										*buf_p = p; /* pass pointer to current command pos */
																												return (_strlen(p)); /* return length of current cmd */
																													}

										*buf_p = buf; /* else not chain, pass the buffer from _getline() */
											return (t); /* return length of buffer from _getline() */
}

/**
 *  * read_buf - func reads a buffer
 *   * @inff: param struct containing argumrnts
 *    * @buf: buffer
 *     * @i: size
 *      *
 *       * Return: r
 *        */
ssize_t read_buf(inff_t *inff, char *buf, size_t *i)
{
		ssize_t t = 0;

			if (*i)
						return (0);
				t = read(inff->readfd, buf, READ_BUF_SIZE);
					if (t >= 0)
								*i = t;
						return (t);
}


/**
 *  * inpt_buff - func buffers chained cmnds
 *   * @inff: param struct containing arguments
 *    * @buf: address of buffer
 *     * @len: address of len var
 *      *
 *       * Return: bytes read
 *        */
ssize_t inpt_buff(inff_t *inff, char **buf, size_t *len)
{
		ssize_t t = 0;
			size_t len_p = 0;

				if (!*len) /* if nothing left in the buffer, fill it */
						{
									/*bfree((void **)inff->cmd_buf);*/
									free(*buf);
											*buf = NULL;
													signal(SIGINT, sigintHandler);
#if USE_GETLINE
															t = getline(buf, &len_p, stdin);
#else
																	t = _getline(inff, buf, &len_p);
#endif
																			if (t > 0)
																						{
																										if ((*buf)[t - 1] == '\n')
																														{
																																			(*buf)[t - 1] = '\0';
																																							t--;
																																										}
																													inff->linecount_flag = 1;
																																remove_comments(*buf);
																																			build_history_list(inff, *buf, inff->histcount++);
																																						/* if (_strchr(*buf, ';')) is this a command chain? */
																																						{
																																											*len = t;
																																															inff->cmd_buf = buf;
																																																		}
																																								}
																				}
					return (t);
}



/**
 *  * _getline - func gets next line of input,
 *   * from standard inpput
 *    * @inff: param struct containing argmnts
 *     * @ptr: address of pointer to buffer, preallocated or NULL
 *      * @length: size of preallocated ptr buffer if not NULL
 *       *
 *        * Return: s
 *         */
int _getline(inff_t *inff, char **ptr, size_t *length)
{
		static char buf[READ_BUF_SIZE];
			static size_t x, len;
				size_t k;
					ssize_t r = 0, s = 0;
						char *p = NULL, *new_p = NULL, *c;

							p = *ptr;
								if (p && length)
											s = *length;
									if (x == len)
												x = len = 0;

										r = read_buf(inff, buf, &len);
											if (r == -1 || (r == 0 && len == 0))
														return (-1);

												c = _strchr(buf + x, '\n');
													k = c ? 1 + (unsigned int)(c - buf) : len;
														new_p = _realloc(p, s, s ? s + k : k + 1);
															if (!new_p) /* MALLOC FAILURE! */
																		return (p ? free(p), -1 : -1);

																if (s)
																			_strncat(new_p, buf + x, k - x);
																	else
																				_strncpy(new_p, buf + x, k - x + 1);

																		s += k - x;
																			x = k;
																				p = new_p;

																					if (length)
																								*length = s;
																						*ptr = p;
																							return (s);
}

/**
 *  * sigintHandler - func blocks ctrl copy
 *   * @siig_numr: signal number
 *    *
 *     * Return: void
 *      */
void sigintHandler(__attribute__((unused))int siig_numr)
{
		_puts("\n");
			_puts("$ ");
				_putchar(BUF_FLUSH);
}#include "shell.h"

/**
 *  * inpt_buff - func buffers chained cmnds
 *   * @inff: param struct containing arguments
 *    * @buf: address of buffer
 *     * @len: address of len var
 *      *
 *       * Return: bytes read
 *        */
ssize_t inpt_buff(inff_t *inff, char **buf, size_t *len)
{
		ssize_t t = 0;
			size_t len_p = 0;

				if (!*len) /* if nothing left in the buffer, fill it */
						{
									/*bfree((void **)inff->cmd_buf);*/
									free(*buf);
											*buf = NULL;
													signal(SIGINT, sigintHandler);
#if USE_GETLINE
															t = getline(buf, &len_p, stdin);
#else
																	t = _getline(inff, buf, &len_p);
#endif
																			if (t > 0)
																						{
																										if ((*buf)[t - 1] == '\n')
																														{
																																			(*buf)[t - 1] = '\0';
																																							t--;
																																										}
																													inff->linecount_flag = 1;
																																remove_comments(*buf);
																																			build_history_list(inff, *buf, inff->histcount++);
																																						/* if (_strchr(*buf, ';')) is this a command chain? */
																																						{
																																											*len = t;
																																															inff->cmd_buf = buf;
																																																		}
																																								}
																				}
					return (t);
}

/**
 *  * _getline - func thst gets the next line of input,
 *   * from standard inpput
 *    * @inff: param struct containing argmnts
 *     * @ptr: address pointer to buffer, preallocated or NULL
 *      * @length: size preallocated ptr buffer if not NULL
 *       *
 *        * Return: s
 *         */
int _getline(inff_t *inff, char **ptr, size_t *length)
{
		static char buf[READ_BUF_SIZE];
			static size_t x, len;
				size_t k;
					ssize_t r = 0, s = 0;
						char *p = NULL, *new_p = NULL, *c;

							p = *ptr;
								if (p && length)
											s = *length;
									if (x == len)
												x = len = 0;

										r = read_buf(inff, buf, &len);
											if (r == -1 || (r == 0 && len == 0))
														return (-1);

												c = _strchr(buf + x, '\n');
													k = c ? 1 + (unsigned int)(c - buf) : len;
														new_p = _realloc(p, s, s ? s + k : k + 1);
															if (!new_p) /* MALLOC FAILURE! */
																		return (p ? free(p), -1 : -1);

																if (s)
																			_strncat(new_p, buf + x, k - x);
																	else
																				_strncpy(new_p, buf + x, k - x + 1);

																		s += k - x;
																			x = k;
																				p = new_p;

																					if (length)
																								*length = s;
																						*ptr = p;
																							return (s);
}

/**
 *  * sigintHandler - func thatt blocks ctrl copy
 *   * @siig_numr: signal number
 *    *
 *     * Return: void
 *      */
void sigintHandler(__attribute__((unused))int siig_numr)
{
		_puts("\n");
			_puts("$ ");
				_putchar(BUF_FLUSH);
}

/**
 *  * get_input - functioon that gets a line minus the newline
 *   * @inff: param struct containing arguments
 *    *
 *     * Return: bytes read
 *      */
ssize_t get_input(inff_t *inff)
{
		static char *buf; /* the command chain buffer */
			static size_t x, y, len;
				ssize_t t = 0;
					char **buf_p = &(inff->arg), *p;

						_putchar(BUF_FLUSH);
							t = inpt_buff(inff, &buf, &len);
								if (t == -1) /* EOF */
											return (-1);
									if (len)	/* commands left in the chain buffer */
											{
														y = x; /*  new iterator to current buf position */
																p = buf + x; /* get pointer for return */

																		check_chain(inff, buf, &y, x, len);
																				while (y < len) /* iterate to semicolon or end */
																							{
																											if (is_chain(inff, buf, &y))
																																break;
																														y++;
																																}

																						x = y + 1; /* increment past nulled ';'' */
																								if (x >= len) /* reached end of buffer? */
																											{
																															x = len = 0; /* reset position and length */
																																		inff->cmd_buf_type = CMD_NORM;
																																				}

																										*buf_p = p; /* pass back pointer to current command position */
																												return (_strlen(p)); /* return length of current command */
																													}

										*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
											return (t); /* return length of buffer from _getline() */
}

/**
 *  * read_buf - func reads a buffer
 *   * @inff: param struct containing argumrnts
 *    * @buf: buffer
 *     * @i: size
 *      *
 *       * Return: r
 *        */
ssize_t read_buf(inff_t *inff, char *buf, size_t *i)
{
		ssize_t t = 0;

			if (*i)
						return (0);
				t = read(inff->readfd, buf, READ_BUF_SIZE);
					if (t >= 0)
								*i = t;
						return (t);
}


