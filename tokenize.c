#include "shell.h"

/**
 * process - process the command.
 * @line: line enter.
 * Return: the line.
 */

char **process(char *line)
{
	size_t len, i;
	char *cp_line = line;
	char **argv = malloc(sizeof(char *));

	if (*argv == NULL)
	{
		free(cp_line);
		return;
	}

	return (line);
}
