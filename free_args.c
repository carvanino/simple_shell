#include "shell.h"

/**
 * free_args - frees an array of pointers
 *
 * @ptr: pointer to array of pointers
 *
 * Return: Nothing
 */

void free_args(char **ptr)
{
	free(ptr[0]);

	free(ptr);
}
