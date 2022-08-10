#include "shell.h"

/**
 * shell_env - gets environmental variable
 *
 * @args: environmental variable
 *
 * Return: 0 Always
 */

int shell_env(char **args __attribute__((unused)))
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
