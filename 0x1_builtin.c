#include "shell.h"

/**
 * get_cwd - get current working directory
 *
 * Return: current working directory
 */
char *get_cwd(void)
{
	char path_size[MAX_PATH];
	char *path;

	path = getcwd(path_size, sizeof(path_size));

	if (path == NULL)
	{
		free(path);
		return (NULL);
	}
	else
	{
		return (path);
	}
}
/**
 * _getenv - get environment variable
 * @env_name: environment variable name
 *
 * Return: environment variable
 */
char *_getenv(const char *env_name)
{
	char **env;

	if (env_name == NULL || env_name[0] == '\0' || _strchr(env_name, '=') != NULL)
		return (NULL);
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, env_name, _strlen(env_name)) == 0
				&& (*env)[_strlen(env_name)] == '=')
			return ((*env) + _strlen(env_name) + 1);
	}

	return (NULL);
}
/**
 * _setenv - set environment variable
 * @name: environment variable name
 * @value: environment variable value
 * @overwrite: overwrite environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_str, *new_env_var;
	size_t len_name;
	size_t len_value;
	size_t len_total;

	if (name == NULL ||  name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);

	env_str = _getenv(name);

	if (env_str != NULL && !overwrite)
		return (0);
	len_name = strlen(name);
	len_value = (value != NULL) ? strlen(value) : 0;
	len_total = len_name + len_value + 2;

	new_env_var = (char *)malloc(len_total);

	if (new_env_var == NULL)
	{
		return (-1);
	}
	strcpy(new_env_var, name);
	new_env_var[len_name] = '=';

	if (value != NULL)
	{
		strcpy(new_env_var + len_name + 1, value);
	}
	else
		new_env_var[len_name + 1] = '\0';

	if (_putenv(new_env_var) != 0)
	{
		free(new_env_var);
		return (-1);
	}
	return (0);
}
/**
 * _putenv - put environment variable
 * @str: environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int _putenv(const char *str)
{
	char *existing_env = _getenv(str);
	int result;

	if (str == NULL	|| str[0] == '\0' || _strchr(str, '=') == NULL)
		return (-1);

	if (existing_env != NULL)
		_unsetenv(str);
	result = _setenv(str, "", 1);

	if (result != 0)
		return (-1);

	return (0);
}
/**
 * _unsetenv - unset environment variable
 * @name: variable to unset
 *
 * Return: 0
 */
int _unsetenv(const char *name)
{
	char **env;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	env = environ;
	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
		{
			while (env[1] != NULL)
			{
				*env = env[1];
				++env;
			}
			*env = NULL;
			return (0);
		}
	}
	return (0);
}
