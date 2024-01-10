#include "shell.h"


/**
 * err - Error handling function
 * @s: string text of error
 *
 * Return: Nothing
 */

void err(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

/**
 * process_input - process input
 * @commands: command input to process
 * @command_cpy: command copy
 * @n: size of input to process
 *
 * Return: Nothing
 */
void process_input(char **commands, char **command_cpy, size_t *n)
{
	ssize_t line;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = getline(commands, n, stdin);
		if (line == -1 || line == EOF)
		{
			perror("Error reading line");
			exit(EXIT_FAILURE);
		}
		if (_strcmp(*commands, "exit\n") == 0)
		{
			exit(EXIT_SUCCESS);
			break;
		}
		*command_cpy = malloc(sizeof(char) * line);
		if (*command_cpy == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		*command_cpy = strdup(*commands);
		exec(*commands, *command_cpy);
	}
}

/**
 * exec - execute command
 * @commands: command to execue
 * @command_cpy: command copy
 *
 * Return: Nothing
 */
void exec(char *commands, char *command_cpy)
{
	char **argv;
	char *token;
	const char *delim = " \n";
	int argc = 0, i, j;

	token = strtok(commands, delim);
	while (token != NULL)
	{
		argc++;
		token = strtok(NULL, delim);
	}
	argc++;
	argv = malloc(sizeof(char *) * argc);
	if (argv == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(command_cpy, delim);
	i = 0;
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (argv[i] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	exe_commands(argv);

	for (j = 0; j < i; j++)
		free(argv[j]);
	free(argv);
}
/**
 * main - Entry point of program
 *
 * Return: 0
 */
int main(void)
{
	char *commands = NULL, *command_cpy = NULL;
	size_t n = 0;

	process_input(&commands, &command_cpy, &n);
	/*exec(commands, command_cpy);*/

	free(commands);
	free(command_cpy);

	return (0);
}
