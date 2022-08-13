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
	/*int i = 0;*/

	/*while (ptr[i]) */
	free(ptr[0]);
	printf("Freed\n");

	printf("Freed 1\n");
	free(ptr);
	printf("Freed 2\n");
}
