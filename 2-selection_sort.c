#include "sort.h"

/**
 * selection_sort ->> Sorts an array of int in ascending the order.
 * @array: Int Array.
 * @size: matrix size.
 **/

void selection_sort(int *array, size_t size)
{
	size_t i, j, s, m;
	int ar, br;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			ar = array[i];
			br = 0;
			for (j = i; j < size ; j++)
			{
				if (array[j] < ar)
				{
					m = j;
					ar = array[j];
					br = 1;
				}
			}
			if (br == 1)
			{
				s = array[i];
				array[i] = array[m];
				array[m] = s;
				print_array(array, size);
			}
		}
	}
}
