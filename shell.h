#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

int shell_noninter(void);
int shell_inter(void);
void exec(char **tokens);
void exec_non_inter(char **tokens);
char **process(char *line);
void *prt_env(char *env);
char *location(char *command);
void exit_shell(void);

#endif
