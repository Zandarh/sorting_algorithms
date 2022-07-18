#include "sort.h"

/**
 * nodes_swap - swapped the nodes in a list
 *
 * @list: first node in doubly linked list
 * @first: address of first node
 * @second: address of second node
 */
void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first->prev)	/* at the first node */
		*list = second;
	else
		first->prev->next = second;

	second->prev = first->prev;

	if (second->next)	/* at the last node */
		second->next->prev = first;


	first->prev = second;
	first->next = second->next;
	second->next = first;
}

/**
 * cocktail_sort_list - sorts a list in ascending order
 * @list: double pointer to the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end;
	int check = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = *list;
	while (check)
	{
		check = 0;
		while (end->next)
		{
			if (end->n > end->next->n)
			{
				nodes_swap(list, end, end->next);
				print_list(*list);
				check = 1;
				continue;
			}
			end = end->next;
		}
		if (check == 0)
			break;
		check = 0;
		while (end->prev)
		{
			if (end->n < end->prev->n)
			{
				nodes_swap(list, end->prev, end);
				print_list(*list);
				check = 1;
				continue;
			}
			end = end->prev;
		}
	}
}
