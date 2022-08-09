#include "shell.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: destination of string to conactenated
 * @src: string to be added to dest
 *
 * Return: concatenated string in dest
 */

char *_strcat(char *dest, char *src)
{
	int len, i;

	for (len = 0; dest[len]; len++)
	{
	}
	for (i= 0; src[i]; i++, len++)
	{
		dest[len] = src[i];
	}
	return (dest);
}
