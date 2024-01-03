#include "shell.h"

/**
  * _strlen - Checks the length of a string
  * @s: string parameter
  * Return: it returns the length of the string
  */
int _strlen(const char *s)
{
	int i;

	i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
/**
  * _strcpy - Copies content of length of src to dest
  * @src: source string to be copied
  * @dest: destination string
  * the content of src will be copied into
  * Return: it returns a pointer to the destination string
  */
char *_strcpy(char *dest, char *src)
{
	int i, length = 0;

	while (*(src + length) != '\0')
	{
		length++;
	}
	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
  * _strcat - Appends content of src to dest
  * @src: string to be copied from
  * @dest: String to be appended
  * Return: this returns a pointer to the concatenated string
  */
char *_strcat(char *dest, char *src)
{
	int i, src_length = 0, dest_length = 0;

	while (src[src_length] != '\0')
	{
		src_length++;
	}
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}
	for (i = 0; i < src_length; i++)
	{
		dest[dest_length + i] = src[i];
	}
	dest[dest_length + i] = '\0';
	return (dest);
}

/**
  * _strcmp - This compares two strings
  * @s1: this is one of the string to be compared
  * @s2: thus is another one of the string to be compared
  * Return: returns 0 if both strings are the same
  * returns a positive value if s1 is greater than s2
  * returns a negative value if s1 is less than s2
  */

int _strcmp(char *s1, char *s2)
{
	int i, cmp, s1_len = 0;

	s1_len = _strlen(s1);

	for (i = 0; i < s1_len; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			return (cmp);
		}
	}
	return (0);
}
/**
 * _strdup - Duplicates a string
 * @s: this is the string that will be copied
 * Return: this returns a pointer to the newly allocated string
 * OR NULL if there's insufficient space
 */
char *_strdup(char *s)
{
	char *copy;
	int len = _strlen(s), i;

	if (s == NULL)
	{
		return (NULL);
	}

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		copy[i] = s[i];
	}
	copy[len] = '\0';

	return (copy);
}
