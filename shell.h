#ifndef SHELL_H
#define SHELL_H


#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

void exe_commands(char **agv);
void err(const char *s);
/*ar *find_executable(char *av);*/
char *string(char *str, const char *del);


#endif
