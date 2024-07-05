#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - checks whether or not a given integer is a palindrome.
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char normal[21];
	char reversed[21];
	int len, i;


	sprintf(normal, "%lu", n);
	len = strlen(normal);
	for (i = 0; i < len; i++)
	{
		reversed[i] = normal[len - 1 - i];
	}
	reversed[len] = '\0';
	if (strcmp(normal, reversed) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
