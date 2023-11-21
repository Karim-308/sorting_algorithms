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

    listint_t *current, *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            /* Swap the nodes */
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;

            /* Update the list pointer if needed */
            if (current->prev == NULL)
                *list = current;

            /* Print the list after each swap */
            print_list(*list);
        }

        current = temp;
    }
}
