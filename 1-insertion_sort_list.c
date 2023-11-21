#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm.
 *
 * @list: A pointer to a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->next;

        while (current->prev != NULL && current->prev->n > current->n)
        {
            current = swap_nodes(current, list);
            print_list(*list);
        }

        current = temp;
    }
}

/**
 * swap_nodes - Swaps a node with its previous one in a doubly linked list.
 *
 * @node: The node to be swapped
 * @list: A pointer to the doubly linked list
 * Return: The node that was entered
 */
listint_t *swap_nodes(listint_t *node, listint_t **list)
{
    listint_t *back = node->prev;
    listint_t *current = node;

    back->next = current->next;

    if (current->next != NULL)
        current->next->prev = back;

    current->next = back;
    current->prev = back->prev;
    back->prev = current;

    if (current->prev != NULL)
        current->prev->next = current;
    else
        *list = current;

    return (current);
}
