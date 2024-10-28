#include "list.h"
/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: A pointer to the head of the linked list
 * @str:the string to copy into the new node
 * Return:Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	if (!list)
		return (NULL);
	List *new = malloc(sizeof(List));

	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
	}
	else
	{
		List *end = (*list)->prev;

		new->next = *list;
		new->prev = end;
		end->next = new;
		(*list)->prev = new;
	}
	return (new);
}

/**
 * add_node_begin - Add a new node at the beginning
 *  of a double circular linked list
 * @list: A pointer to the head of the linked list
 * @str:the string to copy into the new node
 * Return:Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	if (!list)
		return (NULL);
	List *new = malloc(sizeof(List));

	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
	}
	else
	{
		List *end = (*list)->prev;

		new->next = *list;
		new->prev = end;
		end->next = new;
		(*list)->prev = new;
		*list = new;
	}
	return (new);
}
