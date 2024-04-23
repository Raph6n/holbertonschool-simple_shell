#include "shell.h"

/**
 * exec - Execute the command.
 * @tokens: Array of tokens representing the command.
 */

void exec(char **tokens)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (strcmp(tokens[0], "echo") == 0)
		{
			if (execvp(tokens[1], &tokens[1]) == -1)
			{
				perror("Execution failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (execvp(tokens[0], tokens) == -1)
			{
				perror("Execution failed");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
		wait(NULL);
}

