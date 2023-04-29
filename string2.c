#include "shell.h"

/**
 * comp_chars - function to compare characters of two strings
 * @str: input string
 * @delim: delimiter string
 *
 * Return: 1 if strings are similar, else 0
 */
int comp_chars(const char *str, const char *delim)
{
	while (*str && *delim)
	{
		if (*str != *delim)
		{
			return (0);
		}

		str++;
		delim++;
	}

	return (*str == *delim);
}

/**
 * _str_tok - function to split a string by a delimiter
 * @str: input string
 * @delim: delimiter string
 *
 * Return: pointer (Success), else NULL
 */
char *_str_tok(char *str, const char *delim)
{
	static char *next_token;

	if (str)
	{
		next_token = str;
	}

	if (!*next_token)
	{
		return (NULL);
	}

	char *token_start = next_token;

	while (*next_token)
	{
		if (comp_chars(next_token, delim))
		{
			*next_token = '\0';
			next_token++;
			return (token_start);
		}

		next_token++;
	}

	return (token_start);
}

/**
 * _str_concat - function to concatenate two strings
 *
 * @dest: pointer to destination string
 * @src: pointer to source string
 *
 * Return: pointer to destination string
 */
char *_str_concat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _str_chr - function to locate character in a string
 *
 * @s: string
 * @c: character to check for
 *
 * Return: pointer to character if found, else NULL
 */
char *_str_chr(char *s, char c)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (&s[i]);

	if (s[i] == c)
		return (&s[i]);

	return (NULL);
}
