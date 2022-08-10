
/**
 * _strlen - gets the length of a string
 *
 * @s: string to be counted
 *
 * Description: return length of string s
 *
 * Return: number of characters in the string s
 *
 */

int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count = count + 1;
		s++;
	}
	return (count);
}
