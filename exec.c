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
		exit(0);
	}
	else if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Execution failed");
			exit(0);
		}
	}
	else
		waitpid(pid, NULL, 0);
}


