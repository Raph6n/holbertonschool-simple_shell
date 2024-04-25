#define _GNU_SOURCE
#include "shell.h"

/**
 * shell_non_inter - shell non interactif.
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
		exec_non_inter(tokens);
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
		tokens = NULL;
	}
	return (0);
}
