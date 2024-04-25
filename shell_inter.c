#define _GNU_SOURCE
#include "shell.h"

/**
 * shell_inter - prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 *
 * Return: Always 0.
 */

int shell_inter(void)
{
	char *line = NULL;
	char **tokens;
	ssize_t read;
	size_t len = 0;
	int i = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDIN_FILENO, "$ ", 2);
			fflush(stdout);
		}

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		if (strcmp(line, "\n") == 0)
			continue;
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		tokens = process(line);
		exec(tokens);

		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
		tokens = NULL;
	}
	return (0);
}
