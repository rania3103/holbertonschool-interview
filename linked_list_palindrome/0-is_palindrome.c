#include "lists.h"
#include <stdlib.h>
#include <string.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the singly linked list
 * Return:0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int i, length;
	char *stri, *rev_stri;
	listint_t *tmp;

	length = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		length += 1;
		tmp = tmp->next;
	}
	stri = malloc(length + 1);
	rev_stri = malloc(length + 1);
	if (stri == NULL || rev_stri == NULL)
	{
		free(stri);
		free(rev_stri);
		return (0);
	}
	tmp = *head;
	for (i = 0; i < length; i++)
		stri[i] = tmp->n + '0';
	stri[i] = '\0';
	for (i = 0; i < length; i++)
		rev_stri[i] = stri[length - 1 - i];
	rev_stri[i] = '\0';
	for (i = 0; i < length; i++)
	{
		if (stri[i] != rev_stri[i])
		{
			free(stri);
			free(rev_stri);
			return (0);
		}
	}
	free(stri);
	free(rev_stri);
	return (1);
}
