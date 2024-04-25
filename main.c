#include "shell.h"

/**
 *
 *
 */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
		shell_inter();
	else
		shell_non_inter();

	return (0);
}
