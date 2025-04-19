#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * bitonic_merge - Recursively merges bitonic sequences
 * @array: The full array
 * @start: Starting index
 * @size: Total size of the array
 * @seq_size: Current bitonic sequence size
 * @direction: 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t start, size_t size,
		size_t seq_size, int direction)
{
	size_t i, half = seq_size / 2;

	if (seq_size <= 1)
		return;

	for (i = start; i < start + half; i++)
	{
		if ((direction && array[i] > array[i + half]) ||
		    (!direction && array[i] < array[i + half]))
			swap(&array[i], &array[i + half]);
	}

	bitonic_merge(array, start, size, half, direction);
	bitonic_merge(array, start + half, size, half, direction);
}

/**
 * bitonic_recursive - Recursive function for Bitonic sort
 * @array: The full array
 * @start: Starting index
 * @size: Total size of the array
 * @seq_size: Current bitonic sequence size
 * @direction: 1 for ascending, 0 for descending
 */
void bitonic_recursive(int *array, size_t start, size_t size,
		size_t seq_size, int direction)
{
	size_t half = seq_size / 2;

	if (seq_size <= 1)
		return;

	printf("Merging [%lu/%lu] (%s):\n", seq_size, size,
			direction ? "UP" : "DOWN");
	print_array(array + start, seq_size);

	bitonic_recursive(array, start, size, half, 1); /* ascending */
	bitonic_recursive(array, start + half, size, half, 0); /* descending */
	bitonic_merge(array, start, size, seq_size, direction);

	printf("Result [%lu/%lu] (%s):\n", seq_size, size,
			direction ? "UP" : "DOWN");
	print_array(array + start, seq_size);
}

/**
 * bitonic_sort - Sorts an array of ints in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursive(array, 0, size, size, 1);
}

