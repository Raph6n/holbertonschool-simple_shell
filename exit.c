#include "shell.h"

/**
 * exit_shell - built-in for exit
 * @first_tok: correspond of tokens[0] from the token return
 * from the function process.
 * Return: 1 if success or 0 if fail.
 */

int exit_shell(char *first_tok)
{
	if (strcmp(first_tok, "exit") == 0)
		return (1);
	return (0);
}
