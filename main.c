#include "shell.h"


#define bufsize 1024

void err(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

int main()
{
	int a = 20;
	char *commands = malloc(bufsize);
	char *token;
	char *delim = " ";
	size_t n;
	ssize_t line;
	int i;
	char **agv = malloc(a * sizeof(char *));

	if (commands == NULL)
		err("Error Allocating commands");

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = getline(&commands, &n, stdin);

		if (line == - 1 || line == EOF)
		{
			free(commands);
			err("Error reading line");

		}
		i = 0;
		token = strtok(commands, delim);
		
		while (token != NULL)
		{
			agv[i] = token;
			i++;

			if (i >= a)
			{
				a = (int) (a * 1.5);
				agv = realloc(agv, a * sizeof(char *));
			}
			token = strtok(NULL, delim);
		}
		agv[i] = NULL;

		if (commands!= NULL)
		{
			if (strcmp(commands, "exit") == 0)
			{
				free(commands);
				exit(EXIT_SUCCESS);
			}
			exe_commands(agv);
		}
	}

	free(commands);
	return (0);
}

