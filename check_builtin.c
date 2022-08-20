#include "shell.h"

/**
 * check_builtin - check a builtin command is entered
 *
 * @args: pointer to the command entered
 *
 * Return: NULL if there's no match or a function toe execute builtin
 */

int check_builtin(char **args, char *str)
{
	builtin commands[] = {
			{"exit", shell_exit},
			{"env", shell_env},
			{NULL, NULL}
	};
	int i;
	if (args == NULL)
		return (-1);

	for (i = 1; commands[i].name; i++)
	{
		if (_strcmp(args[0], "exit") == 0)
			return (commands[0].f(args, str));
		if (_strcmp(commands[i].name, args[0]) == 0)
			return (commands[i].f(args));
	}
	return (-1);
}
