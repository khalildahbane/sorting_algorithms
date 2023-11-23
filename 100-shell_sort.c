#include "sort.h"

/**
 * shell_sort ->> Sorts an array of int in ascending the order.
 * @array: int Array.
 * @size: matrix size.
 **/

void shell_sort(int *array, size_t size)
{
    size_t kun[1000], k = 0, j = 0, i;
    int m;

    if (!array)
        return;
    while (j * 3 + 1 < size)
    {
        kun[k] = j * 3 + 1;
        j = kun[k++];
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < size; j++)
        {
            if ((j + kun[k - i - 1]) > size - 1)
                break;
            k = j;
            while (array[k] > array[k + kun[k - i - 1]])
            {
		int k;
                m = array[k];
                array[k] = array[k + kun[k - i - 1]];
                array[k + kun[k - i - 1]] = m;
                k = k - kun[k - i - 1];
                if (k < 0)
                    break;
            }
        }
        print_array(array, size);
    }
}
