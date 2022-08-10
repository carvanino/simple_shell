
/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: an int
 */

int _strcmp(char *s1, char *s2)
{
	int i, n;

	i = n = 0;
	while (n == 0)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			n = s1[i] - s2[i];
			return (n);
		}
		n = s1[i] - s2[i];
		i++;
	}
	return (n);
}
