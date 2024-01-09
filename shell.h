#ifndef SHELL_H
#define SHELL_H

/*Include Statement*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>

#define BUF_SIZE 1024
#define MAX_PATH 4096


/*Environmental variable*/
extern char **environ;


void _printf(int stream, const char *format, ...);
int empty(const char *str);
void remov(char *str);
void rm_white_space(char *cmd);
void handle_comment(const char *str);

/*Builtin Functions*/
void cd_command(char **agv, char **argv, size_t cmd_count, char *cmd,
		char **colon);
void exit_command(char **agv, char **argv, size_t cmd_count, char *cmd,
		char **colon);
char *get_cwd(void);
int execute_builtin_command(char **agv, char **argv, size_t cmd_count, char *cmd,
		char **colon);
char *find_executable(char **argv);
int execute_command(char **agv, char **argv, int status, size_t cmd_count, char stream);
int execute(char *cmd, char **agv, char **argv, size_t cmd_count, char stream, int status, char **colon);

/*Shell modes Function*/
void non_interactive(char **agv, char *cmd, size_t cmd_count,
		FILE *stream, int status, char **argv, char **colon);
void interactive(int argc, char **agv, char *cmd, size_t cmd_count,
		FILE *stream, int status, char **argv, char **colon);

char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **split_vector(char *cmd, char *dl);
void free_arg(char **agv, char **colon);

/*Environment function*/
char *_getenv(const char *env_name);
int _setenv(const char *name, const char *value, int overwrite);
int _putenv(const char *str);


/* String function*/
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
