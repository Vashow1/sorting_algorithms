#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *output;
	size_t index = 0, i;
	int max = 0, j;
	int *countArray;

	if (array == NULL || size < 2)
		return;
	while (index < size && array[index])
	{
		if (array[index] > max)
			max = array[index];
		index++;
	}

	max++;
	countArray = malloc(sizeof(int) * max);
	output = malloc(sizeof(int) * size);
	if (countArray == NULL || output == NULL)
		return;

	for (j = 0; j <= max && countArray[j]; j++)
		countArray[j] = 0;

	for (i = 0; array[i] && i < size; i++)
		++countArray[array[i]];

	for (j = 1; j <= max - 1; j++)
		countArray[j] += countArray[j - 1];

	 print_array(countArray, max);
	for (j = size - 1; j >= 0; j--)
	{
		output[countArray[array[j]] - 1] = array[j];
		--countArray[array[j]];
	}
	for (i = 0; i < size && array[i]; i++)
		array[i] = output[i];
	free(countArray);
	free(output);
}
