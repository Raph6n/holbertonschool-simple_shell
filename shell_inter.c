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
	char *prt = "$ ";
	size_t len = 0;
	ssize_t read;
	char **token;
	pid_t pid;
	int status;

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
			free(line);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		if (strlen(line) == 0)
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		else if (pid == 0)
		{
			if (execlp(line, line, (char *)NULL) == -1)
			{
				fprintf(stderr, "commande introuvable : %s\n", line);
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(pid, &status, 0);

		free(line);
		line = NULL;
		len = 0;
	}

	return (0);
}
