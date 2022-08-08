#include "shell.h"
#include <stdio.h>

/**
 * main - starts the shell prgram\
 *
 * Return: 0 Always
 */


int main (void)
{
	char **argv, *str;
	int status;
	size_t i = 1024;
	pid_t pid;
	int prompt, j = 0;

	argv = malloc(sizeof(char *) * 2);
	argv[1] = NULL;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		prompt = getline(&str, &i, stdin);
		if (prompt == -1 || prompt == EOF)
		{
			perror("GETLINE ERROR");
			break;
		}
		argv = make_args(str);
		/*if (argv[0][0] == '\n')
		{
			perror("New line");
		}*/
		while (argv && argv[j])
		{
			printf("%s\n", argv[j]);
			j++;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("FORK ERROR");
			return (1);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("EXECVE ERROR");
				return (2);
			}
			return (0);
		}
		else
			wait(&status);
	}
	return (0);
}
