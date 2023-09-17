#include "shell.h"

/**
 *  * dup_chars - func duplicates set of chars
 *   * @patthstr: the patth of string
 *    * @startt: startting index
 *     * @stops: stopsping index
 *      *
 *       * Return: pointer to new buffer
 *        */
char *dup_chars(char *patthstr, int startt, int stops)
{
		static char buf[1024];
			int x = 0, y = 0;

				for (y = 0, x = startt; x < stops; x++)
							if (patthstr[x] != ':')
											buf[y++] = patthstr[x];
					buf[y] = 0;
						return (buf);
}

/**
 *  * iss_cmd - func determines if a file is executable
 *   * @inff: the inff struct
 *    * @patth: patth to the file
 *     *
 *      * Return: 1 if true, 0 otherwise
 *       */
int iss_cmd(inff_t *inff, char *patth)
{
		struct stat st;

			(void)inff;
				if (!patth || stat(patth, &st))
							return (0);

					if (st.st_mode & S_IFREG)
							{
										return (1);
											}
						return (0);
}

/**
 *  * find_patth - func finds this cmd in the patth string
 *   * @inff: the inff struct containing arguments
 *    * @patthstr: the patth of the string
 *     * @cmd: the cmd to find
 *      *
 *       * Return: cmd patth
 *        * or NULL
 *         */
char *find_patth(inff_t *inff, char *patthstr, char *cmd)
{
		int t = 0, curr_pos = 0;
			char *patth;

				if (!patthstr)
							return (NULL);
					if ((_strlen(cmd) > 2) && startts_with(cmd, "./"))
							{
										if (iss_cmd(inff, cmd))
														return (cmd);
											}
						while (1)
								{
											if (!patthstr[t] || patthstr[t] == ':')
														{
																		patth = dup_chars(patthstr, curr_pos, t);
																					if (!*patth)
																										_strcat(patth, cmd);
																								else
																												{
																																	_strcat(patth, "/");
																																					_strcat(patth, cmd);
																																								}
																											if (iss_cmd(inff, patth))
																																return (patth);
																														if (!patthstr[t])
																																			break;
																																	curr_pos = t;
																																			}
													t++;
														}
							return (NULL);
}#include "shell.h"

/**
 *  * find_patth - func finds this cmd in the patth string
 *   * @inff: the inff struct containing arguments
 *    * @patthstr: the patth of the string
 *     * @cmd: the cmd to find
 *      *
 *       * Return: cmd patth
 *        * or NULL
 *         */
char *find_patth(inff_t *inff, char *patthstr, char *cmd)
{
		int t = 0, curr_pos = 0;
			char *patth;

				if (!patthstr)
							return (NULL);
					if ((_strlen(cmd) > 2) && startts_with(cmd, "./"))
							{
										if (iss_cmd(inff, cmd))
														return (cmd);
											}
						while (1)
								{
											if (!patthstr[t] || patthstr[t] == ':')
														{
																		patth = dup_chars(patthstr, curr_pos, t);
																					if (!*patth)
																										_strcat(patth, cmd);
																								else
																												{
																																	_strcat(patth, "/");
																																					_strcat(patth, cmd);
																																								}
																											if (iss_cmd(inff, patth))
																																return (patth);
																														if (!patthstr[t])
																																			break;
																																	curr_pos = t;
																																			}
													t++;
														}
							return (NULL);
}


/**
 *  * iss_cmd - func determines if a file is executable
 *   * @inff: the inff struct
 *    * @patth: patth to the file
 *     *
 *      * Return: 1 if true, 0 otherwise
 *       */
int iss_cmd(inff_t *inff, char *patth)
{
		struct stat st;

			(void)inff;
				if (!patth || stat(patth, &st))
							return (0);

					if (st.st_mode & S_IFREG)
							{
										return (1);
											}
						return (0);
}

/**
 *  * dup_chars - func duplicates set of chars
 *   * @patthstr: the patth of string
 *    * @startt: startting index
 *     * @stops: stopsping index
 *      *
 *       * Return: pointer to new buffer
 *        */
char *dup_chars(char *patthstr, int startt, int stops)
{
		static char buf[1024];
			int x = 0, y = 0;

				for (y = 0, x = startt; x < stops; x++)
							if (patthstr[x] != ':')
											buf[y++] = patthstr[x];
					buf[y] = 0;
						return (buf);
}