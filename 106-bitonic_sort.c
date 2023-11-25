#include "sort.h"

/**
 * swap ->> Swap two items.
 * @arr: Array.
 * @item_plus: Item one.
 * @item_pluss: The second element.
 * @order: 1 : ascending order , 0 descending order.
 */

void swap(int arr[], int item_plus, int item_pluss, int order)
{
	int i;

	if (order == (arr[item_plus] > arr[item_pluss]))
	{
		i = arr[item_plus];
		arr[item_plus] = arr[item_pluss];
		arr[item_pluss] = i;
	}
}

/**
 * merge ->> Sorts an array of int in ascending order.
 * @arr: Array.
 * @low: Item one.
 * @nelemnt: number of items.
 * @order: 1 : Ascending Order , 0 Descending Order.
 */

void merge(int arr[], int low, int nelemnt, int order)
{
	int n, i;

	if (nelemnt > 1)
	{
		n = nelemnt / 2;
		for (i = low; i < low + n; i++)
			swap(arr, i, i + n, order);
		merge(arr, low, n, order);
		merge(arr, low + n, n, order);
	}
}

/**
 * bitonicsort ->> Sorts an array of int in ascending order.
 * @arr: Array.
 * @low: Item one.
 * @nelemnt: number of items.
 * @order: 1 : Ascending Order , 0 Descending Order.
 * @size: matrix size.
 */

void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int m;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		} m = nelemnt / 2;
		bitonicsort(arr, low, m, 1, size);
		bitonicsort(arr, low + m, m, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort ->> Sorts int array in ascending order.
 * @array: Array.
 * @size: list size.
 */

void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
