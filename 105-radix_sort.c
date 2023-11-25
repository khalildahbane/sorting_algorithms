#include "sort.h"

/**
 * return_max_val ->> Find the maximum value of the matrix.
 * @array: int array.
 * @size: matrix size.
 * Return: Value Max.
 */

int return_max_val(int *array, size_t size)
{
	int m = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	} return (m);
}

/**
 * radix_sort ->> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
 */

void radix_sort(int *array, size_t size)
{
	int *new;
	int i, max, j = 1;
	int m = size;

	if (!array || size < 2)
		return;
	max = return_max_val(array, size);
	new = malloc(sizeof(int) * size);
	while (max / j > 0)
	{
		int brews[20] = {0};

		i = 0;
		while (i < m)
		{
			brews[(array[i] / j) % 10]++;
			i++;
		}
		if (brews != NULL)
		{
			for (i = 1; i < 10; i++)
				brews[i] += brews[i - 1];

			for (i = m - 1; i >= 0; i--)
			{
				new[brews[(array[i] / j) % 10] - 1] = array[i];
				brews[(array[i] / j) % 10]--;
			}
			for (i = 0; i < m; i++)
				array[i] = new[i];
		} j *= 10;
		print_array(array, size);
	} free(new);
}
