#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to the first element of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *unsorted, *sorted_copy, *sorted_copy_prev;

	if (*list)
	{
		sorted = *list;
		unsorted = sorted->next;
		while (unsorted)
		{
			if (unsorted->n < sorted->n)
			{
				node_swap(sorted, unsorted);
				unsorted = unsorted->next;
				sorted = unsorted->prev;
				sorted_copy = sorted;
				sorted_copy_prev = sorted_copy->prev;
				print_list(*list);

				while (sorted_copy_prev && sorted_copy->n < sorted_copy_prev->n)
				{
					node_swap(sorted_copy_prev, sorted_copy);
					if (sorted_copy_prev == *list)
						*list = sorted_copy;
					sorted_copy_prev = sorted_copy->prev;
					print_list(*list);
				}
			}
			sorted = unsorted;
			unsorted = unsorted->next;
		}
	}
}

/**
 * node_swap - swaps nodes in a doubly linked list
 * @sorted: first pointer
 * @unsorted: second pointer
 */
void node_swap(listint_t *sorted, listint_t *unsorted)
{
	sorted->next = unsorted->next;
	unsorted->prev = sorted->prev;
	sorted->prev = unsorted;
	unsorted->next = sorted;
	if (sorted->next)
		sorted->next->prev = sorted;
	if (unsorted->prev)
		unsorted->prev->next = unsorted;
}
