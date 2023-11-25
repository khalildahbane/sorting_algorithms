#include "sort.h"

/**
 * merge_sub_arry_rcv ->> Merges two sub-arrays of the matrix.
 * @array: int array.
 * @size: matrix size.
 * @l: left side of the array.
 * @r: the right side of the array.
 **/

void merge_sub_arry_rcv(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int L, R;

	L = size / 2;
	R = size - L;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, L);
	printf("[right]: ");
	print_array(r, R);

	while (i < L && j < R)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}
	while (i < L)
		array[k++] = l[i++];

	while (j < R)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort -> Sorts an array of integers in ascending order
 * @array: Array Integers
 * @size: Array's size
 **/

void merge_sort(int *array, size_t size)
{
	size_t n = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;
	if (size < 2)
		return;
	n = size / 2;
	for (i = 0; i < n; i++)
		left[i] = array[i];
	for (i = n; i < size; i++)
		right[i - n] = array[i];
	merge_sort(left, n);
	merge_sort(right, size - n);
	merge_sub_arry_rcv(array, left, right, size);
}
