#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int lowest;
	size_t index = 0, index1, tempindex, flag = 1;

	if (array == NULL || size < 2)
		return;

	while (array[index] && index < size)
	{
		lowest = array[index];
		index1 = index;
		flag = 0;

		while (array[index] && index < size)
		{
			if (array[index] < lowest)
			{
				tempindex = index;
				lowest = array[index];
				flag = 1;
			}
			index++;
		}

		if (flag == 1)
		{
			array[tempindex] = array[index1];
			array[index1] = lowest;
			print_array((const int *)array, size);
		}
		index = index1 + 1;
	}
}
