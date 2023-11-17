#ifndef S_SORT_H
#define S_SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s ->> doubly linked a list node.
 * @n: Int stored in node.
 * @prev: Pointer to the previous item in the list.
 * @next: Pointer to the next item in the list.
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);

#endif
