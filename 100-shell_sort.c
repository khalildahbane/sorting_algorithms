#include "sort.h"
#include <stdio.h>

/**
 * shell_sort ->> Sorts an array of int in ascending the order.
 * @array: int Array.
 * @size: matrix size.
 **/

void shell_sort(int *array, size_t size)
{
    int gap = 1;
    while (gap <= size / 3)
    {
        gap = gap * 3 + 1;
    }

    while (gap > 0)
    {
        for (size_t i = gap; i < size; i++)
        {
            int temp = array[i];
            size_t j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        printf("Array after decreasing interval (gap = %d): ", gap);
        print_array(array, size);

        gap = (gap - 1) / 3;

        if (gap == 0)
        {
            break;
        }
    }
}
