#include "shell.h"

/**
 * print_integer - prints integer
 * @num: integer to print
 * @n: stream to print to
 *
 * Return: void
*/
void print_integer(int num, int n)
{
	char buffer[32];
	int i = 0, j;

	if (num == 0)
	{
		write(n, "0", 1);
		return;
	}

	if (num < 0)
	{
		write(n, "-", 1);
		num = -num;
	}

	while (num != 0)
	{
		buffer[i++] = '0' + (num % 10);
		num /= 10;
	}

	for (j = i - 1; j >= 0; j--)
		write(n, &buffer[j], 1);
}

/**
 * write_string - writes a string to the specified stream
 * @n: stream to write to
 * @s: string to write
 *
 * Return: void
*/
void write_string(int n, const char *s)
{
	write(n, s, _strlen(s));
}

/**
 * print_string - print string lateral
 * @s:string to print
 * @n: stream
 *
 * Description: This function prints a string lateral
 * Return: void
 */
void print_string(char *s, int n)
{
	write_string(n, s);
}

/**
 * _isspace - checks if a character is a space
 * @c: character to check
 *
 * Return: 1 if space
*/
int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v' || c == '\r')
		return (1);
	else
		return (0);
}


/**
 * _printf - minature printf function
 * @stream: stream to write to
 * @format: format to write
 *
 * Return: void
*/
void _printf(int stream, const char *format, ...)
{
	va_list args;

	fflush(stdout);
	fflush(stdin);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				{
					int num = va_arg(args, int);

					print_integer(num, stream);
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char*);

					print_string(str, stream);
					break;
				}
				default:
					write(stream, format, 1);
					break;
			}
		}
		else
		{
			write(stream, format, 1);
		}
		format++;
	}
	va_end(args);
}
