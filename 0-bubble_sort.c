#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort ->> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
 **/

void bubble_sort(int *array, size_t size)
{
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
