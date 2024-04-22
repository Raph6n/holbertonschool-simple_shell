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
	char *line = NULL, **av;
	char *prt = "$ ";
	size_t len = 0;
	ssize_t read;
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

		line[read - 1] = '\0';
		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			**av = {line, NULL};
			execve(line, av, NULL);
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);

	return (0);
}
