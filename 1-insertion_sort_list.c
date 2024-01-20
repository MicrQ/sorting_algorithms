#include "sort.h"
/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}


/**
 * insertion_sort_list - a function that sortes a doubly linked list
 * @list: a doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *goBack, *head = *list, *tmp, *prv;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

    for (goBack = head->next; goBack; goBack = tmp)
    {
        tmp = goBack->next;
		prv = goBack->prev;

		while (prv && goBack->n < prv->n)
		{
			swap(list, &prv, goBack);
			print_list((const listint_t *)*list);
		}
    }
}
