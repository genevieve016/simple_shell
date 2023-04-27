#include "shell.h"

/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			exit(1);
		delim++;
	}
	exit(0);
}
