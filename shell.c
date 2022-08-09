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
	int status;
	size_t i = 0;
	pid_t pid;
	/*int prompt;*/

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&str, &i, stdin) != -1)
		{
			if (str[0] != '\n')
			{
				printf("Here\n");
				argv = make_args(str);


				printf("Here2");
				argv[0] = find_path(argv[0]);
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
						free_args(argv);
						return (2);
					}
					free_args(argv);
					return (0);
				}
				else
					wait(&status);
				free_args(argv);
			}
			else
			{
				/*free(str);*/
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
