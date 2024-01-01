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


void exe_commands(char **argv);
void err(const char *s);
char *find_executable(char *executable);
char *string(char *str, const char *del);

extern char **environ;

#endif
