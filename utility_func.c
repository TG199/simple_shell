#include "shell.h"

int empty(const char *str)
{
	while (*str)
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

void remov(char *str)
{
	int i, j;

	char *src, *dst;

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\t' && str[i] != '\n')
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	src = str;
	dst = str;

	while (*src)
	{
		if (*src != '"')
		{
			*dst = *src;
			dst++;
		}
		src++;
	}
	*dst = '\0';
}
void rm_white_space(char *cmd)
{
	char *new;

	if (cmd == NULL || *cmd == '\0')
		return;

	while (*cmd != '\0' && _strchr(" \t\n", *cmd) == NULL)
		cmd++;
	new = cmd;
	while (*cmd != '\0')
	{
		if (*cmd == ' ')
		{
			while (*(cmd + 1) == ' ')
				cmd++;
		}
		*new = *cmd;
		cmd++;
		new++;
	}
	*new = '\0';
}
void handle_comment(const char *dest)
{
	char *str_copy;

	str_copy = _strchr(dest, '#');

	if (str_copy != NULL)
	{
		*str_copy = '\0';
	}
}
