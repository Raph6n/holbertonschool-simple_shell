#include "shell.h"

/**
 * exec_non_inter - Execute the command.
 * @tokens: Array of tokens representing the command.
 */

void exec_non_inter(char **tokens)
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Execution failed");
			exit(1);
		}
	}
	else
		waitpid(pid, NULL, 0);
}
