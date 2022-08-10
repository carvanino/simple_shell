#include "shell.h"
#include <stdio.h>

/**
 * main - starts the shell prgram\
 *
 * Return: 0 Always
 */


int main(void)
{
	char **argv, *str;
	/*int status;*/
	size_t i = 0;
	/*int prompt;*/

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&str, &i, stdin) != -1)
		{
			if (str[0] != '\n')
			{
				argv = make_args(str);
				if (check_builtin(argv) == -1)
				{
					argv = check_path(argv);
					if (argv != NULL)
					{
						execute(argv);
					}
					else
					{
						_puts("shell: ");
						_puts(str);
						_puts(": command not found\n");
					}
				}
			}
			{

			}
		}
		else
		{
			free(str);
			exit(9);
		}
	}
	return (0);
}
