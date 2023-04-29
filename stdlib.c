#include "shell.h"

/**
 * num_len - function to return length of int
 * @n: integer
 * Return: length of integer
 */
int num_len(int n)
{
	unsigned int m;
	int len = 1;

	if (n > 0)
	{
		m = n;
	}
	else
	{
		len++;
		m = n * -1;
	}

	while (m > 9)
	{
		len++;
		m /= 10;
	}

	return (len);
}

/**
 * int_to_string - converts an integer to a string
 * @n: integer
 * Return: string
 */
char *int_to_string(int n)
{
	unsigned int m;
	int len = num_len(n);
	char *str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	*(str + len) = '\0';

	if (n > 0)
	{
		m = n;
	}
	else
	{
		m = n * -1;
		str[0] = '-';
	}

	len--;
	do {
		*(str + len) = (m % 10) + '0';
		m /= 10;
		len--;
	} while (m > 0);

	return (str);
}

/**
 * string_to_int - converts a string to an integer
 * @s: input string
 * Return: integer
 */
int string_to_int(char *s)
{
	unsigned int count = 0, size = 0, output_int = 0, pos_neg = 1, mult = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pos_neg *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				mult *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		output_int = output_int + ((*(s + i) - 48) * mult);
		mult /= 10;
	}
	return (output_int * pos_neg);
}
