#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: Array Integers
 * @size: Array's size
 */

void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	} printf("\n");
}
