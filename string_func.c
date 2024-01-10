#include "shell.h"

/**
 * _strncmp - compares n bytes of two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: 0 on success
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}

/**
 * _strcat - concatinate two strings
 * @dst: string to concatinate with
 * @src: string to add
 *
 * Return: pointer to the concatinated string
*/
char *_strcat(char *dst, const char *src)
{
	char *str = dst;

	while (*dst != '\0')
		dst++;

	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';

	return (str);
}

/**
 * _strdup - duplicate a string and allocate memory for duplicate
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *new_str = malloc(sizeof(char) * len);

	if (new_str == NULL)
		return (NULL);
	_strcpy(new_str, str);
	return (new_str);
}

/**
 * _strchr - returns the first occuttance of a character in a string
 * @str: string to check
 * @ch:charcter to compare
 *
 * Return: ointer to the location
 */
char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);

		str++;
	}
	return (NULL);
}
