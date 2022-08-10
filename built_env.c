#include "shell.h"

/**
 * _env - gets environmental variable
 *
 * @env: environmental variable
 */

void _env(char **environ)
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
