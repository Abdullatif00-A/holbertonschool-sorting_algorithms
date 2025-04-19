#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array using Counting sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i, *count = NULL, *output = NULL;
	size_t j;

	if (!array || size < 2)
		return;

	/* Find max value */
	for (j = 0; j < size; j++)
		if (array[j] > max)
			max = array[j];

	/* Allocate memory */
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	/* Initialize count array */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Store counts of elements */
	for (j = 0; j < size; j++)
		count[array[j]]++;

	/* Update count array to contain positions */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Print the counting array */
	print_array(count, max + 1);

	/* Build the sorted array */
	for (j = size; j > 0; j--)
	{
		output[count[array[j - 1]] - 1] = array[j - 1];
		count[array[j - 1]]--;
	}

	/* Copy sorted values back */
	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}

