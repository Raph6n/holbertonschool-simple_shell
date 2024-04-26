#include "shell.h"

/**
 * location - get the path
 * Return: the path.
 */

char *location(void)
{
	int i;
	char *path;

	for (i = 0; environ[i] != NULL; i++)/*search the path*/
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	if (path == NULL)/*path not found*/
	{
		fprintf(stderr, "PATH variable not found\n");
		exit(1);
	}

	return (path);
}
