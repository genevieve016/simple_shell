/**
 * print_help_env - prints desc of env to stdout
 *
 * Return: void
 */

void print_help_env(void)
{
	print_help_env("env", "Print shell environment");
}

/**
 * print_help_setenv - prints desc of setenv to stdout
 *
 * Return: void
 */

void print_help_setenv(void)
{
	print_help("setenv", "New shell environment");
}

/**
 * print_help_unsetenv - prints desc of the unsetenv to stdout
 *
 * Return: void
 */

void print_help_unsetenv(void)
{
	print_help("unsetenv", "Remove from environment");
}
