#include "sort.h"

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

/**
 * cocktail_sort_list - sorts a list in ascending order 
 * @list: double pointer to the list
 * Return: void 
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *tail;
	int check = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = tail = *list;

	while (tail != NULL)
		tail = tail->next;

	while (check)
	{
		check = 0;
		end = start;

		while (end != tail)
        {
            if (end->n > end->next->n)
		    {
			    swap_doubly_linked_list(list, end);
                check = 1;
		    }
            end = end->next;
        }
		if (check == 0)
			break;
        
        check = 0;

		tail = tail->prev;
		end = tail;

		while (end != start)
        {
            if (end->prev->n > end->n)
		    {
			    swap_doubly_linked_list(list, end);
			    check = 1;
		    }
            end = end->prev;
        }
        start = start->next;
	}
}
