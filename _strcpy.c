#include "shell.h"

/**
 * _strcpy - copies string from src to dest
 *
 * @dest: destination
 * @src: source
 *
 * Return: destination
 */

char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len + 1; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
