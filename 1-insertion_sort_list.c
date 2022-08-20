#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list 
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	swap_nde = (*list)->nxt;
	while (swap_nde != NULL)
	{
		nxt_swap = swap_nde->nxt;
		while (swap_nde->prv != NULL && swap_nde->prv->n > swap_nde->n)
		{
			swap_nde->prv->nxt = swap_nde->nxt;
			if (swap_nde->nxt != NULL)
				swap_nde->nxt->prv = swap_nde->prv;
			swap_nde->nxt = swap_nde->prv;
			swap_nde->prv = swap_nde->nxt->prv;
			swap_nde->nxt->prv = swap_nde;
			if (swap_nde->prv == NULL)
				*list = swap_nde;
			else
				swap_nde->prv->nxt = swap_nde;
			print_list(*list);
		}
		swap_nde = nxt_swap;
	}
}
