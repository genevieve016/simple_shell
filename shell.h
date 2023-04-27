#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define PROMPT "$ "

/**
 * struct info - info struct
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment vector
 * @lineptr: pointer to the input string
 * @line_count: number of lines
 * @fname: the file name
 * @status: status
 * @exit_code: exit code
 */
typedef struct info
{
	int argc;
	char **argv;
	char **environ;
	list_t *env;
	int env_changed;
	char *lineptr;
	size_t line_count;
	char *fname;
	int status;
	int exit_code;
} info_t;

int _putchar(char c);
void _puts(char *s);
void _eputs(char *s);
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);
char **list_to_strings(list_t *list);
void free_str_arr(char **arr);
list_t *array_to_list(char **array);
void free_list(list_t **list);
char *starts_with(const char *str, const char *prefix);
int delete_node_at_index(list_t **head, size_t index);
int add_node_end(list_t **head, char *str, size_t len);
size_t print_list(list_t *h);
size_t list_len(list_t *h);
list_t *find_node(list_t *head, const char *str);
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);

#endif /* SHELL_H */

