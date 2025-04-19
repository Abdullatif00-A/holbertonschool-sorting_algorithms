#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array.
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * hoare_partition - Performs the Hoare partition scheme
 * @array: The array
 * @low: The low index
 * @high: The high index
 * @size: The size of the array
 * Return: The partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Recursive quicksort
 * @array: The array
 * @low: The low index
 * @high: The high index
 * @size: The array size
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = hoare_partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, p, size);
		quick_sort_hoare_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using Hoare partition scheme
 * @array: The array
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}

