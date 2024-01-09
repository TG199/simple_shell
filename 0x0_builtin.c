#include "shell.h"

/**
 * cd_command - change directory
 * @agv: argument variable
 * @argv: argument variable
 * @cmd_count: Number of commands passed
 * @cmd: command argument
 * @colon: Command seperator
 *
 * Return:  Nothing
 */
void cd_command(char **agv, char **argv, size_t cmd_count,
		char *cmd, char **colon)
{
	char *env;
	int i;
	(void) cmd, (void) colon;

	if (agv[1] == NULL)
	{
		i = chdir(_getenv("HOME"));
		if (i == 0)
		{
			_setenv("OLDPWD", _getenv("PWD"), 1);
			_setenv("PWDP", get_cwd(), 1);
		}
		return;
	}
	else if (_strcmp(agv[1], "-") == 0)
	{
		env = _getenv("OLDPWD");
		i = chdir(env);
		if (i == 0)
		{
			_setenv("OLDLPWD", _getenv("PWD"), 1);
			_setenv("PWD", get_cwd(), 1);
			_printf(STDOUT_FILENO, "%s\n", getenv("PWD"));
		}
		return;
	}
	else
	{
		i = chdir(agv[1]);
		if (i == 0)
		{
			_setenv("OLDPWD", _getenv("PWD"), 1);
			_setenv("PWD", get_cwd(), 1);
		}
		else
		{
			_printf(STDOUT_FILENO, "%s: %d: %s: can't cd to %s\n",
					argv[0], cmd_count, agv[0], agv[1]);
		}
	}
}
/**
 */
void exit_command(char **agv, char **argv, size_t cmd_count,
		char *cmd, char **colon)
{
	int i, status, is_number;

	is_number = 1;
	if (agv[1] == NULL)
	{
		free_arg(agv, colon);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (agv[1] != NULL)
	{
		i = 0;
		while (agv[1][i] != '\0')
		{
			if (!_isdigit(agv[1][i]))
			{
				is_number = 0;
				break;
			}
			i++;
		}
		if (!is_number)
		{
			_printf(STDOUT_FILENO, "%s: %d: %s: Illegal number: %s\n",
					argv[0], cmd_count, agv[0], agv[1]);
			free_arg(agv, colon);
			free(cmd);
			if (!isatty(STDIN_FILENO))
			{
				exit(2);
			}
		}
		else
		{
			status = _atoi(agv[1]);
			free_arg(agv, colon);
			exit(status);
		}
	}
}
