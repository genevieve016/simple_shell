#include "shell.h"

/**
 * print_help - prints desc of a given command to stdout
 *
 * @command: name of command
 * @desc: description of command
 *
 * Return: void
 */

void print_help(const char *command, const char *desc)
{
	char buf[1024];
	int len = snprintf(buf, sizeof(buf), "%s: %s\n\t", command, desc);

	write(STDOUT_FILENO, buf, len);
}

/**
 * gen_print_help - prints list of commands and descriptions to stdout
 *
 * Return: void
 */

void gen_print_help(void)
{
	const char *header = "^-^ bash, version 1.0(1)-release\n";
	const char *intro = "For list of commands, type 'help'\n";
	const char *intro2 = "For more information, type help then function name\n\n";

	write(STDOUT_FILENO, header, strlen(header));
	write(STDOUT_FILENO, intro, strlen(intro));
	write(STDOUT_FILENO, intro2, strlen(intro2));

	print_help("alias", "alias [name=['string']]");
	print_help("cd", "cd [-L|[-P [-e]] [-@]] [dir]");
	print_help("exit", "exit [n]");
	print_help("env", "env [option] [name=value] [command [args]]");
	print_help("setenv", "setenv [variable] [value]");
	print_help("unsetenv", "unsetenv [variable]");
}


/**
 * print_help_exit - prints desc of the 'exit' command to stdout
 *
 * Return: void
 */

void print_help_exit(void)
{
	print_help("exit", "Exit shell");
	const char *desc = "Exits the shell with N status\n";

	write(STDOUT_FILENO, desc, strlen(desc));
}
