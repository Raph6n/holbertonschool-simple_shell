#include "shell.h"

/**
 * exec - Execute the command.
 * @tokens: Array of tokens representing the command.
 */

void exec(char **tokens)
{
	pid_t pid = fork();
	char *path;
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		*path = location(tokens[0]);
		if (path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", tokens[0]);
			exit(EXIT_FAILURE);
		}
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Execution failed");
			exit(1);
		}
	}
	else
		waitpid(pid, NULL, 0);
}
