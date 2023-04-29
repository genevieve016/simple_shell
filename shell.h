#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data_sh - struct containing data
 * @args: arguments
 * @env: environment
 * @status: status
 */

typedef struct data_sh
{
	char **args;
	char **env;
	int status;
} data_sh;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_sh;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * desc: struct sep_list_s to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_sh *datash);
} builtin_t;

/* cd_builtin.c */

int cd_shell(data_sh *data);

/* cd.c */

void cd_parent(data_sh *data);
void cd_to_other(data_sh *data);
void cd_to_previous(data_sh *data);
void cd_home(data_sh *data);

/* error_file.c */

char *cd_error(data_sh *data);
char *not_found_error(data_sh *data);
char *exit_error(data_sh *data);
char *env_error(data_sh *data);
char *path_error(data_sh *data);

/*  help_comm.c */

void disp_help(void);
void disp_alias(void);
void disp_cd(void);

/*  help_file.c */

void print_help(const char *command, const char *desc);
void gen_print_help(void);
void print_help_exit(void);

/* help_file_env.c */

void print_help_env(void);
void print_help_setenv(void);
void print_help_unsetenv(void);

/* list_file.c */

sep_list *add_separator_node(sep_list **head, char separator);
void free_separator_list(sep_list **head);
line_list *add_line_node(line_list **head, char *line);
void free_line_list(line_list **head);

/* mem_file.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realloc_dp(char **ptr, unsigned int old_size, unsigned int new_size);
void copy_data(void *new_ptr, const void *ptr, unsigned int size);

/* shell.c */

void init_data(data_sh *data, char **args);
void free_data(data_sh *data);
int main(int argc, char **argv);

/* stdlib.c */

int num_len(int n);
char *int_to_string(int n);
int string_to_int(char *s);

/* string1.c */

char *_str_cpy(char *dest, char *src);
int _str_cmp(char *s1, char *s2);
int _str_spn(char *s, char *accept);
int _is_digit(const char *s);

/* string2.c */

int comp_chars(const char *str, const char *delim);
char *_str_tok(char *str, const char *delim);
char *_str_concat(char *dest, const char *src);
char *_str_chr(char *s, char c);


/* string3.c */

char *_str_dup(const char *s);
size_t _str_len(const char *s);
void rev_string(char *s);

/* var_list.c */

r_var *add_variable(r_var **head, int var_len, char *value, int value_length);
void free_variable_list(r_var **head);


#endif
