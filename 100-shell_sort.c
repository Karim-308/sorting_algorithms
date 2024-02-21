#include "sort.h"
#include <stddef.h>

/**
 * swap - Swaps the positions of two elements in an array
 * @array: The array
 * @item1: Index of the first element
 * @item2: Index of the second element
 */
void swap(int *array, size_t item1, size_t item2)
{
    int tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell sort algorithm
 * with the Knuth sequence
 * @array: The array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t gap, i, index;

    // Generate the initial gap using the Knuth sequence
    for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
        ;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            int temp = array[i];
            index = i;

            // Insertion sort with the current gap
            while (index >= gap && array[index - gap] > temp)
            {
                array[index] = array[index - gap];
                index -= gap;
            }

            array[index] = temp;
        }

        // Reduce the gap
        gap /= 3;
    }
}
