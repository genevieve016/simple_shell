#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
#define MAX_ENV_VARS 100

/**
 * struct data_shell_s - name of struct
 * struct data_shell - data structure for the shell
 * @av: array of strings representing the command-line args
 * @_environ: array of strings representing environment variables
 * @input: string representing user input
 * @args: array of strings representing arguments parsed from user input
 * @status: exit status of the last executed command
 * @counter: command counter
 * @pid: string representation of the current process ID
 */

/* data structure to hold shell data */
struct data_shell_s
{
	char **av;
	char **_environ;
	char *input;
	char **args;
	char *pid;
	int status;
	int counter;
};
typedef struct data_shell_s data_shell;

/* function to free memory */
void free_data(data_shell *datash);

/* function to set up shell data structure */
void set_data(data_shell *datash, char **av);

/* function to enter loop and execute user commands */
void shell_loop(data_shell *datash);

/* main function */
int main(int ac, char **av);

#endif
