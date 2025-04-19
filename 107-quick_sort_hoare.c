#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions the array using Hoare’s scheme
 * @array: The array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Array size (for printing)
 * Return: Index for the next recursive call
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

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

		if (array[i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * quick_sort_hoare_rec - Recursive function for quicksort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_hoare_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quick_sort_hoare_rec(array, low, pivot, size);
		quick_sort_hoare_rec(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using quick sort with Hoare scheme
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_rec(array, 0, size - 1, size);
}

