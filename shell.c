#include "shell.h"

/**
 * free_data - frees memory allocated for data structure
 * @datash: pointer to datash data structure
 *
 * Return: void
 */

void free_data(data_shell *datash)
{
	char **env = datash->environ;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		free(env[i]);
	}
	free(env);
	free(datash->pid);
}

/**
 * set_data - initializes datash data structure
 * @datash: pointer to datash data structure
 * @av: array of strings representing the command-line args
 *
 * Return: void
 */

void set_data(data_shell *datash, char **av)
{
	int i, environ_len = 0;

  /* Count the number of environment variables. */
	for (i = 0; environ[i] != NULL; i++)
	{
		environ_len++;
	}

  /* Set members of the data_shell struct. */
	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;
	datash->pid = malloc(10 * sizeof(char));
	sprintf(datash->pid, "%d", getpid());

  /* Allocate memory for the environ array. */
	datash->environ = malloc((environ_len + 1) * sizeof(char *));
	for (i = 0; environ[i] != NULL; i++)
	{
		datash->environ[i] = strdup(environ[i]);
	}
	datash->environ[i] = NULL;
}

/**
 * Signal handler for SIGINT (Ctrl-C).
 */
void sigint_handler(int sig_num)
{
  /* Reset the signal handler to this function. */
	signal(SIGINT, sigint_handler);
}

/**
 * main - entry point of the program
 * @ac: number of command-line arguments
 * @av: array of strings representing the command-line arguments
 *
 * Return: integer (0 on success)
 */

int main(int ac, char **av)
{
	data_shell datash;

	signal(SIGINT, sigint_handler);

	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	return (datash.status < 0 ? 255 : datash.status);
}
