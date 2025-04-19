#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_split - Prints the merging process
 * @side: "left", "right", or "Done"
 * @array: Subarray to print
 * @start: Starting index
 * @end: Ending index (exclusive)
 */
void print_split(const char *side, int *array, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * merge - Merges two subarrays into a temporary buffer
 * @array: The full array being sorted
 * @start: Start index of left subarray
 * @mid: Midpoint index
 * @end: End index of right subarray
 * @temp: Temporary buffer array
 */
void merge(int *array, size_t start, size_t mid, size_t end, int *temp)
{
	size_t i = start, j = mid, k = start;

	printf("Merging...\n");
	print_split("left", array, start, mid);
	print_split("right", array, mid, end);

	while (i < mid && j < end)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < end)
		temp[k++] = array[j++];

	for (i = start; i < end; i++)
		array[i] = temp[i];

	print_split("Done", array, start, end);
}

/**
 * merge_sort_recursive - Recursive top-down merge sort
 * @array: The array to sort
 * @start: Start index
 * @end: End index
 * @temp: Temporary buffer
 */
void merge_sort_recursive(int *array, size_t start, size_t end, int *temp)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = start + (end - start) / 2;
	merge_sort_recursive(array, start, mid, temp);
	merge_sort_recursive(array, mid, end, temp);
	merge(array, start, mid, end, temp);
}

/**
 * merge_sort - Sorts an array using top-down Merge sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, 0, size, temp);
	free(temp);
}

