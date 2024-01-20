#include "sort.h"

/**
 * insertion_sort_list - a function that sortes a doubly linked list
 * @list: a doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current; current = current->next)
	{
		temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			if (temp->next)
				temp->next->prev = temp->prev;

			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev)
				temp->prev->next = temp;
			print_list(*list);
		}
	}
}

