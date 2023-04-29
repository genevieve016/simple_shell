#include "shell.h"

/**
 * cd_error - function to make error message for cd
 * @data: data
 *
 * Return: the error message
 */
char *cd_error(data_sh *data)
{
	char *error, *ver_str, *msg;
	int length;

	ver_str = aux_itoa(data->counter);
	msg = (data->args[1][0] == '-')
			? ": Error!  -%c\n"
			: ": %s: unable to cd to %s\n";

	length = _str_len(data->av[0]) + _strlen(ver_str) + _strlen(msg) +
		 _str_len(data->args[0]) + _strlen(data->args[1]) + 3;

	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(ver_str);
		return (NULL);
	}

	sprintf(error, "%s: %d: %s",
		data->av[0],
		data->counter,
		msg,
		data->args[0],
		data->args[1][0] == '-' ? data->args[1][1] : data->args[1]
		);

	free(ver_str);

	return (error);
}

/**
 * not_found_error - function to make error message for command not found
 * @data: data
 *
 * Return: the error message
 */
char *not_found_error(data_sh *data)
{
	char *error, *ver_str;
	int length;

	ver_str = aux_itoa(data->counter);

	length = _strlen(data->av[0]) + _strlen(ver_str) +
		_strlen(": %s: is not found\n") +
		_strlen(data->args[0]) + 1;

	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(ver_str);
		return (NULL);
	}

	sprintf(error, "%s: %d: %s: is not found\n", data->av[0],
			data->counter, data->args[0]);
	free(ver_str);

	return (error);
}

/**
 * exit_error - function to make error message for exit command
 * @data: data
 *
 * Return: the error message
 */
char *exit_error(data_sh *data)
{
	char *error, *ver_str;
	int length;

	ver_str = aux_itoa(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str) +
		_strlen(": %s: Exit error!: %s\n")
		+ _strlen(data->args[0]) + _strlen(data->args[1]) + 1;

	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(ver_str);
		return (NULL);
	}

	sprintf(error, "%s: %d: %s: Exit error!: %s\n", data->av[0],
			data->counter, data->args[0], data->args[1]);
	free(ver_str);

	return (error);
}

/**
 * env_error - function to make error message for environment
 * @data: data
 *
 * Return: error message
 */
char *env_error(data_sh *data)
{
	int length = 0;
	char *error = NULL;
	char *ver_str = NULL;
	char *msg = ": Unable to add/remove from environment\n";

	ver_str = aux_itoa(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(ver_str);
		return (NULL);
	}

	_str_cpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * path_error - function to make error message for path
 * @data: data
 *
 * Return: error message
 */
char *path_error(data_sh *data)
{
	int length = 0;
	char *ver_str = NULL;
	char *error = NULL;

	ver_str = aux_itoa(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
