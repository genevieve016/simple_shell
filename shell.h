#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Data structures */
/**
 * struct info_s - stores information needed for the shell to work
 * @args: array of strings containing the parsed arguments
 * @line: string containing the line input
 * @readfd: file descriptor for reading input
 * @env: array of strings containing the environment variables
 * @program_name: name of the program
 * @exit_status: last exit status of a command
 */
typedef struct info_s
{
	char **args;
	char *line;
	int readfd;
	char **env;
	char *program_name;
	int exit_status;
}

info_t;

/* Function prototypes */
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
void prompt(info_t *info);
char *_getline(info_t *info);
char **_parse_line(info_t *info);
void execute(info_t *info);
void free_info(info_t *info);
void print_error(info_t *info, char *command);

#endif /* SHELL_H */

