#include "shell.h"

/**
 * find_executable - Finds the full path of an executable
 * @executable: executable paths to find
 *
 * Return: The full path of the executable program
 */

char *find_executable(char *executable)
{
	char *env_path, *env_path_cpy, *env_token, *file_path;
	int exec_len, dir_len;
	struct stat buffer;

	env_path = getenv("PATH");
	if (env_path)
	{
		env_path_cpy = strdup(env_path);
		exec_len = _strlen(executable);
		env_token = strtok(env_path_cpy, ":");
		while (env_token != NULL)
		{
			dir_len = _strlen(env_token);
			file_path = malloc(exec_len + dir_len + 2);
			_strcpy(file_path, env_token);
			_strcat(file_path, "/");
			_strcat(file_path, executable);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(env_path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				env_token = strtok(NULL, ":");
			}
		}
		if (stat(executable, &buffer) == 0)
		{
			return (executable);
		}
		return (NULL);
	}
	return (NULL);
}
