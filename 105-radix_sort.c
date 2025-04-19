#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_max - Get the maximum value in an array
 * @array: Array to scan
 * @size: Size of the array
 * Return: Maximum integer
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Counting sort by digit place
 * @array: Array to sort
 * @size: Size of array
 * @place: Significant digit to sort by (1 = units, 10 = tens, etc.)
 */
void counting_sort_radix(int *array, size_t size, int place)
{
	int count[10] = {0};
	int *output, i;
	size_t j;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Count occurrences */
	for (j = 0; j < size; j++)
		count[(array[j] / place) % 10]++;

	/* Update count[i] to have actual position of digit in output */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build output array */
	for (j = size; j > 0; j--)
	{
		output[count[(array[j - 1] / place) % 10] - 1] = array[j - 1];
		count[(array[j - 1] / place) % 10]--;
	}

	/* Copy sorted elements back to original array */
	for (j = 0; j < size; j++)
		array[j] = output[j];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array using the LSD Radix sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (place = 1; max / place > 0; place *= 10)
		counting_sort_radix(array, size, place);
}

