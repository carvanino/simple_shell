#include "shell.h"

/**
 * main - starts the shell prgram\
 *
 * Return: 0 Always
 */


int main (void)
{
	char **argv;
	int status;
	size_t i = 1024;
	pid_t pid;

	argv = malloc(sizeof(char *) * 2);
	argv[1] = NULL;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&argv[0], &i, stdin) == -1)
		{
			perror("GETLINE ERROR");
			continue;
		}
		argv[0] = strtok(argv[0], "\n");
		if (argv[0][0] == '\n')
			continue;

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
