#ifndef SHELL_H
#define SHELL_H


#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>

#define MAX_ARGS 100

void exe_commands(char **argv);
void err(const char *s);
char *find_executable(char *executable);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void exec(char *commands, char *command_cpy);
void process_input(char **commands, char **command_cpy, size_t *n);
extern char **environ;

int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dst, const char *src);
char *_strdup(const char *str);
size_t _strlen(const char *str);
char *_strstr(const char *str, const char *find);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *s1, const char *sc, size_t n);
int _strcmp(const char *s1, const char *s2);
char *_strchr(const char *str, int ch);
int _isdigit(int c);
int _atoi(const char *nptr);
int _isspace(int c);

#endif /*SHELL_H*/
