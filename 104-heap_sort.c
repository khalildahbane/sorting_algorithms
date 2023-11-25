#include "sort.h"

/**
 * check_tree ->> check tree.
 * @array: int array.
 * @size: matrix size.
 * @size_init: The initial size of the array.
 * @i: Index.
**/

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, num1, num2;
	size_t num4, num3;

	num4 = i * 2 + 1;
	num3 = num4 + 1;
	num1 = array[num4];
	num2 = array[num3];
	if (((num4 < size) && (num3 < size) &&
		(num1 >= num2 && num1 > array[i]))
		|| ((num4 == size - 1) && num1 > array[i]))
	{
		n = array[i];
		array[i] = num1;
		array[num4] = n;
		print_array(array, size_init);
	}
	else if ((num4 < size) && (num3 < size) &&
		(num2 > num1 && num2 > array[i]))
	{
		n = array[i];
		array[i] = num2;
		array[num3] = n;
		print_array(array, size_init);
	}
	if (num4 < size - 1)
		check_tree(array, size_init, size, num4);
	if (num3 < size - 1)
		check_tree(array, size_init, size, num3);
}

/**
 * heap_sort ->> Sorts an array of int in ascending the order.
 * @array: int array.
 * @size: matrix size.
**/

void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int m;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		m = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = m;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}
}
