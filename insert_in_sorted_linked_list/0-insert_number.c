#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head:double pointer (points to the head of the list)
 * @number: number to insert it into the list
 * Return: the address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_n = malloc(sizeof(listint_t));

	if (new_n == NULL)
	{
		return (NULL);
	}
	new_n->n = number;
	new_n->next = NULL;
	if (*head == NULL || (*head)->n >= number)
	{
		new_n->next = *head;
		*head = new_n;
		return (new_n);
	}
	listint_t *tmp = *head;

	while (tmp->next != NULL && tmp->next->n < number)
	{
		tmp = tmp->next;
	}
	new_n->next = tmp->next;
	tmp->next = new_n;
	return (new_n);
}
