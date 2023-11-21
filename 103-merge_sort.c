#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

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
