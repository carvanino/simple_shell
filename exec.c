#include "shell.c"

/**
 * execute - execute an argument
 *
 * @ptr: pointer to argument
 *
 * Return: 0 if Success -1 if fail
 */

int execute(char **argv)
{
	pid_t pid;
	int status;

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
	{
		wait(&status);
	}
	return (0);
}
