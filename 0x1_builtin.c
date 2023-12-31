#include "shell.h"

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

char *_getenv(const char *env_name)
{
	char **env;

	if (env_name == NULL || env_name[0] == '\0' || _strchr(env_name, '=') != NULL)
		return (NULL);
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, env_name, _strlen(env_name)) == 0 && (*env)[_strlen(env_name)] == '=')
			return ((*env) + _strlen(env_name) + 1);
	}
	return (NULL);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_var, *new_env_var;
	size_t len_name, len_value, len_total;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	env_var = _getenv(name);

	if (env_var != NULL && !overwrite)
		return (0);
	len_name = _strlen(name);
	len_value = (value != NULL) ? _strlen(value) : 0;
	len_total = len_name + len_value + 2;

	new_env_var = (char *)malloc(len_total);
	if (new_env_var == NULL)
		return (-1);

	_strcpy(new_env_var, name);
	new_env_var[len_name] = '=';

	if (value != NULL)
		_strcpy(new_env_var + len_name + 1, value);
	else
		new_env_var[len_name + 1] = '\0';

	if (_putenv(new_env_var) != 0)
	{
		free(new_env_var);
		return (-1);
	}
	return (0);
}
int _putenv(const char *str)
{
	char *existing_env_var;
	int result;

	if (str == NULL || str[0] == '\0' || _strchr(str, '=') == NULL)
		return (-1);

	existing_env_var = _getenv(str);
	if (existing_env_var != NULL)
		_unsetenv(str);
	result = _setenv(str, "", 1);

	if (result != 0)
		return (-1);

	return (0);
}

int _unsetenv(const char *name)
{
	char **env;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);

	env = environ;

	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, _strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
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
