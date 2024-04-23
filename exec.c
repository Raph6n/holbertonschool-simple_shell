#include "shell.h"

/**
 * exec - Execute the command.
 * @tokens: Array of tokens representing the command.
 */

int exec(char **tokens)
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
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
	}
	return (-1);
}

