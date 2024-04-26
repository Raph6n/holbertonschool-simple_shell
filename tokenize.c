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
	char *line_cp = strdup(line);/*Duplicate the line*/

	if (line_cp == NULL)
		exit(98);

	token = strtok(line_cp, delim);/*cut line_cp using delim*/
	while (token != NULL)/*get the number of token*/
	{
		num_tk++;
		token = strtok(NULL, delim);
	}

	av = malloc(sizeof(char *) * (num_tk + 1));/*stock the token*/
	if (av == NULL)
	{
		perror("memory allocation error");
		free(line_cp);
		exit(98);
	}

	token = strtok(line, delim);/*reset the token*/
	for (i = 0; token != NULL; i++)/*copy all the token in av*/
	{
		av[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;/*add a NULL pointer at the end*/
	free(line_cp);

	return (av);
}
