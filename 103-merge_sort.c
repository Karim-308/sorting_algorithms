#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_bottom_up(array, size);
}

/**
 * merge_sort_bottom_up - Sorts an array of integers using the bottom-up
 *                       approach of the Merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort_bottom_up(int *array, size_t size)
{
	size_t step, left;

	for (step = 1; step < size; step *= 2)
	{
		for (left = 0; left < size - 1; left += 2 * step)
		{
			size_t mid = left + step < size ? left + step : size;
			size_t right = left + 2 * step < size ? left + 2 * step : size;

			merge(array + left, mid - left, array + mid, right - mid);

			printf("[Done]: ");
			print_array(array, size);
		}
	}
}

/**
 * merge - Merges two subarrays into a sorted array.
 *
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 */
void merge(int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged;

	merged = malloc((left_size + right_size) * sizeof(int));
	if (merged == NULL)
		exit(EXIT_FAILURE);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < left_size)
		merged[k++] = left[i++];

	while (j < right_size)
		merged[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		left[i] = merged[i];

	free(merged);
}
