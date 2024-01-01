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
 * main - Entry point of program
 * @argc: argument count
 * @argv: argument vector
 * 
 * Return: Always(0)
 */

int main(int argc, char **argv)
{
	char *commands = NULL;
	char *command_cpy = NULL;
	char *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t line;
	int i, j;
	int num_of_tokens;

	(void)argc;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = getline(&commands, &n, stdin);

		if (line == - 1 || line == EOF)
		{
			err("Error reading line");

		}

		if (strcmp(commands, "exit\n") == 0)
		{
			exit(EXIT_SUCCESS);
			break;
		}

		command_cpy = malloc(sizeof(char) * line);
		if (command_cpy == NULL)
		{
			perror("Mem allocation err");
			break;
		}

		command_cpy = strdup(commands);
		token = strtok(commands, delim);

		while (token != NULL)
		{
			num_of_tokens++;
			token = strtok(NULL, delim);
		}
		num_of_tokens++;

		argv = malloc(sizeof(char *) * num_of_tokens);

		token = strtok(command_cpy, delim);
		i = 0;

		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			argv[i] = strdup(token);
			i++;

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		exe_commands(argv);


	}
	for (j = 0; j < i-1; j++)
		free(argv[j]);
	free(commands);
	free(command_cpy);
	free(argv);
	return (0);
}
