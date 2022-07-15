#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: double pointer to the list
 * Return: void.
**/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	/* checking if the list is empty or has only one node */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = *list;

	/* Looping till the end node is reached */
	while (temp != NULL)
	{
		current = temp;

		/* checking that the current node has a previous node */
		/* And that the data in previous node is > the that of curent node */
		/* This *cuurent will always point at the same node, hence... */
		/* ... an indirect way of doing a current--, if that makes sense */
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_doubly_linked_list(list, current);
		}

		/* Moving the temp node upward until it reaches the last node */
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

	/* When swapping the first two nodes */
	if (node->prev == *head)
		*head = node;

	/* two pointers to point before and after the current node */
	next_node = node->next;
	prev_node = node->prev;

	/* when *prev_node points to any node except the first node */
	if (prev_node->prev != NULL)
		prev_node->prev->next = node;

	/* when the swapping the last node. *next_node == NULL */
	if (next_node != NULL)
		next_node->prev = node->prev;

	/* Swapping the links between four nodes */
	node->prev = prev_node->prev;
	node->next = prev_node;
	prev_node->next = next_node;
	prev_node->prev = node;
	print_list(*head);
	return (*head);

}
