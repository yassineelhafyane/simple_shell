#include "shell.h"

int _myexit(info_t *infos)
{
		int exitcheck;

			if (infos->argv[1])  /* If  an exit arguement exists*/
					{
								exitcheck = _erratoi(infos->argv[1]);
										if (exitcheck == -1)
													{
																	infos->status = 2;
																				print_error(infos, "Illegal number: ");
																							_eputs(infos->argv[1]);
																										_eputchar('\n');
																													return (1);
																															}
												infos->err_num = _erratoi(infos->argv[1]);
														return (-2);
															}
				infos->err_num = -1;
					return (-2);
}



int _mycd(info_t *ifos)
{
		char *z, *dr, buffer[1024];
			int chdir_ret;

				z = getcwd(buffer, 1024);
					if (!z)
								_puts("TODO: >>getcwd failure msg here<<\n");
						if (!ifos->argv[1])
								{
											dr = _getenv(ifos, "HOME=");
													if (!dr)
																	chdir_ret = /* TODO: what should it be? */
																						chdir((dr = _getenv(ifos, "PWD=")) ? dr : "/");
															else
																			chdir_ret = chdir(dr);
																}
							else if (_strcmp(ifos->argv[1], "-") == 0)
									{
												if (!_getenv(ifos, "OLDPWD="))
															{
																			_puts(z);
																						_putchar('\n');
																									return (1);
																											}
														_puts(_getenv(ifos, "OLDPWD=")), _putchar('\n');
																chdir_ret = /* TODO: what should it be? */
																				chdir((dr = _getenv(ifos, "OLDPWD=")) ? dr : "/");
																	}
								else
											chdir_ret = chdir(ifos->argv[1]);
									if (chdir_ret == -1)
											{
														print_error(ifos, "can't cd to ");
																_eputs(ifos->argv[1]), _eputchar('\n');
																	}
										else
												{
															_setenv(ifos, "OLDPWD", _getenv(ifos, "PWD="));
																	_setenv(info, "PWD", getcwd(buffer, 1024));
																		}
											return (0);
}


int _myhelp(info_t *infos)
{
		char **arg_arr;

			arg_arr = infos->argv;
				_puts(" Function not yet implemented \n");
					if (0)
								_puts(*arg_arr); /* Temp att_unused  */
						return (0);
}#include "shell.h"


int _myexit(info_t *infos)
{
		int exitcheck;

			if (infos->argv[1])  /* If  an exit arguement exists*/
					{
								exitcheck = _erratoi(infos->argv[1]);
										if (exitcheck == -1)
													{
																	infos->status = 2;
																				print_error(infos, "Illegal number: ");
																							_eputs(infos->argv[1]);
																										_eputchar('\n');
																													return (1);
																															}
												infos->err_num = _erratoi(infos->argv[1]);
														return (-2);
															}
				infos->err_num = -1;
					return (-2);
}


int _mycd(info_t *infos)
{
		char *z, *dr, buffer[1024];
			int chdir_ret;

				z = getcwd(buffer, 1024);
					if (!z)
								_puts("TODO: >>getcwd failure msg here<<\n");
						if (!infos->argv[1])
								{
											dr = _getenv(infos, "HOME=");
													if (!dr)
																	chdir_ret = /* TODO: what should it be? */
																						chdir((dr = _getenv(infos, "PWD=")) ? dr : "/");
															else
																			chdir_ret = chdir(dr);
																}
							else if (_strcmp(infos->argv[1], "-") == 0)
									{
												if (!_getenv(infos, "OLDPWD="))
															{
																			_puts(z);
																						_putchar('\n');
																									return (1);
																											}
														_puts(_getenv(infos, "OLDPWD=")), _putchar('\n');
																chdir_ret = /* TODO: what should it be? */
																				chdir((dr = _getenv(infos, "OLDPWD=")) ? dr : "/");
																	}
								else
											chdir_ret = chdir(infos->argv[1]);
									if (chdir_ret == -1)
											{
														print_error(infos, "can't cd to ");
																_eputs(infos->argv[1]), _eputchar('\n');
																	}
										else
												{
															_setenv(infos, "OLDPWD", _getenv(infos, "PWD="));
																	_setenv(infos, "PWD", getcwd(buffer, 1024));
																		}
											return (0);
}


int _myhelp(info_t *infos)
{
		char **arg_arr;

			arg_arr = infos->argv;
				_puts(" Function not yet implemented \n");
					if (0)
								_puts(*arg_arr); /* Temp att_unused  */
						return (0);
}
