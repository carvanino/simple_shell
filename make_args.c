#include "shell.h"

/**
 * make_args - splits string into tokens an stores the addresses in any array
 *
 * @str: string
 *
 * Return: Pointer to array of strings
 */

char **make_args(char *str)
{
	char **splitted, *strcopy = NULL, *tok;
	int len = 0, i = 0;

	if (!str)
		return (NULL);
	strcopy = _strdup(str);
	if (strcopy && tokenize(strcopy, " "))
	{
		len++;
		while (tokenize(NULL, " "))
			len++;
	}
	free(strcopy);

	if (len > 0)
	{
		splitted = malloc(sizeof(char *) * len + 1);

		if (splitted)
		{
			tok = tokenize(str, " \n");
			while (tok)
			{
				splitted[i] = tok;
				tok = tokenize(NULL, " \n");
				i++;
			}
			splitted[i] = NULL;
			i = 0;
			while (splitted && splitted[i])
				i++;
			free_args(splitted);
			return (splitted);
		}
		free_args(splitted);
	}
	free_args(splitted);
	return (NULL);
}
