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
	char *prt = "$ ", *line = NULL, **tokens;
	ssize_t read;
	size_t len = 0;
	int i = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))/*Display the prompt*/
		{
			printf("%s", prt);
			fflush(stdout);
		}
		read = getline(&line, &len, stdin);/*get the line enter by the user*/
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		if (strcmp(line, "\n") == 0)/*continue when the user use only enter*/
			continue;
		if (line[0] == ' ')/*continue when the user enter space first*/
			continue;
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		tokens = process(line);/*call the function process*/
		if (strcmp(tokens[0], "exit") == 0)/*the user enter exit*/
			exit_shell();
		else if (strcmp(tokens[0], "env") == 0)/*the user enter env*/
			print_env();
		else
			exec(tokens);/*call the function exec*/
		for (i = 0; tokens[i]; i++)/*free the token*/
			free(tokens[i]);
		free(tokens);
		tokens = NULL;
	}
	return (0);
}
