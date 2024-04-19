#define _GNU_SOURCE
#include "shell.h"

/**
 * main - prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		printf("%s", line);
	}
	free(line);

	return (0);
}
