#include "shell.h"

/**
<<<<<<< HEAD
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

	while (line)
		len++;

	for (i = 0; i < len - 1; i++)
	{
		argv[i] = malloc(sizeof(char));
		if (argv[i])
		{
			free(cp_line);
			return;
		}
	}

	return (line);
=======
 * command - function for tokenise the line
 * @line: line enter.
 */

void command(char *line)
{
	char *tokens[64];
	int count = 0;
	const char *specials = " \t\n";
	pid_t pid;
	int status;
	char *token_2;

	if (line == NULL)
		return;

	token_2 = strtok(line, specials);

	while (token_2 != NULL && count < 64)
	{
		tokens[count++] = token_2;
		token_2 = strtok(NULL, specials);
	}
	tokens[count] = NULL;

	if (tokens[0] == NULL)
		return;

	pid = fork();

	if (pid == -1)
	{
		perror ("fork");
		return;
	}
	else if (pid == 0)
	{
		if (execvp(tokens[0], tokens) == -1)
		{
			fprintf(stderr, "erreur %s\n", tokens[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
>>>>>>> main
}
