#include "shell.h"

/**
 * _str_dup - duplicate a string
 *
 * @s: string
 *
 * Return: pointer to string duplicate
 */
char *_str_dup(const char *s)
{
	char *new_str;
	size_t len;

	len = _str_len(s);
	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);

	_mem_cpy(new_str, s, len + 1);

	return (new_str);
}


/**
 * _str_len - function to get length of string
 * @s: pointer to string char
 *
 * Return: string length
 */
size_t _str_len(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}


/**
 * rev_string - function to reverse a string
 * @s: input string
 *
 * Return: void
 */
void rev_string(char *s)
{
	if (!s)
	{
		return;
	}

	size_t len = _str_len(s);

	for (size_t i = 0; i < len / 2; i++)
	{
		char temp = s[i];

		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
