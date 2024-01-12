#include "shell.h"

/**
 * Prints the current environment.
 * @info: Pointer to the info_t struct. Used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * Gets the value of an environment variable.
 * @info: Pointer to the info_t struct. Used to maintain constant function prototype.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * Initializes a new environment variable or modifies an existing one.
 * @info: Pointer to the info_t struct. Used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * Removes an environment variable.
 * @info: Pointer to the info_t struct. Used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * Populates the environment linked list.
 * @info: Pointer to the info_t struct. Used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
