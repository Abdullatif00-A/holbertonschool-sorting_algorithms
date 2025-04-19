#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two integers in an array
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
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: The array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array
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
 * quicksort_hoare - Recursively sorts array using Hoare's scheme
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quicksort_hoare(array, low, p, size);
		quicksort_hoare(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Entry function for quick sort with Hoare partition
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, (int)size - 1, size);
}

