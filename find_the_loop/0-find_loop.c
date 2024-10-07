#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list.
 * @head:pointer to the head of a linked list.
 * Return:The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *step1 = head, *step2 = head;

	while (step2 && step2->next)
	{
		step1 = step1->next;
		step2 = step2->next->next;
		if (step1 == step2)
		{
			step1 = head;
			while (step1 != step2)
			{
				step1 = step1->next;
				step2 = step2->next;
			}
			return (step1);
		}
	}
	return (NULL);
}
