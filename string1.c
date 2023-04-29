#include "shell.h"

/**
 * _str_cpy - function to copy a string to buffer
 *
 * @dest: pointer to destination buffer
 * @src: pointer to source string
 *
 * Return: pointer to destination buffer
 */
char *_str_cpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _str_cmp - function to compare two strings
 *
 * @s1: string1
 * @s2: string2
 *
 * Return: Integer indicating the comparison
 */
int _str_cmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] < s2[i])
		return (-1);
	if (s1[i] > s2[i])
		return (1);

	return (0);
}

/**
 * _str_spn - function to find length of prefix substring
 *
 * @s: string
 * @accept: bytes to accept
 *
 * Return: number of @accept
 */
int _str_spn(char *s, char *accept)
{
	int i, j, found;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (!found)
			break;
	}

	return (i);
}

/**
 * _is_digit - function to determine if string represents a digit
 * @s: input string
 *
 * Return: 1 if true, else 0
 */
int _is_digit(const char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
		{
			return (0);
		}

		s++;
	}

	return (1);
}
