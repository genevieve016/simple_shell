#include "shell.h"

/**
 * is_interactive - checks if shell is in interactive mode
 * @info: pointer to the info struct
 *
 * Return: 1 if shell is interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter string
 *
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: character to check
 *
 * Return: 1 if c is an alphabetic character, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted number, 0 if no numbers in string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, flag = 0, output = 0;
	unsigned int result = 0;

	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = (result * 10) + (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}
	output = sign * result;
	return (output);
}
