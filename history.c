#include "shell.h"
/**
 *  * writehist - func that create file, or appends existing files
 *   * @info: is the param strct
 *    *
 *     * Return: 1 on success, otherwise -1
 *      */
int writehist(info_t *info)
{
		ssize_t fd;
			char *filenm = gethistfile(info);
				list_t *node = NULL;

					if (!filenm)
								return (-1);

						fd = open(filenm, O_CREAT | O_TRUNC | O_RDWR, 0644);
							free(filenm);
								if (fd == -1)
											return (-1);
									for (node = info->hist; node; node = node->next)
											{
														_putsfd(node->str, fd);
																_putfd('\n', fd);
																	}
										_putfd(BUF_FLUSH, fd);
											close(fd);
												return (1);
}

/**
 *  * gethistfile -func gets the hist file
 *   * @info: is param strct
 *    *
 *     * Return: allocated string with  hist file
 *      */

char *gethistfile(info_t *info)
{
		char *buff, *dr;

			dr = _getenv(info, "HOME=");
				if (!dr)
							return (NULL);
					buff = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
						if (!buff)
									return (NULL);
							buff[0] = 0;
								_strcpy(buff, dr);
									_strcat(buff, "/");
										_strcat(buff, HIST_FILE);
											return (buff);
}

/**
 *  * readhist - func that reads hist from file
 *   * @info:is the param strct
 *    *
 *     * Return: hist count on success, 0 opposite
 *      */
int readhist(info_t *info)
{
		int j, last = 0, linecount = 0;
			ssize_t d, rdlen, fsize = 0;
				strct stat st;
					char *buf = NULL, *filenam = gethistfile(info);

						if (!filenam)
									return (0);

							d = open(filenam, O_RDONLY);
								free(filenam);
									if (d == -1)
												return (0);
										if (!fstat(d, &st))
													fsize = st.st_size;
											if (fsize < 2)
														return (0);
												buf = malloc(sizeof(char) * (fsize + 1));
													if (!buf)
																return (0);
														rdlen = read(d, buf, fsize);
															buf[fsize] = 0;
																if (rdlen <= 0)
																			return (free(buf), 0);
																	close(d);
																		for (j = 0; j < fsize; j++)
																					if (buf[j] == '\n')
																								{
																												buf[j] = 0;
																															buildhistlist(info, buf + last, linecount++);
																																		last = j + 1;
																																				}
																			if (last != j)
																						buildhistlist(info, buf + last, linecount++);
																				free(buf);
																					info->histcount = linecount;
																						while (info->histcount-- >= HIST_MAX)
																									delete_node_at_index(&(info->hist), 0);
																							renumberhist(info);
																								return (info->histcount);
}

/**
 *  * gethistfile -func gets the hist file
 *   * @info: is param strct
 *    *
 *     * Return: allocated string with  hist file
 *      */

char *gethistfile(info_t *info)
{
		char *buff, *dr;

			dr = _getenv(info, "HOME=");
				if (!dr)
							return (NULL);
					buff = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
						if (!buff)
									return (NULL);
							buff[0] = 0;
								_strcpy(buff, dr);
									_strcat(buff, "/");
										_strcat(buff, HIST_FILE);
											return (buff);
}

/**
 *  * buildhistlist - func that adds entry to  hist linked list
 *   * @info: strcture that has possible arguments. maintain
 *    * @buff: buffer
 *     * @linecount1: hist linecount
 *      * Return: Always 0
 *       */
int buildhistlist(info_t *info, char *buff, int linecount1)
{
		list_t *node = NULL;

			if (info->hist)
						node = info->hist;
				add_node_end(&node, buff, linecount1);

					if (!info->hist)
								info->hist = node;
						return (0);
}

/**
 *  * renumberhist - func that renumbers hist after changes
 *   * @info: strcture that has arguments
 *    * Return: the new hist count
 *     */
int renumberhist(info_t *info)
{
		list_t *node = info->hist;
			int j = 0;

				while (node)
						{
									node->num = j++;
											node = node->next;
												}
					return (info->histcount = j);
}#include "shell.h"


/**
 *  * writehist - func that create file, or appends existing files
 *   * @info: is the param strct
 *    *
 *     * Return: 1 on success, otherwise -1
 *      */
int writehist(info_t *info)
{
		ssize_t fd;
			char *filenm = gethistfile(info);
				list_t *node = NULL;

					if (!filenm)
								return (-1);

						fd = open(filenm, O_CREAT | O_TRUNC | O_RDWR, 0644);
							free(filenm);
								if (fd == -1)
											return (-1);
									for (node = info->hist; node; node = node->next)
											{
														_putsfd(node->str, fd);
																_putfd('\n', fd);
																	}
										_putfd(BUF_FLUSH, fd);
											close(fd);
												return (1);
}



/**
 *  * buildhistlist - func that adds entry to  hist linked list
 *   * @info: strcture that has possible arguments. maintain
 *    * @buff: buffer
 *     * @linecount1: hist linecount
 *      * Return: Always 0
 *       */
int buildhistlist(info_t *info, char *buff, int linecount1)
{
		list_t *node = NULL;

			if (info->hist)
						node = info->hist;
				add_node_end(&node, buff, linecount1);

					if (!info->hist)
								info->hist = node;
						return (0);
}

/**
 *  * renumberhist - func that renumbers hist after changes
 *   * @info: strcture that has arguments
 *    * Return: the new hist count
 *     */
int renumberhist(info_t *info)
{
		list_t *node = info->hist;
			int j = 0;

				while (node)
						{
									node->num = j++;
											node = node->next;
												}
					return (info->histcount = j);
}



/**
 *  * readhist - func that reads hist from file
 *   * @info:is the param strct
 *    *
 *     * Return: hist count on success, 0 opposite
 *      */
int readhist(info_t *info)
{
		int j, last = 0, linecount = 0;
			ssize_t d, rdlen, fsize = 0;
				strct stat st;
					char *buf = NULL, *filenam = gethistfile(info);

						if (!filenam)
									return (0);

							d = open(filenam, O_RDONLY);
								free(filenam);
									if (d == -1)
												return (0);
										if (!fstat(d, &st))
													fsize = st.st_size;
											if (fsize < 2)
														return (0);
												buf = malloc(sizeof(char) * (fsize + 1));
													if (!buf)
																return (0);
														rdlen = read(d, buf, fsize);
															buf[fsize] = 0;
																if (rdlen <= 0)
																			return (free(buf), 0);
																	close(d);
																		for (j = 0; j < fsize; j++)
																					if (buf[j] == '\n')
																								{
																												buf[j] = 0;
																															buildhistlist(info, buf + last, linecount++);
																																		last = j + 1;
																																				}
																			if (last != j)
																						buildhistlist(info, buf + last, linecount++);
																				free(buf);
																					info->histcount = linecount;
																						while (info->histcount-- >= HIST_MAX)
																									delete_node_at_index(&(info->hist), 0);
																							renumberhist(info);
																								return (info->histcount);
}
