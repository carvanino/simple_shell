#include "shell.h"

/**
 * check_builtin - check a builtin command is entered
 *
 * @args: pointer to the command entered
 *
 * Return: NULL if there's no match or a function toe execute builtin
 */

int check_builtin(char **args)
{
	builtin commands[] = {
			{"exit", shell_exit},
			{"env", shell_env},
			{NULL, NULL}
	};
	int i;

	for (i = 0; commands[i].name; i++)
	{
		if (_strcmp(commands[i].name, args[0]) == 0)
			return (commands[i].f(args));
	}
	return (-1);
}
