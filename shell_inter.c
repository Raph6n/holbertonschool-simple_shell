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
	char *prt = "$ ";
	size_t len = MAX_COMMAND_LENGTH;
	ssize_t read;
	pid_t pid;
        char *line = (char *)malloc(len * sizeof(char));

        if (line == NULL)
        {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
        }

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
			char *av[] = {line, NULL};
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
