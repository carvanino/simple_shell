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
	char **splitted, *strcopy = NULL;
	int len = 0, i = 1;

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
			str = strtok(str, "\n");
			splitted[0] = strtok(str, " ");
			while (len > i)
			{
				splitted[i] = strtok(NULL, " ");
				i++;
			}
			splitted[i] = NULL;
			return (splitted);
		}
	}
	return (NULL);
}
