#include "sort.h"

/**
 * swap_nodes_in - Swaps two nodes in a doubly linked list.
 *
 * @list: A pointer to a doubly linked list
 * @node: The node to be swapped with its previous node
 */
void swap_nodes_in(listint_t **list, listint_t *node)
{
	if (node->prev != NULL && node->n < node->prev->n)
	{
		/* Swap the nodes */
		node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
		node->next = node->prev;
		node->prev = node->prev->prev;
		node->next->prev = node;

		/* Update the list pointer if needed */
		if (node->prev == NULL)
			*list = node;
	}
}

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
			swap_nodes_in(list, current_node);
			print_list(*list);
		}

		current_node = temp_node;
	}
}
