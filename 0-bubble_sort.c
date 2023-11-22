#include "sort.h"

/**
 * bubble_sort ->> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, s;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				s = array[j];
				array[j] = array[j - 1];
				array[j - 1] = s;
				print_array(array, size);
			}
		}
	}
}
