#include "shell.h"

/**
 * main - starts the shell prgram\
 *
 * Return: 0 Always
 */


int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char **argv, *str = NULL;
	int check;
	size_t i = 0;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	if (!isatty(STDIN_FILENO))
	{
		get_args();
		return (0);
	}
	
	while (1)
	{
		write(1, "$ ", 2);
		parent = 1;
		/*_puts("$ ");*/
		if (getline(&str, &i, stdin) != -1)
		{
			if (str[0] != '\n')
			{
				argv = make_args(str);
				if (check_builtin(argv) == -1)
				{
					check = check_path(argv);
					if (check != 1)
					{
						execute(argv);
					}
					else
					{
						_puts("shell: ");
						_puts(str);
						_puts(": command not found\n");
						free(argv); /*change to just free_args */
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
/*	free_args(argv);*/
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
		free_args(argv); /* edit */
		return (1);
	}
	if (pid == 0)
	{
		parent = 0;
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("EXECVE ERROR");
			free_args(argv); /* Edit */
			return (2);
		}
		free_args(argv);
		return (0);
	}
	else
	{
		wait(&status);
		free_args(argv);
	}
	return (-1);
}

void get_args(void)
{
	char **argv, *str;
	size_t i = 0;
	while (getline(&str, &i, stdin) != -1)
	{
		if (str[0] != '\n')
		{
			argv = make_args(str);
			if (check_builtin(argv) == -1)
			{
				int check = check_path(argv);
				if (check != 0)
				{
					execute(argv);
				}
				else
				{
					_puts("shell: ");
					_puts(str);
					_puts(": command not found\n");
					free(argv);/* changed to just free_args */
				}
			}
			free_args(argv); /* New //ill need to delete this or change to just free*/
		}
		free(argv);/* New //doesn't make a difference, so not needed */
	}
	{
		free(str);
		exit(0);
	}
}


void sighandler(int sig_num)
{
	(void)sig_num;
	if (parent == 1)
		_puts("\n$ ");
	signal(SIGINT, sighandler);
}
