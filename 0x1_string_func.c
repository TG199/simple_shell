#include "shell.h"

/**
 * _strlen - returns the lenght of a string
 * @str: string to perform operation on
 *
 * Return: lenght of the string
*/
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * _strstr - finds the first occurrance of a substring in a string
 * @str: hystark
 * @find: needle
 *
 * Return: pointer to the first occurance if found
*/
char *_strstr(const char *str, const char *find)
{
	size_t len = _strlen(find);

	while (*str != '\0')
	{
		if (_strncmp(str, find, len) == 0)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

/**
 * _strcpy - copies a string to another memory location
 * @dest: destionation
 * @src: source
 *
 * Return: pointer to the copied memory
*/
char *_strcpy(char *dest, const char *src)
{
	char *str = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (str);
}

/**
 * _strncpy - copies n byte of a string to another memory location
 * @s1: destionation
 * @sc: source
 * @n: number to copy
 *
 * Return: pointer to the copied memory
*/
char *_strncpy(char *s1, const char *sc, size_t n)
{
	char *str = s1;

	while (n > 0 && *sc != '\0')
	{
		*s1 = *sc;
		s1++;
		sc++;
		n--;
	}
	if (n > 0)
		*s1 = '\0';

	return (str);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 on success
*/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}

