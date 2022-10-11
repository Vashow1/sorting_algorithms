#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t index = 0;
	int temp, temp1 = 0, temp2;

	if (size < 2)
		return;
	if (array == NULL)
		return;
	while (temp1 != -1)
	{
		temp2 = temp1;
		while (array[index] && index < size)
		{
			if (array[index + 1] < array[index] && (index + 1) < size)
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				print_array((const int *)array, size);
				temp1++;
			}
			index++;
		}
		index = 0;
		if (temp2 == temp1)
			temp1 = -1;
	}
}
