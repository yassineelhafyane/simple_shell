#include "shell.h"


int _erratoi(char *str)
{
		int j = 0;
			unsigned long int result = 0;

				if (*str == '+')
							str++;  
					for (j = 0;  str[j] != '\0'; j++)
							{
										if (str[j] >= '0' && str[j] <= '9')
													{
																	result *= 10;
																				result += (str[j] - '0');
																							if (result > INT_MAX)
																												return (-1);
																									}
												else
																return (-1);
													}
						return (result);
}


void print_error(info_t *info, char *ett)
{
		_eputs(info->fname);
			_eputs(": ");
				print_d(info->line_count, STDERR_FILENO);
					_eputs(": ");
						_eputs(info->argv[0]);
							_eputs(": ");
								_eputs(ett);
}


int print_d(int inp, int fs)
{
		int (*__putchar)(char) = _putchar;
			int i, count = 0;
				unsigned int _abs_, current;

					if (fs == STDERR_FILENO)
								__putchar = _eputchar;
						if (inp < 0)
								{
											_abs_ = -inp;
													__putchar('-');
															count++;
																}
							else
										_abs_ = inp;
								current = _abs_;
									for (i = 1000000000; i > 1; i /= 10)
											{
														if (_abs_ / i)
																	{
																					__putchar('0' + current / i);
																								count++;
																										}
																current %= i;
																	}
										__putchar('0' + current);
											count++;

												return (count);
}


char *convert_number(long int mn, int base, int flags)
{
		static char *arr;
			static char buffer[50];
				char sign = 0;
					char *pt;
						unsigned long m  = mn;

							if (!(flags & CONVERT_UNSIGNED) && mn < 0)
									{
												m = -mn;
														sign = '-';

															}
								arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
									pt = &buffer[49];
										*pt = '\0';

											do	{
														*--pt = arr[m % base];
																m /= base;
																	} while (m != 0);

												if (sign)
															*--pt = sign;
												return (pt);
}


void remove_comments(char *fubb)
{
		int i;

			for (i = 0; fubb[i] != '\0'; i++)
						if (fubb[i] == '#' && (!i || fubb[i - 1] == ' '))
									{
													fubb[i] = '\0';
																break;
																		}
}#include "shell.h"


int _erratoi(char *string)
{
		int j = 0;
			unsigned long int result = 0;

				if (*string == '+')
							string++;  
					for (j = 0;  string[j] != '\0'; j++)
							{
										if (string[j] >= '0' && string[j] <= '9')
													{
																	result *= 10;
																				result += (string[j] - '0');
																							if (result > INT_MAX)
																												return (-1);
																									}
												else
																return (-1);
													}
						return (result);
}


void print_error(info_t *infos, char *et)
{
		_eputs(infos->fname);
			_eputs(": ");
				print_d(infos->line_count, STDERR_FILENO);
					_eputs(": ");
						_eputs(infos->argv[0]);
							_eputs(": ");
								_eputs(et);
}


int print_d(int inpout, int fn)
{
		int (*__putchar)(char) = _putchar;
			int i, count = 0;
				unsigned int _abs_, current;

					if (fn == STDERR_FILENO)
								__putchar = _eputchar;
						if (inpout < 0)
								{
											_abs_ = -inpout;
													__putchar('-');
															count++;
																}
							else
										_abs_ = inpout;
								current = _abs_;
									for (i = 1000000000; i > 1; i /= 10)
											{
														if (_abs_ / i)
																	{
																					__putchar('0' + current / i);
																								count++;
																										}
																current %= i;
																	}
										__putchar('0' + current);
											count++;

												return (count);
}


char *convert_number(long int nm, int dab, int flagues)
{
		static char *arr;
			static char buffer[50];
				char sign = 0;
					char *pt;
						unsigned long m  = nm;

							if (!(flagues & CONVERT_UNSIGNED) && nm < 0)
									{
												m = -nm;
														sign = '-';

															}
								arr = flagues & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
									pt = &buffer[49];
										*pt = '\0';

											do	{
														*--pt = arr[m % dab];
																m /= dab;
																	} while (m != 0);

												if (sign)
															*--pt = sign;
												return (pt);
}


void remove_comments(char *buffer)
{
		int j;

			for (j = 0; buffer[j] != '\0'; j++)
						if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
									{
													buffer[j] = '\0';
																break;
																		}
}
