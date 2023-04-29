#include "shell.h"

/**
 * cd_parent - change the working directory to the parent directory
 *
 * @data: pointer
 *
 * Returns: void
 */
void cd_parent(data_sh *data)
{
	char cwd[PATH_MAX], *old_pwd, *dir, *parent_dir;

	getcwd(cwd, sizeof(cwd));
	old_pwd = _str_dup(cwd);
	setenv("OLDPWD", old_pwd, data_sh);
	free(old_pwd);
	dir = data->args[1];

	if (_str_cmp(".", dir) == 0 || _str_cmp("/", cwd) == 0)
	{
		setenv("PWD", cwd, data_sh);
		return;
	}
	parent_dir = _str_dup(cwd);
	rev_string(parent_dir);
	parent_dir = _str_tok(parent_dir, "/");
	if (parent_dir != NULL)
	{
		parent_dir = _str_tok(NULL, "\0");
		if (parent_dir != NULL)
			rev_string(parent_dir);
	}
	if (parent_dir != NULL)
	{
		chdir(parent_dir);
		setenv("PWD", parent_dir, data_sh);
	}
	else
	{
		chdir("/");
		setenv("PWD", "/", data_sh);
	}
	data->status = 0;
	free(parent_dir);
}

/**
 * cd_to_other - change the working directory to a specified directory
 *
 * @data: pointer
 *
 * Returns: void
 */
void cd_to_other(data_sh *data)
{
	char cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));

	char *dir = data->args[1];

	if (chdir(dir) == -1)
	{
		path_error(data, 2);
		return;
	}

	char *old_pwd = _str_dup(cwd);

	setenv("OLDPWD", old_pwd, data_sh);
	free(old_pwd);

	char *new_pwd = _str_dup(dir);

	setenv("PWD", new_pwd, data_sh);
	free(new_pwd);

	data->status = 0;
}


#include "shell.h"

/**
 * cd_to_previous - changes to the previous directory
 *
 * @data: data or pointer
 * Return: void
 */
void cd_to_previous(data_sh *data)
{
	char current_dir[PATH_MAX], *prev_dir, *oldpwd_copy, *pwd_copy;

	if (!getcwd(current_dir, sizeof(current_dir)))
	{
	perror("getcwd");
	data->status = 1;
	return;
	}

	pwd_copy = _str_dup(current_dir);
	setenv("OLDPWD", pwd_copy, data);

	prev_dir = getenv("OLDPWD", data->_environ);
	oldpwd_copy = prev_dir ? _str_dup(prev_dir) : _str_dup(current_dir);

	if (chdir(oldpwd_copy) == -1)
	{
		setenv("PWD", pwd_copy, data_sh);
	}
	else
	{
		setenv("PWD", oldpwd_copy, data);
	}

	char *cwd = getenv("PWD", data->_environ);

	write(STDOUT_FILENO, cwd, _str_len(cwd));
	write(STDOUT_FILENO, "\n", 1);

	free(pwd_copy);
	if (prev_dir)
	free(oldpwd_copy);

	data->status = 0;

	chdir(cwd);
}

/**
 * cd_home - changes to home directory
 *
 * @data: data
 * Return: void
 */
void cd_home(data_sh *data)
{
	char current_dir[PATH_MAX], *pwd_copy, *home_dir;

	if (!getcwd(current_dir, sizeof(current_dir)))
	{
	perror("getcwd");
	data->status = 1;
	return;
	}

	pwd_copy = _str_dup(current_dir);

	home_dir = _getenv("HOME", data->_environ);
	if (home_dir == NULL)
	{
		setenv("OLDPWD", pwd_copy, data_sh);
		free(pwd_copy);
		return;
	}

	if (chdir(home_dir) == -1)
	{
	path_error(data, 2);
	free(pwd_copy);
	return;
	}

	setenv("OLDPWD", pwd_copy, data_sh);
	setenv("PWD", home_dir, data_sh);
	free(pwd_copy);
	data->status = 0;
}
