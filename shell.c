#include "shell.h"

/**
 * main - starts the shell prgram\
 *
 * Return: 0 Always
 */


int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char **argv, *str = NULL, *command;
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
					command = argv[0];
					check = check_path(&command);
					if (check != 1)
					{
						execute(argv, command);
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

int execute(char **argv, char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("FORK ERROR");
		/*free_args(argv);  edit */
		return (1);
	}
	if (pid == 0)
	{
		printf("%s", command);
		parent = 0;
		if (execve(command, argv, environ) == -1)
		{
			perror("EXECVE ERROR");
			/*free_args(argv);  Edit */
			return (2);
		}
		if (argv[0] != command)
			free(command);
		free(argv);
		return (0);
	}
	else
	{
		wait(&status);
		if (argv[0] != command)
			free(command);
		free(argv);
	}
	return (-1);
}

void get_args(void)
{
	char **argv, *str, *command;
	size_t i = 0;
	int check;
	while (getline(&str, &i, stdin) != -1)
	{
		if (str[0] != '\n')
		{
			argv = make_args(str);
			if (check_builtin(argv) == -1)
			{
				command = argv[0];
				check = check_path(&command);
				if (check != 1)
				{
					execute(argv, command);
				}
				else
				{
					_puts("shell: ");
					_puts(str);
					_puts(": command not found\n");
					free(argv);/* changed to just free_args */
				}
			}
		}
	}
	exit(0);
}


void sighandler(int sig_num)
{
	(void)sig_num;
	if (parent == 1)
		_puts("\n$ ");
	signal(SIGINT, sighandler);
}
