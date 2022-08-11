#include "shell.h"

/**
 * check_delim - checks if a character is in the delim string
 *
 * @c: character
 * @delim: string of characters
 *
 * Return: 1 if found and 0 otherwise
 */

int check_delim(char c, char *delim)
{
	while(*delim)
	{
		if (*delim == c)
			return (0);
		delim++;
	}
	return (1);
}









/**
 * tokenize - works like strtok function
 *
 * @str: pointer to the string
 * @delim: delimiter
 *
 * Return: Address of the string before the delimiter or
 * 	NULL if the string is NULL
 */

char *tokenize(char * str, char * delim)
{
	static char *buffer = NULL;
	char *token;

	if (!buffer || str)
		buffer = str;

	while (*buffer && !check_delim(*buffer, delim))
		buffer++;

	if (!*buffer)
		return (NULL);

	token = buffer;
	while (*buffer && check_delim(*buffer, delim))
		buffer++;

	if (!check_delim(*buffer, delim))
	{
		*buffer = '\0';
		buffer++;
	}

	return (token);
}
