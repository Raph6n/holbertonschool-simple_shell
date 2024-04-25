#include "shell.h"

/**
 * process - function for tokenise the line.
 * @line: line enter.
 * Return: an array with token.
 */

char **process(char *line)
{
	char *token, **av;
	int num_tk = 64, i = 0;

	if (line == NULL)
		exit(98);

	av = malloc(sizeof(char *) * (num_tk + 2));
	if (av == NULL)
	{
		perror("memory allocation error");
		free(line);
		exit(98);
	}

	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		av[i] = malloc(sizeof(char *) * (strlen(token) + 1));
		av[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	av[i] = NULL;
	free(line);

	return (av);
}
