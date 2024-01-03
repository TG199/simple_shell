#include "shell.h"
/**
  * hsh_env - Prints all the environment variables
  * @args: array of words split
  * Return: 0 on success
  */
int hsh_env(char **args)
{
	int i = 0;
	char *new_line = "\n";
	(void)args;

	while (*(environ + i) != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, new_line, 1);
		i++;
	}
	return (1);
}

/**
  * hsh_exit - Exits from the shell
  * @args: array of words split
  * Return: 0 on success
  */

int hsh_exit(char **args)
{
	(void)args;
	return (0);
}

/**
  * _cd - Changes directory
  * @args: array of words split
  * Return: 0 on success
  */

int _cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("error: expected arguments");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("error");
	}
	return (1);

}
