#include "sort.h"

/**
 * swap - swaps two adjacent nodes the forward coming back
 * and vice-versa
 *
 * @head: the head of the list
 * @left: the node to move forward
 * @right: the node to move back
 */

void swap(listint_t **head, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;
	if (right->next != NULL)
		right->next->prev = *left;

	right->prev = (*left)->prev;
	right->next = *left;

	if ((*left)->prev != NULL)
		(*left)->prev->next = right;
	else
		*head = right;
	(*left)->prev = right;
	*left = right->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 *
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *boundary, *forward, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	boundary = (*list)->next;
	while (boundary)
	{
		temp = boundary->next;
		forward = boundary->prev;
		while (forward && boundary->n < forward->n)
		{
			swap(list, &forward, boundary);
		       print_list((const listint_t *)*list);
		}

		boundary = temp;
	}
}
