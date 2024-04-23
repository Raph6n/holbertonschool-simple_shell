#include "shell.h"

/**
 * process - function for tokenise the line.
 * @line: line enter.
 * Return: an array with token.
 */

char **process(char *line)
{
	const char *delim = " \n";
	char *token, **av;
	int num_tk = 0, i;
	char *line_cp = strdup(line);

	if (line_cp == NULL)
		exit(98);

	token = strtok(lineptr_copy, delim);
	while (token != NULL)
	{
		num_tk++;
		token = strtok(NULL, delim);
	}

	av = malloc(sizeof(char *) * (num_tk + 1));
	if (av == NULL)
	{
		perror("memory allocation error");
		free(line_cp);
		exit(98);
	}

	token = strtok(line, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	free(line_cp);

	return (argv);
}
