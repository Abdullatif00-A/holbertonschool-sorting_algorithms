#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swaps two integers
 * @a: First int
 * @b: Second int
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: The array
 * @low: Start index
 * @high: End index
 * @size: Size of array
 * Return: New partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
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

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Recursively sorts using Hoare scheme
 * @array: The array
 * @low: Lower index
 * @high: Upper index
 * @size: Size of array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, p, size);
		quick_sort_hoare_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Quick sort with Hoare partition scheme
 * @array: The array
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}

