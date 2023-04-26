#include "shell.h"

void read_input(char *command);
void tokenize_input(char *command, char **args, int *num_args);
void exec_command(char **args);

/**
 * main - program entry point
 *
 * Return: 0 (Success), 1 (Failure)
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGUMENTS + 2];
	int status;

	while (1)
	{
		printf("($) ");
		read_input(command);
		tokenize_input(command, args, &num_args);
		exec_command(args);
	}
	return (0);
}

/**
 * read_input - read user inout
 * @command: input stored in this buffer
 */

void read_input(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\n");
		return (0);
	}
	command[strcspn(command, "\n")] = '\0'; /* remove trailing line*/
}

/**
 * tokenize_input - tokenizes user input into arguments
 * @command: user input to tokenize
 * @args: array to store arguments in
 * @num_args: pointer to number of arguments found
 */

void tokenize_input(char *command, char **args, int *num_args)
{
	*num_args = 0;

	args[*num_args++] = strtok(command, " ");

	while (args[*num_args - 1] != NULL && *num_args <= MAX_ARGUMENTS)
	{
		args[*num_args++] = strtok(NULL, " ");
	}

	if (*num_args > MAX_ARGUMENTS + 1)
	{
		printf("Input a maximum of %d arguments.\n", MAX_ARGUMENTS);
		*num_args = 0;
	}
}

/**
 * exec_command - forks child process and executes command
 * @args: array pf arguments for command
 */

void exec_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		return (1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("Command not found: %s\n", args[0]);
			return (1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
