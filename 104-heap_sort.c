#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array.
 * @a: First element
 * @b: Second element
 * @array: The array to print
 * @size: Size of the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}


/**
 * heapify - Maintains the max heap property.
 * @array: Array of integers
 * @size: Size of the full array
 * @heap_size: Current heap size
 * @root: Root index of the subtree
 */
void heapify(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;
	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest], array, size);
		heapify(array, size, heap_size, largest);
	}
}

/**
 * heap_sort - Sorts an array using heap sort algorithm.
 * @array: Array of integers to sort
 * @size: Number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;
	size_t heap_size;

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	/* Extract elements from heap */
	for (heap_size = size - 1; heap_size > 0; heap_size--)
	{
		swap(&array[0], &array[heap_size], array, size);
		heapify(array, size, heap_size, 0);
	}
}

