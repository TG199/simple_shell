#include "shell.h"

/**
 * non_interactive - non interactive mode of shell program
 * @agv: argument variable
 * @cmd: command
 * @cmd_count: command count
 * @stream: input stream
 * @status: status
 * @argv: argument vector
 * @colon: colon seperator
 *
 * Return: Nothing
 */
void non_interactive(char **agv, char *cmd, size_t cmd_count, FILE *stream,
		int status, char **argv, char **colon)
{
	ssize_t bytes_read;
	size_t n;
	char st;

	n = 0;
	st = !isatty(STDIN_FILENO);

	(void)agv;

	do {
		bytes_read = getline(&cmd, &n, stream);
		if (bytes_read != 1)
		{
			remov(cmd);
			rm_white_space(cmd);
			if (empty(cmd))
			{
				cmd_count++;
				continue;
			}
			if (*cmd == '\n')
				continue;
			handle_comment(cmd);
			cmd_count++;
			if (*cmd != '\0')
				execute(cmd, agv, argv, cmd_count, st, status, colon);
			if (st)
				break;
			if (!st)
				continue;
		}
	} while (bytes_read != -1);
	exit(status);
}
/**
 * interactive - interactive mode of shell program
 * @argc: argument count
 * @agv: argument variable
 * @cmd: command
 * @cmd_count: command count
 * @stream: input stream
 * @status: status
 * @argv: argument vector
 * @colon: colon seperator
 *
 * Return: Nothing
 */
void interactive(int argc, char **agv, char *cmd, size_t cmd_count,
		FILE *stream, int status, char **argv, char **colon)
{
	ssize_t bytes_read;
	size_t n;
	char st;

	(void)agv;

	st = !isatty(STDIN_FILENO);

	while (1 && isatty(STDIN_FILENO) && (!st || bytes_read != 0))
	{
		cmd_count++;
		st = !isatty(STDIN_FILENO);

		if (argc == 1 && !st)
			write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&cmd, &n, stream);
		if (bytes_read == -1)
		{
			free(cmd);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		rm_white_space(cmd);
		remov(cmd);
		if (empty(cmd))
			continue;
		if (*cmd == '\n')
			continue;
		handle_comment(cmd);
		if (*cmd != '\0')
			execute(cmd, agv, argv, cmd_count, st, status, colon);
		if (!st)
			continue;
		if (st)
			break;
	}
}
