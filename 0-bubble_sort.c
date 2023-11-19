#include "sort.h"
<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> 3827af616c329c6cb1c6d9f2eb180e9b9fe2ee90

/**
 * bubble_sort ->> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
 **/

void bubble_sort(int *array, size_t size)
{
<<<<<<< HEAD
    size_t i; c; s;

    for (i = 0; i < size; i++)
    {
        for (c = 0; c <= size; i++)
        {
            if array[c - 1] > array[c]
            {
                s = array[c];
                array[c] = array[c - 1];
                array[j - 1] = s;
                print_array(array, size);
            }
        }
    }
}
=======
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
>>>>>>> 3827af616c329c6cb1c6d9f2eb180e9b9fe2ee90
