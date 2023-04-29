#include "shell.h"

/**
 * disp_help - display information for help
 *
 * Return: void
 */
void disp_help(void)
{
	char *help_msg = "help: help [-dms] [pattern ...]\n"
				"\tShow builtin commands details.\n"
				"\tShow builtin commands summaries.\n";

	write(STDOUT_FILENO, help_msg, _str_len(help_msg));
}

/**
 * disp_alias - display information for alias
 *
 * Return: void
 */
void disp_alias(void)
{
	char *alias_msg = "alias: alias [-p] [name[=value]...]\n"
				"\tDisplay alias.\n";

	write(STDOUT_FILENO, alias_msg, _strlen(alias_msg));
}

/**
 * disp_cd - display information for cd
 *
 * Return: void
 */
void disp_cd(void)
{
	char *cd_msg = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n"
				"\tTo change working directory.\n";

	write(STDOUT_FILENO, cd_msg, _strlen(cd_msg));
}
