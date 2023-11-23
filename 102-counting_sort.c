#include "sort.h"

/**
 * counting_sort ->> Sorts int array in ascending the order.
 * @array: int Array.
 * @size: matrix size.
 **/

void counting_sort(int *array, size_t size)
{
	int n, j, *m, *c;
	size_t i;

	if (!array || size < 2)
		return;
	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	} c = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		c[array[i]]++;
	}
	for (j = 1; j < n; j++)
	{
		c[j + 1] += c[j];
	} print_array(c, n + 1);
	m = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		c[array[i]]--;
		m[c[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = m[i];
	} free(m);
	free(c);
}
