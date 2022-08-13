#include "shell.h"

/**
 * main - starts the shell prgram\
 *
 * Return: 0 Always
 */


int main(void)
{
	char **argv, *str;
	size_t i = 0;

	while (1)
	{
		write(1, "$ ", 2);
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
						free(argv);
					}
				}
			}
		}
		else
		{
			free(str);
			exit(9);
		}
	}
	free_args(argv);
	return (0);
}


/**
 * execute - execute the argument
 *
 * @argv: pointer to aegument to excute
 *
 * Return: 0 if Success -1 if Fail
 */

int execute(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("FORK ERROR");
		free(argv);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("EXECVE ERROR");
			free(argv);
			return (2);
		}
		return (0);
	}
	else
	{
		wait(&status);
		free(argv);
	}
	return (-1);
}
