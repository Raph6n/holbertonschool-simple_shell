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

int shell_inter(void);
void exec(char **tokens);
char **process(char *line);
void *prt_env(char *env);
char *location(char *command);

#endif
