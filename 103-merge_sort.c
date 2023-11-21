#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of the given array.
 * @array: The array containing the subarrays to be merged.
 * @tmp: A temporary array used for merging.
 * @start: The starting index of the first subarray.
 * @mid: The ending index of the first subarray.
 * @end: The ending index of the second subarray.
 */
void merge(int *array, int *tmp, int start, int mid, int end)
{
    int size_left = mid - start + 1;
    int size_right = end - mid;

    // Create temporary arrays
    int left[size_left];
    int right[size_right];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < size_left; i++)
        left[i] = array[start + i];
    for (int j = 0; j < size_right; j++)
        right[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into array[start..end]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = start; // Initial index of merged subarray

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, size_left);
    printf("[right]: ");
    print_array(right, size_right);

    while (i < size_left && j < size_right)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < size_left)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < size_right)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(&array[start], size_left + size_right);
}

/**
 * merge_sort_recursive - Recursive part of the Merge Sort algorithm
 * @array: Array to be sorted
 * @tmp: Temporary array for merging
 * @start: Start index of the subarray
 * @end: End index of the subarray
 */
void merge_sort_recursive(int *array, int *tmp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		merge_sort_recursive(array, tmp, start, mid);
		merge_sort_recursive(array, tmp, mid + 1, end);

		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_recursive(array, tmp, 0, size - 1);

	free(tmp);
}
