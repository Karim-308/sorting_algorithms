#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array.
 * @array: The array containing the integers.
 * @a: Index of the first integer.
 * @b: Index of the second integer.
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];
	
	array[a] = array[b];
	array[b] = temp;
}

/**
 * sift_down - Adjusts the position of an element in the heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @root: The root index of the subtree to sift down.
 * @end: The index where the sift down should stop.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (max != root)
	{
		swap(array, root, max);
		print_array(array, size);
		sift_down(array, size, max, end);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	int i;

	/* Build the heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Extract elements from the heap */
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
