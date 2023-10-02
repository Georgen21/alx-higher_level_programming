#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: to check linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *dull = list;
	listint_t *swift = list;

	if (!list)
		return (0);
	while (dull && swift && swift->next)
	{
		dull = dull->next;
		swift = swift->next->next;
		if (dull == swift)
			return (1);
	}

	return (0);
}
