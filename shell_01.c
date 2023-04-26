#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - main function
 *
 * Return: 0
 *
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &bufsize, stdin) == -1)
		{
			printf("\n");
			break;
		}
		line[strcspn(line, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = { line, NULL };

			execve(line, args, NULL);
			perror(line);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	exit(EXIT_SUCCESS);
}
