#include "shell.h"

void command (char *line)
{
char *token[64];
int count = 0;
const char *specials = " \t\n";
pid_t pid;
int status;

 
if (line == NULL)
return;

char *token = strtok(line, specials);

while (token != NULL && count < 64)
{
token[count++] = token;
token = strtok(NULL, specials);
}
token[count] = NULL;

if (token[0] = NULL)
return;

pid = fork ();

if (pid == -1)
{
perror ("fork");
return;
}
else if (pid == 0)
{
execvp(token[0], token);
fprintf(stderr, "erreur %s\n", token[0]);
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}
