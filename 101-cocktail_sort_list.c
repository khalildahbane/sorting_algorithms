#include "sort.h"

/**
 * swap_plus ->> Swap nodes from left to right.
 * @list: list.
 * @_up: Node.
 * @vary: auxiliary node.
 */

void swap_plus(listint_t **list, listint_t *_up, listint_t *vary)
{
	if (_up->prev)
		_up->prev->next = vary;
	else
		*list = vary;
	if (vary->next)
		vary->next->prev = _up;
	_up->next = vary->next;
	vary->prev = _up->prev;
	vary->next = _up;
	_up->prev = vary;
	print_list(*list);
}

/**
 * swap_plus_plus ->> Swaps nodes from right to left.
 * @list: List
 * @_up: _up Node
 * @vary: auxiliar Node
 */

void swap_plus_plus(listint_t **list, listint_t *_up, listint_t *vary)
{
	vary = _up->prev;
	vary->next->prev = vary->prev;
	if (vary->prev)
		vary->prev->next = vary->next;
	else
		*list = vary->next;
	vary->prev = vary->next;
	vary->next = vary->next->next;
	vary->prev->next = vary;
	if (vary->next)
		vary->next->prev = vary;
	print_list(*list);
}

/**
 * cocktail_sort_list -> sorts a doubly linked list of integers
 * @list: List
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *h, *a;
	int b = 1;

	if (list)
	{
		h = *list;
		while (b != 0)
		{
			b = 0;
			while (h->next)
			{
				if (h->n > h->next->n)
				{
					a = h->next;
					swap_plus(list, h, a);
					b = 1;
				}
				else
					h = h->next;
			}
			if (b == 0)
				break;
			b = 0;
			while (h->prev)
			{
				if (h->prev->n > h->n)
				{
					swap_plus_plus(list, h, a);
					b = 1;
				}
				else
					h = h->prev;
			}
		}
	}
}
