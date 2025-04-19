#include "sort.h"

/**
 * swap - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions the array using Hoare scheme
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Array size
 * Return: Index for the next recursion
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
 * hoare_quick_sort - Recursive function for quick sort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Array size
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		hoare_quick_sort(array, low, p, size);
		hoare_quick_sort(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Quick sort using Hoare partition
 * @array: The array to sort
 * @size: Array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, 0, size - 1, size);
}

