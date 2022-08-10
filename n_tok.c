#include "shell.h"

/**
 * n_toks - gets the number of token from a string
 *
 * @str: string ti be tokenized or parsed
 * @delim: delimiter
 *
 * Return: Number of tokens
 */

int n_toks(char *str, char *delim)
{
	int num = 0;
	char *token;

	token = strtok(str, delim);
	while (token != NULL)
	{
		num++;
		token = strtok(NULL, delim);
	}
	num++; /* creates space for NULL character */

	return (num);
}
