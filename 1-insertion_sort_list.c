#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: double pointer to the list
 * Return: void.
**/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = *list;

	while (temp != NULL)
	{
		current = temp;

		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_doubly_linked_list(list, current);
		}

		temp = temp->next;
	}

}

/**
 * swap_doubly_linked_list - swaps node of a doubly linked list with previous
 * @head: head pointer to the list
 * @node: node to be swapped
 * Return: pointer to the start address of the list
 */
listint_t *swap_doubly_linked_list(listint_t **head, listint_t *node)
{
	listint_t *next_node, *prev_node;

	if (node->prev == *head)
		*head = node;

	next_node = node->next;
	prev_node = node->prev;

	if (prev_node->prev != NULL)
		prev_node->prev->next = node;

	if (next_node != NULL)
		next_node->prev = node->prev;

	node->prev = prev_node->prev;
	node->next = prev_node;
	prev_node->next = next_node;
	prev_node->prev = node;
	print_list(*head);
	return (*head);

}
