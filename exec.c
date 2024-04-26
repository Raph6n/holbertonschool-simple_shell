#include "shell.h"

/**
 * exec - Execute the command.
 * @tokens: Array of tokens representing the command.
 */

void exec(char **tokens)
{
	pid_t pid = fork();/*call the function fork*/
	char *path, *token, cmd_path[1024];

	if (pid < 0)/*fork failed*/
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)/*code execute in the child process*/
	{
		if (tokens[0] != NULL)/*if we use echo instead of the prompt*/
			execve(tokens[0], tokens, NULL);

		path = location();
		token = strtok(path, ":");/*cut the path each :*/
		while (token != NULL && tokens[0] != NULL)
		{
			sprintf(cmd_path, "%s/%s", token, tokens[0]);
			if (access(cmd_path, X_OK) == 0)
			{/*no path executable*/
				execve(cmd_path, tokens, NULL);
				perror("Execution failed");
				exit(1);
			}
			token = strtok(NULL, ":");
		}
		fprintf(stderr, "Command not found: %s\n", tokens[0]);
		exit(1);
	}
	else/*code execute in the parent process*/
		waitpid(pid, NULL, 0);/*wait for the child process*/
}
