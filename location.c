#include "shell.h"

char *location(char *command)
{
	extern char **environ;
	char *path = NULL, *token, *full_path;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = &environ[i][5];
			break;
		}
	}

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
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
