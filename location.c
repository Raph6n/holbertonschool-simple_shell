#include "shell.h"

char *location(char *command)
{
	char *path = getenv("PATH"), *token, *full_path;

	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
