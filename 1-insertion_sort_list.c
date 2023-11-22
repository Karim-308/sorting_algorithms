#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 *
 * @list: A pointer to a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;
	listint_t *temp_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node != NULL)
	{
		temp_node = current_node->next;

		while (current_node->prev != NULL && current_node->n < current_node->prev->n)
		{
			swap_nodes(list, current_node);
			print_list(*list);
		}

		current_node = temp_node;
	}
}
