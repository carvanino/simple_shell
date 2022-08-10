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
	char **splitted, *strcopy = NULL, *pos = NULL, *tok;
	int len = 0, i = 0;

	if (!str)
		return (NULL);
	strcopy = _strdup(str);
	if (strcopy && strtok(strcopy, " "))
	{
		len++;
		while (strtok(NULL, " "))
			len++;
	}
	free(strcopy);

	if (len > 0)
	{
		splitted = malloc(sizeof(char *) * len + 1);

		if (splitted)
		{
			tok = strtok_r(str, " \n", &pos);
			while (tok)
			{
				splitted[i] = tok;
				tok = strtok_r(NULL, " \n", &pos);
				i++;
			}
			splitted[i] = NULL;
			i = 0;
			while (splitted && splitted[i])
			{
				printf("%s\n", splitted[i]);
				i++;
			}
			return (splitted);
		}
	}
	printf("NULL\n");
	return (NULL);
}
