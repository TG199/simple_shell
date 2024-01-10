#include "shell.h"

/**
 * execute_builtin_command - execute builtin command
 * @agv: argument variable
 * @argv: argument variable
 * @cmd_count: command count
 * @cmd: command passed
 * @colon: colon separator
 *
 * Return: 1
 */
int execute_builtin_command(char **agv, char **argv, size_t cmd_count,
		char *cmd, char **colon)
{
	char *built_in_cmds[] = {
		"cd",
		"exit",
	};

	void (*built_in_func[])(char **, char **, size_t,
			char *, char **) = {
		&cd_command,
		&exit_command,
	};
	int num_built_in_com = sizeof(built_in_cmds) / sizeof(char *), i;

	for (i = 0; i < num_built_in_com; i++)
	{
		if (strcmp(agv[0], built_in_cmds[i]) == 0)
		{
			(*built_in_func[i])(agv, argv, cmd_count, cmd, colon);
			return (0);
		}
	}
	return (1);
}
/**
 * find_executable - find the executable file in PATH
 * @agv: executable program to find
 *
 * Return: Executable
 */
char *find_executable(char **agv)
{
	char *path_env, *path_cpy, *token, *exe_path;
	size_t token_len, exec_name_len;

	if (access(agv[0], X_OK) == 0)
	{
		exe_path = agv[0];
		return (exe_path);
	}
	path_env = getenv("PATH");
	path_cpy = strdup(path_env);
	token = _strtok(path_cpy, ":");

	while (token)
	{
		token_len = strlen(token);
		exec_name_len = strlen(agv[0]);
		exe_path = (char *)malloc((token_len + exec_name_len + 2) * sizeof(char));
		if (exe_path == NULL)
		{
			free(path_cpy);
			return (NULL);
		}

		strcpy(exe_path, token);
		strcat(exe_path, "/");
		strcat(exe_path, agv[0]);
		if (access(exe_path, X_OK) == 0)
		{
			free(path_cpy);
			return (exe_path);
		}
		free(exe_path);
		token = _strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}
/**
 * execute_command -  execute a command
 * @agv: argument variable
 * @argv: argument variable
 * @status: status
 * @cmd_count: command count
 * @stream: file stream
 *
 * Return: 1
 */
int execute_command(char **agv, char **argv, int status,
		size_t cmd_count, char stream)
{
	char *executable;
	pid_t pid;

	executable = find_executable(agv);
	if (executable == NULL)
	{
		_printf(STDOUT_FILENO, "%s: %d: %s: not found\n", argv[0],
				cmd_count, agv[0]);
		if (stream)
			exit(127);
	}
	if (executable != NULL)
	{
		pid = fork();

		if (pid == -1)
			perror("Error forking");
		else if (pid == 0)
		{
			execve(executable, agv, environ);
			_printf(STDERR_FILENO, "%s %d %s: Permission denied\n",
			argv[0], cmd_count, agv[0]);
			return (EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
			free(executable);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
		}
	}
	return (-1);
}
/**
 * execute - execute function
 * @cmd:command
 * @agv: argument count
 * @argv: command count
 * @cmd_count: command count
 * @stream: file stream
 * @status: status
 * @colon: colon separator
 *
 * Return: execute function
 */
int execute(char *cmd, char **agv, char **argv,
		size_t cmd_count, char stream, int status, char **colon)
{
	int i = 0;

	colon = split_vector(cmd, ";\n\t");
	for (i = 0; colon[i] != NULL; i++)
	{
		agv = split_vector(colon[i], " \t\n\r");
		status = execute_builtin_command(agv, argv, cmd_count, cmd, colon);
		if (status != 0)
			status = execute_command(agv, argv, status, cmd_count, stream);
	}
	
	if (!isatty(STDIN_FILENO))
		free_arg(agv, colon);
	return (status);
}
