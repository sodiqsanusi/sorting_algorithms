#include "sort.h"

/**
* insertion_sort_list - Performs an insertion sorting technique on a list
* @list: "listint_t **" The doubly-linked list to be sorted
*
* Return: "void" Nothing
*/
void insertion_sort_list(listint_t **list)
{
	nodePtr current, next, left;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		left = current->prev;
		while (left != NULL && current->n < left->n)
		{
			current->prev = left->prev;
			if (left->prev != NULL)
				left->prev->next = current;
			else
				*list = current;
			left->next = current->next;
			if (current->next != NULL)
				current->next->prev = left;
			current->next = left;
			left->prev = current;
			print_list(*list);
			left = current->prev;
		}
		current = next;
	}
}

