#include "shell.h"
#include "prompt.c"
#include "execve.c"


int main(void)
{

	prompt();
	execve();
}
