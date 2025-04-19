#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array
 * @a: Pointer to first element
 * @b: Pointer to second element
 */
void swap(int *a, int *b)
{
	int tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * hoare_partition - Hoare partition scheme for Quick Sort
 * @array: Array to sort
 * @low: Lowest index
 * @high: Highest index
 * @size: Size of the array
 * Return: Final partition index
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
		} while (i <= high && array[i] < pivot);

		do {
			j--;
		} while (j >= low && array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare - Recursive quicksort with Hoare partition
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Array size
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
 * quick_sort_hoare - Sort array using Quick sort with Hoare scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}

