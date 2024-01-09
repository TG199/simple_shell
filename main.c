#include "shell.h"


void sig(int num)
{
	(void)num;

	_printf(STDOUT_FILENO, "\n$ ");
	fflush(stdout);
}

int main(int argc, char **argv)
{
	char **agv = NULL, *cmd = NULL, **colon = NULL;
	size_t n = 0, cmd_count = 0;
	ssize_t bytes_read = 1;
	char st;
	int status = 0;

	(void)status, (void)st, (void)bytes_read, (void)n;

	signal(SIGINT, sig);
	if (!isatty(STDIN_FILENO))
		non_interactive(agv, cmd, cmd_count, stdin, status, argv, colon);
	if (isatty(STDIN_FILENO) && argc == 1)
		interactive(argc, agv, cmd, cmd_count, stdin, status, argv, colon);
	return (0);
}

