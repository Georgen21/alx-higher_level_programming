#include "lists.h"
#include <stdio.h>

/**
 * reverse_listint - reverses linked list
 * @head: first node pointer
 * Return: pointer to the first node in the list
 */
void reverse_listint(listint_t **head)
{
	listint_t *first = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	while (current)
	{
		next = current->next;
		current->next = first;
		first = current;
		current = next;
	}

	*head = first;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *bump = *head, *speed = *head, *idle = *head, *twin = NULL;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (1)
	{
		speed = speed->next->next;
		if (!speed)
		{
			twin = bump->next;
			break;
		}
		if (!speed->next)
		{
			twin = bump->next->next;
			break;
		}
		bump = bump->next;
	}

	reverse_listint(&twin);

	while (twin && idle)
	{
		if (idle->n == twin->n)
		{
			twin = twin->next;
			idle = idle->next;
		}
		else
			return (0);
	}

	if (!twin)
		return (1);

	return (0);
}
