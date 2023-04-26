#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	ssize_t read_len;

	while (1)
	{
		display_prompt(command);
		read_len = getline(&command, &command_len, stdin);

		if (read_len == -1) /* End of file (Ctrl+D) */
		{
			printf("\n");
			break;
		}
		/* Remove trailing newline character */

		if (command[read_len - 1] == '\n')
			command[read_len - 1] = '\0';
		execute_command(command);
	}

	free(command);
	return (0);
}

/**
 * display_prompt - Display the shell prompt
 *
 * @command: The command entered by the user
 */

void display_prompt(char *command)
{
	if (isatty(STDIN_FILENO))
	{
		if (command != NULL && command[0] != '\0')
			printf("\n");
		printf("$ ");
		fflush(stdout);
	}
}

/**
 * execute_command - Execute a command entered by the user
 *
 * @command: The command entered by the user
 */

void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* Child process */
	{
		/* Use execve to execute the command */
		if (execve(command, NULL, NULL) == -1)
		{
			printf("%s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		do {
		       waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
