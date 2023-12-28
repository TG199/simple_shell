#include "shell.h"



void exe_commands(char **agv)
{
	pid_t pid;
	int status;

	pid = fork();


	if (pid == 0)
	{

		if (execve(agv[0], agv, NULL) == -1)
		{
			err("Error in execve");
		}

	}
	else if (pid < 0)
	{
		err("Error Forking");
	}
	else
	{
		do 
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
		

