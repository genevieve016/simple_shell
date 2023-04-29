#include "shell.h"

/**
 * cd_shell - changes the current directory
 *
 * @data: data relevant (environ)
 * Return: 1 on success, 0 on failure
 */
int cd_shell(data_sh *data)
{
	char *dir = data->args[1];
	int is_home = (dir != NULL) &&
		(_str_cmp("$HOME", dir) == 0 || _str_cmp("~", dir) == 0);
	int is_dashdash = (dir != NULL) && (_str_cmp("--", dir) == 0);
	int is_dash = (dir != NULL) && (_str_cmp("-", dir) == 0);

	if (!dir || is_home || is_dashdash)
	{
		cd_home(data);
		return (1);
	}
	if (is_dash)
	{
		cd_to_previous(data);
		return (1);
	}

	if (_str_cmp(".", dir) == 0 || _str_cmp("..", dir) == 0)
	{
		cd_parent(data);
		return (1);
	}

	cd_to_other(data);
	return (1);
}
