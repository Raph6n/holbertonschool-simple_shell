#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int shell_inter(void);
char **process(char *line);
void *prt_env(char *env);
char *location(char *command);


#endif
