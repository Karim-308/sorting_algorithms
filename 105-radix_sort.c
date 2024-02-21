#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Helper function to get the maximum element from an array
 * @array: The array to find the maximum element from
 * @size: The size of the array
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/**
 * countingSort - Helper function to perform counting sort on an array based on
 *                the significant digit represented by exp
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The exponent representing the significant digit
 */
void countingSort(int *array, size_t size, int exp) {
    int output[size];
    int count[10] = {0};

    // Count the occurrence of each digit in array
    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Update count[i] to contain the actual position of the digit in output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to the original array
    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    // Print the array after sorting for the current significant digit
    print_array(array, size);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix sort algorithm (LSD)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    int max = getMax(array, size);

    // Perform counting sort for every digit, starting from the least significant digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
    }
}
