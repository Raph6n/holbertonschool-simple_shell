#include "shell.h"
#include "prompt.c"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main(void)
{
	char *argv[] = {"/bin/sh", "-u", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	prompt();
	return (0);
}
