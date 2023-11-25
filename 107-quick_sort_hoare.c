#include "sort.h"

/**
*swap_p ->> swap two itmes.
*@array: Array.
*@item_plus: Element one.
*@item_pluss: Element tow.
*/

void swap_p(int *array, ssize_t item_plus, ssize_t item_pluss)
{
	int i;

	i = array[item_plus];
	array[item_plus] = array[item_pluss];
	array[item_pluss] = i;
}

/**
 *hoare_partition_p ->> Hore division scheme.
 *@array: Array.
 *@first: The first array element
 *@last: The last array element
 *@size: matrix size.
 *Return: position.
 */

int hoare_partition_p(int *array, int first, int last, int size)
{
	int a = first - 1, b = last + 1;
	int p = array[last];

	while (1)
	{
		do {
			a++;
		} while (array[a] < p);
		do {
			b--;
		} while (array[b] > p);
		if (a >= b)
			return (a);
		swap_p(array, a, b);
		print_array(array, size);
	}
}

/**
 *qs_p ->> Quicksort algorithm
 *@array: Array
 *@first: Element one.
 *@last: Element tow.
 *@size: matrix size.
 */

void qs_p(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t p = 0;

	if (first < last)
	{
		p = hoare_partition_p(array, first, last, size);
		qs_p(array, first, p - 1, size);
		qs_p(array, p, last, size);
	}
}

/**
 *quick_sort_hoare ->> Sorts an array of int in ascending order.
 *@array: Array.
 *@size: matrix size.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs_p(array, 0, size - 1, size);
}
