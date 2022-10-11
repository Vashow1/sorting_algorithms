#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, v;
	int Size = (int)size;

	if (array == NULL || size < 2)
		return;

	while (gap < (Size / 3))
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < Size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				v = array[j];
				array[j] = array[j - gap];
				array[j - gap] = v;
				j -= gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
