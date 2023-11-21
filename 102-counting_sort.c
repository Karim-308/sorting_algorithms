#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the counting array */
    int *counting_array = malloc(sizeof(int) * (max + 1));
    if (counting_array == NULL)
        return;

    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Count the occurrences of each element in the original array */
    size_t i;
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    printf("Counting array:");
    print_array(counting_array, max + 1);

    /* Modify the original array based on the counting array */
    int idx = 0;
    for (int i = 0; i <= max; i++)
    {
        while (counting_array[i] > 0)
        {
            array[idx] = i;
            idx++;
            counting_array[i]--;
        }
    }

    /* Free the counting array */
    free(counting_array);
}
