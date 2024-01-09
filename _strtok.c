#include "shell.h"

/**
 * _strtok - Breaks a string into a sequence of zero or more nonempty tokens
 * @str: The string to be parsed
 * @del: Set of bytes that delimit the tokens in the parsed string
 *
 * Return: Pointer to the next token,
 *		or NULL if there are no more tokens.
*/
char *_strtok(char *str, const char *delim)
{
	char *tok_st = NULL, *tok_ed = NULL;
	static char *saved_str;

	if (str != NULL)
		saved_str = str;

	if (saved_str == NULL || *saved_str == '\0')
		return (NULL);

	tok_st = saved_str;

	while (*tok_st != '\0' && _strchr(delim, *tok_st) != NULL)
		tok_st++;

	tok_ed = tok_st;

	while (*tok_ed != '\0' && _strchr(delim, *tok_ed) == NULL)
		tok_ed++;

	if (*tok_ed != '\0')
	{
		*tok_ed = '\0';
		saved_str = tok_ed + 1;
	}
	else
	{
		saved_str = NULL;
	}

	return (tok_st);
}

/**
 * split_vector - parses input command to tokens
 * @cmd: string to tokenize
 * @dl: specify the delimiter to use
 *
 * Return: an array pointers to chracters
*/
char **split_vector(char *cmd, char *dl)
{
	char *com_cpy = NULL, *tok, **command;
	size_t count = 0, cnt = 0;

	if (cmd)
	{
		com_cpy = _strdup(cmd);
		tok = _strtok(cmd, dl);
		while (tok)
		{
			cnt++;
			tok = _strtok(NULL, dl);
		}
		cnt++;
		command = malloc(sizeof(char *) * (cnt + 1));
		tok = _strtok(com_cpy, dl);
		while (tok)
		{
			command[count] = malloc(sizeof(char) * (_strlen(tok) + 1));
			_strcpy(command[count], tok);
			tok = _strtok(NULL, dl);
			count++;
		}
		free(tok);
		command[count] = NULL;
		free(com_cpy);
		com_cpy = NULL;
		count = 0, cnt = 0;
		return (command);
	}
	else
		return (NULL);

}

/**
 * free_arg- free's char **
 * @av: char **
 * @colon: char **
 *
 * Return: void
*/
void free_arg(char **agv, char **colon)
{
	int i, j;

	for (i = 0; agv[i] != NULL; i++)
	{
		free(agv[i]);
	}
	free(agv);

	for (j = 0; colon[j] != NULL; j++)
	{
		free(colon[j]);
	}
	free(colon);
}

/**
 * _isdigit - Checks if variable is a digit.
 * @c: The parameter to be checked.
 *
 * Return: 1 c is a number, 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to integer
 * @nptr: string to be converted
 *
 * Return: void
*/
int _atoi(const char *nptr)
{
	int result, sign, i, digit;

	if (nptr == NULL)
		return (0);

	result = 0;
	sign = 1;
	i = 0;

	while (_isspace(nptr[i]))
		i++;

	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = (nptr[i] == '-') ? -1 : 1;
		i++;
	}
	while (_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (result > (INT_MAX - digit) / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);
		result = result * 10 + digit;
		i++;
	}
	return (sign * result);
}
