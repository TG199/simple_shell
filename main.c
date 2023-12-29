#include "shell.h"


#define bufsize 1024

void err(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

int main()
{
	char *commands = NULL;
	char *token;
	char *delim = " ";
	size_t n;
	ssize_t line;
	int i;
	char **agv = malloc(sizeof(bufsize));


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
