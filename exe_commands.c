#include "shell.h"


/**
 * exe_commands - execute programs with the execve system call
 * @argv: argument vector containing program
 *
 * Return: Nothing
 */

void exe_commands(char **argv)
{
	pid_t pid;
	int status, execute;
	char *program;
	char *executable;

	if (argv)
	{
		program = argv[0];

		executable = find_executable(program);

		if (executable != NULL)
		{

			pid = fork();

			if (pid == -1)
			{
				err("Error forking");
			}
			else if (pid == 0)
			{
				execute = execve(executable, argv, environ);

				if (execute == -1)
				{
					err("Error in execve");

				}

			}
			else
			{
				waitpid(pid, &status, WUNTRACED);
			}

		}
	}

}
