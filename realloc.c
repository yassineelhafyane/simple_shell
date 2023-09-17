#include "shell.h"

/**
 *  * ffree - func frees a string of strings
 *   * @pp: string of strings to be freed
 *    *
 *     * Return: nothing
 *      */
void ffree(char **pp)
{
		char **a = pp;

			if (!pp)
						return;
				while (*pp)
							free(*pp++);
					free(a);
}

/**
 *  **_memset - func fills memoryy with a constantt byte
 *   *@s: pointer to the memoryy area
 *    *@b: byte to fill *s (pointer) with
 *     *@n: amount of bytes to be filled
 *      *Return: (s) a pointer to the memoryy area s
 *       */
char *_memset(char *s, char b, unsigned int n)
{
		unsigned int t;

			for (t = 0; t < n; t++)
						s[t] = b;
				return (s);
}

/**
 *  * _realloc - func reallocates a block of memoryy
 *   * @ptr: pointer to previous memoryy block malloced
 *    * @old_size: previous block size
 *     * @new_size: new block size
 *      *
 *       * Return: pointer to de allocated memoryy block
 *        */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
		char *p;

			if (!ptr)
						return (malloc(new_size));
				if (!new_size)
							return (free(ptr), NULL);
					if (new_size == old_size)
								return (ptr);

						p = malloc(new_size);
							if (!p)
										return (NULL);

								old_size = old_size < new_size ? old_size : new_size;
									while (old_size--)
												p[old_size] = ((char *)ptr)[old_size];
										free(ptr);
											return (p);
}#include "shell.h"


/**
 *  * _realloc - func reallocates a block of memoryy
 *   * @ptr: pointer to previous memoryy block malloced
 *    * @old_size: previous block size
 *     * @new_size: new block size
 *      *
 *       * Return: pointer to de allocated memoryy block
 *        */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
		char *p;

			if (!ptr)
						return (malloc(new_size));
				if (!new_size)
							return (free(ptr), NULL);
					if (new_size == old_size)
								return (ptr);

						p = malloc(new_size);
							if (!p)
										return (NULL);

								old_size = old_size < new_size ? old_size : new_size;
									while (old_size--)
												p[old_size] = ((char *)ptr)[old_size];
										free(ptr);
											return (p);
}


/**
 *  **_memset - func fills memoryy with a constantt byte
 *   *@s: pointer to the memoryy area
 *    *@b: byte to fill *s (pointer) with
 *     *@n: amount of bytes to be filled
 *      *Return: (s) a pointer to the memoryy area s
 *       */
char *_memset(char *s, char b, unsigned int n)
{
		unsigned int t;

			for (t = 0; t < n; t++)
						s[t] = b;
				return (s);
}

/**
 *  * ffree - func frees a string of strings
 *   * @pp: string of strings to be freed
 *    *
 *     * Return: nothing
 *      */
void ffree(char **pp)
{
		char **a = pp;

			if (!pp)
						return;
				while (*pp)
							free(*pp++);
					free(a);
}


