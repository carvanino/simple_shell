#include "shell.h"

/**
 * free_args - frees an array of pointers
 *
 * @ptr: pointer to array of pointers
 *
 * Return: NOthing
 */

void free_args(char **ptr)
{
	int i = 0;

	while (ptr[i] && ptr)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
