#define _GNU_SOURCE
#include "shell.h"
#define MAX_COMMAND_LENGTH 1024

/**
 * shell_inter - prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 *
 * Return: Always 0.
 */

int shell_inter(void)
{
	char *prt = "$ ", *lineptr = NULL;
	char **tokens;
	ssize_t read;
	size_t len = 0;
	int status, i = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			printf("%s", prt);
			fflush(stdout);
		}

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}

		if (strcmp(line, "\n") == 0)
			continue;
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		tokens = process(line);
		/**status = exit_shell(tokens[0]);
		if (status > 0)
		{
			free(line);
			for (i = 0; tokens[i]; i++)
				free(tokens[i]);
			free(tokens);
			tokens = NULL;
			exit(EXIT_SUCCESS);
		}*/

		exec(tokens);
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
		tokens = NULL;
	}
	return (0);
}
