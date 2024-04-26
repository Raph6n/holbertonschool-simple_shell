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

<<<<<<< HEAD
int shell_non_inter(void);
int shell_inter(void);
void exec(char **tokens);
void exec_non_inter(char **tokens);
=======
int shell_inter(void);
void exec(char **tokens);
char *location(void);
>>>>>>> main
char **process(char *line);
void print_env(void);
void exit_shell(void);

#endif
