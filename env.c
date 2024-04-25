#include "shell.h"

void print_env(void)
{
	int count = 0;

	while (environ[count] != NULL)
	{
		printf("%s\n", environ[count]);
		count++;
	}
}
  
