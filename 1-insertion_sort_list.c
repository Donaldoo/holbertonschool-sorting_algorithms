#include "sort.h"

/**
 * insertion_sort_list - Sort double linked list using insertion sort algorithm
 * @list: pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;


	if (list == 0)
		return;

	current = *list;
	while (current != NULL)
	{
		while (current->next != NULL && current->n < current->prev->n)
		{
			temp = current->next;
			current->next = temp->next;
			temp->prev = current->prev;
			if (current->prev)
				current->prev->next = temp;

			if (temp->next)
				temp->next->prev = current;
			current->prev = temp;
			temp->next = current;

			if (temp->prev)
				current = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
