#include "shell.h"

/**
 * find_path - checks what directory an argument is located
 *
 * @argv: pointer tonan array of strings passed as arguments
 *
 * Return: the full path of the argument if found
 * Otherwise: Return the argument that was passed intially
 */

char *find_path(char *argv)
{
	int i = 0;
	int n_token;
	struct stat st;
	char *str_cpy, *env_var, *token;
	char **tokens;

	if (argv[0] != '/')
	{
		env_var = getenv("PATH");
		/* Have a copy of env_var */
		str_cpy = malloc(sizeof(char) * strlen(env_var));
		_strcpy(str_cpy, env_var);
		/* Get number of tokens */
		n_token = n_toks(env_var, ":");
		/*printf("%d\n", n_token);*/

		/* An array to store token */
		tokens = malloc(sizeof(char *) * n_token);
		token = strtok(str_cpy, ":");
		while (token != NULL)
		{
			tokens[i] = malloc(sizeof(char) * strlen(token));
			_strcpy(tokens[i], token);
			i++;
			token = strtok(NULL, ":");
		}
		tokens[i] = "\0";
		/*printf("Here\n");*/
		i = 0;
		/* Move through thw array of tokens and add the a "/" with the argument*/
		 /* passed */
		while (tokens[i] != NULL)
		{
			_strcat(tokens[i], "/");
			_strcat(tokens[i], argv);

			/* Check for each if the argument is files im the directory */
			if (stat(tokens[i], &st) == 0)
			{
				printf("%s\n", tokens[i]);
				return (tokens[i]); /* tokens[i] FOUND */
			}
			i++;
		}
	}
	return (0);
}
