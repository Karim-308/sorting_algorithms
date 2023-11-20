#include "sort.h"

/**
 * bubble_sort - Sorts an integers array in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, index;
    int tmp;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        for (index = 0; index < size - 1; index++)
        {
            if (index + 1 < size && array[index] > array[index + 1])
            {
                /* Swap the elements */
                tmp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = tmp;

                /* Print the array after each swap */
                print_array(array, size);
            }
        }
    }
}
