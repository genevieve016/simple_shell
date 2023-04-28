shell.c

#include "shell.h"

/**
 * init_data - function to initialise data structure
 * @data: pointer to data structure
 * @args: pointer to argument vector
 *
 * Return: void
 */

void init_data(data_sh * data, char **args)
{
	data->av = args;
	data->input = NULL;
	data->args = NULL;
	data->status = 0;
	data->counter = 1;

	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		i++;
	}

	data->_environ = (char **) malloc(sizeof(char *) * (i + 1));
	for (unsigned int j = 0; j < i; j++)
	{
		data->_environ[j] = _strdup(environ[j]);
	}
	data->_environ[i] = NULL;
	data->pid = aux_itoa(getpid());
}

/**
 * free_data - function to free data structure
 * @data: pointer to data structure
 *
 * Return: void
 */

void free_data(data_sh *data)
{
	for (unsigned int i = 0; data->_environ[i]; i++)
	{
		free(data->_environ[i]);
	}
	free(data->_environ);
	free(data->pid);
}

/**
 * main - entry point function
 * @argc: number of arguments
 * @argv: pointer to argument vector
 *
 * Return: 0 (Success), 225 (Failure)
 */

int main(int argc, char **argv)
{
	data_sh data;
	(void) argc;

	signal(SIGINT, get_sigint);
	init_data(&data, argv);

	sh_loop(&data);

	free_data(&data);
	if (data.status < 0)
	{
		return (255);
	}
	return (data.status);
}

