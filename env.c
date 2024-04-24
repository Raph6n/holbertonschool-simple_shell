#include "shell.h"

void print_env(void)
{
int count = 0;
 extern char **environ;
while (environ[count] != NULL)
{
printf("%s\n", environ[count]);
count++;
}
}
  
