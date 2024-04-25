#include "shell.h"

/**
 * exec - Execute the command.
 * @tokens: Array of tokens representing the command.
 */

void exec(char **tokens)
{
	pid_t pid = fork();
	char *path = NULL, *token;
	char cmd_path[1024];
	int i;

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		if (tokens[0] != NULL)
			execve(tokens[0], tokens, NULL);
		for (i = 0; environ[i] != NULL; i++)
		{
			if (strncmp(environ[i], "PATH=", 5) == 0)
			{
				path = environ[i] + 5;
				break;
			}
		}

		if (path == NULL)
		{
			fprintf(stderr, "PATH environment variable not found\n");
			exit(1);
		}

		token = strtok(path, ":");

		while (token != NULL && tokens[0] != NULL)
		{
			strcpy(cmd_path, token);
			strcat(cmd_path, "/");
			strcat(cmd_path, tokens[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				execve(cmd_path, tokens, NULL);
				perror("Execution failed");
				exit(1);
			}
			token = strtok(NULL, ":");
		}

		fprintf(stderr, "Command not found: %s\n", tokens[0]);
		exit(1);
	}
	else
		waitpid(pid, NULL, 0);
}
