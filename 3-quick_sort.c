#include "sort.h"

/**
 * quick_sort_rec -> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
 * @array_init: raw matrix.
 * @size_init: The size of the initial matrix.
 **/

void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size)
{
	size_t j, g;
	int br;
	int i = -1, n, m = array[size - 1];

	if (array && size > 1)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] < m)
			{
				i++;
				g = i;
				if (g != j && array[j] != array[g])
				{
					n = array[j];
					array[j] = array[i];
					array[i] = n;
					print_array(array_init, size_init);
				}
			}
		} br = size;
		if (br - 1 != i + 1 && array[br - 1] != array[i + 1])
		{
			array[size - 1] = array[i + 1];
			array[i + 1] = m;
			print_array(array_init, size_init);
		}
		if (i > 0)
		{
			quick_sort_rec(array_init, size_init, array, i + 1);
		} quick_sort_rec(array_init, size_init, array + i + 2,  size - (i + 2));
	}
}

/**
 * quick_sort ->> Sorts an array of int in ascending the order.
 * @array: int Array.
 * @size: matrix size.
**/

void quick_sort(int *array, size_t size)
{
	int *_arrays;
	size_t _sizes;

	if (array)
	{
		_arrays = array;
		_sizes = size;
		quick_sort_rec(_arrays, _sizes, array, size);
	}
}

