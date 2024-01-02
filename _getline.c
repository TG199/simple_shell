#include "shell.h"

/**
 * _getline - get line of text from file stream
 * @lineptr: pointer to a pointer to a buffer
 * @n: pointer to a size_t variable (bufsize)
 * @stream: File stream to read text.
 *
 * Return: The number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer;
	size_t bufsize = 20;
	ssize_t bytes_read;
	int fd;
	char c;

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Memory Allocation");
		return (-1);
	}
	fd = fileno(stream);
	if (fd == -1)
	{
		perror("Error getting file descriptor");
		free(buffer);
		return (-1);
	}
	bytes_read = 0;
	while (read(fd, &c, 1) == 1 && c != '\n')
	{
		buffer[bytes_read] = c;
		bytes_read++;
		if (bytes_read >= bufsize)
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize);
			if (buffer == NULL)
			{
				perror("Memory Management error");
				return (-1);
			}
		}
	}
	*n = bufsize;
	*lineptr = buffer;
	return (bytes_read);
}


