#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/**
 * interactive - true if shell is interactive
 *
 * Return: 1 (True), 0 (Otherwise)
 */

int interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * is_delim - to check if character is delimeter
 * @c: the char to check
 * @delim: delimeter string
 * Return: 1 (True), 0 (False)
 */

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}

/**
 * _isalpha - to check for alphabetic character
 * @c: char to input
 * Return: 1 (True), 0 (False)
 */

int _isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}

/**
 * _atoi - to converts a string to an integer
 * @s: string to convert
 * Return: 0 (No integer), 1 (Converted Integer)
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

void read_input(char *command);
void tokenize_input(char *command, char **args, int *num_args);
void execute_command(char **args);

/**
 * main - program entry point
 *
 * Return: 0 (Success), 1 (Failure)
 *
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGUMENTS + 2];
	int num_args;

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
 * read_input - reads a line of input from the user
 * @command: buffer to store the input in
 */

void read_input(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\n");
		return (0);
	}
	command[strcspn(command, "\n")] = '\0';
}

/**
 * tokenize_input - tokenizes a line of input into arguments
 * @command: line of input to tokenize
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
