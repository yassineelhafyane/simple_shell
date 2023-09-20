#include "shell.h"


void _eputs(char *str)
{
		int j = 0;

			if (!str)
						return;
				while (str[j] != '\0')
						{
									_eputchar(str[j]);
											j++;
												}
}


int _eputchar(char m)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (m == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(2, buf, j);
											j = 0;
												}
					if (m != BUF_FLUSH)
								buf[j++] = m;
						return (1);
}


int _putfd(char d, int fd)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(fd, buf, j);
											j = 0;
												}
					if (d != BUF_FLUSH)
								buf[j++] = d;
						return (1);
}


int _putsfd(char *string, int fn)
{
		int j = 0;

			if (!string)
						return (0);
				while (*string)
						{
									j += _putfd(*string++, fn);
										}
					return (j);
}#include "shell.h"


void _eputs(char *str)
{
		int j = 0;

			if (!str)
						return;
				while (str[j] != '\0')
						{
									_eputchar(str[j]);
											j++;
												}
}


int _eputchar(char u)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (u == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(2, buf, j);
											j = 0;
												}
					if (u != BUF_FLUSH)
								buf[j++] = u;
						return (1);
}


int _putfd(char d, int fn)
{
		static int j;
			static char buf[WRITE_BUF_SIZE];

				if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
						{
									write(fn, buf, j);
											j = 0;
												}
					if (d != BUF_FLUSH)
								buf[j++] = d;
						return (1);
}


int _putsfd(char *string, int fn)
{
		int j = 0;

			if (!string)
						return (0);
				while (*string)
						{
									j += _putfd(*string++, fn);
										}
					return (j);
}
