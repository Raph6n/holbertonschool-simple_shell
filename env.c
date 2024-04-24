#include "shell.h"

void print_env(void)
{
int count = 0;
extern char **env;

while (env[count] != NULL)
{
printf("%s\n", env[count]);
count++;
}
}
  
