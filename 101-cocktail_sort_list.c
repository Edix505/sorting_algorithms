#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps a node 
 * @list
 * @node: node
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}


void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (tmp->next != NULL)
		{
			if (tmp->next->a < tmp->a)
			{
				swap(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->a > tmp->a)
			{
				swap(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
