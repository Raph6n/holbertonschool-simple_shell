#define _GNU_SOURCE
#include "shell.h"

/**
 * main - prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 *
 * Return: Always 0.
 */

int shell_inter(void)
{
	char *line = NULL;
	char *prt = "$ ";
	size_t len = 0;
	ssize_t read;


	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("%s", prt);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		if (line == NULL)
			continue;

		if (len > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		/*call process command in the file tokenize.c*/
		

	}


	return (0);
}
