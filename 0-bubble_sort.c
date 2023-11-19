#include "sort.h"

/**
 * bubble_sort ->> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, c, s;

	for (i = 0; i < size; i++)
	{
		for (c = 1; c < size - i; c++)
		{
			if (array[c - 1] > array[c])
			{
				s = array[c];
				array[c] = array[c - 1];
				array[c - 1] = s;
				print_array(array, size);
			}
		}
	}
}