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
		str_cpy = malloc(sizeof(char) * strlen(env_var));/* Have a copy of env_var */
		_strcpy(str_cpy, env_var);
		n_token = n_toks(env_var, ":");  /* Get number of tokens */
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
				argv = _strdup(tokens[i]);
				return (argv); /* tokens[i] FOUND */
			}
			i++;
		}
	}
	return (argv);
}


/**
 * check_path - checks if the command exists in the path
 *
 * @args: pointer to strings
 *
 * Return: pointer to string
 */

char **check_path(char **args)
{
	char *filename = NULL, *delim, *path = NULL, *dir = NULL;
	struct stat st;

	delim = ":";
	path = _strdup(getenv("PATH"));
	if (!path)
		exit(5);
	if (stat(args[0], &st) == 0)
	{
		free(path);
		return (args);
	}
	dir = strtok(path, delim);
	while (dir != NULL)
	{
		filename = path_concat(dir, args[0]);
		if (stat(filename, &st) == 0)
		{
			args[0] = filename;
			free(path);
			return (args);
		}
		dir = strtok(NULL, delim);
		free(filename);
	}
	free(path);
	return (NULL);

}

/**
 * path_concat - concatenate s1 and s2 adding the "/" between
 *
 * @s1: desrination
 * @s2: source
 *
 * Return: pointer to concatenated atring
 */

char *path_concat(char *s1, char *s2)
{
	char *s, *p;
	int len1, len2;

	len1 = len2 = 0;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	s = p = malloc((len1 + len2 + 2) * sizeof(char));
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '/';
	s++;
	while (*s2)
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (p);


}
