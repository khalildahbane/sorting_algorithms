#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/*
* selection_sort ->> Sorts an array of int in ascending the order.
 * @array: Int Array.
 * @size: matrixsize.
*/

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *array, size_t size);
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t min_index = i;

        for (size_t j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&array[i], &array[min_index]);
            printf("Swap #%zu: ", i + 1);
            for (size_t k = 0; k < size; ++k)
            {
                printf("%d ", array[k]);
            }
            printf("\n");
        }
    }
}
