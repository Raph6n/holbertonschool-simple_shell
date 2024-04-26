#include "shell.h"

/**
 * print_env - built-in for env.
 */

void print_env(void)
{
	int count = 0;

	while (environ[count] != NULL)//display the environnement
	{
		printf("%s\n", environ[count]);
		count++;
	}
}
  
