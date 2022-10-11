#include "sort.h"

/**
 * lomuto_partition - a function that executes the
 * lomuto partitioning of an array
 *
 * @array: the array to be partitioned
 * @left: the index of the left most side of the first partition
 * @right: the rightmost index of the second partion
 * @size: the size of the array
 * Return: the value of the partition index
 */

int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right], temp;
	int i = left, j = left;

	while (j < right)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
		++j;
	}
	if (array[i] > pivot)
	{
		temp = array[i];
		array[i] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sort - a function that executes the quick sort on an array
 * by use of lomuto partitioning
 *
 * @array: the array to be partitioned
 * @left: the index of the left most side of the first partition
 * @right: the rightmost index of the second partion
 * @size: the size of the array
 */

void lomuto_sort(int *array, int left, int right, size_t size)
{
	if (left < right)
	{
		int parti = lomuto_partition(array, left, right, size);

		lomuto_sort(array, left, parti - 1, size);
		lomuto_sort(array, parti + 1, right, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array  == NULL || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
