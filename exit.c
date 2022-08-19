#include "shell.h"

/**
 * shell_exit - exits the shell
 *
 * @args: pointer to the command entered
 *
 * Return: 0 if it succeeds and 1 if it fails
 */

int shell_exit(char **args, char *str)
{
	free(str);
	free(args);
	_exit(0);
}
