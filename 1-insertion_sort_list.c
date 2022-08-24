#include "sort.h"

/**
 * insertion_sort_list - Sort double linked list using insertion sort algorithm
 * @list: pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *temp = NULL;

	current = *list;
	current = current->next;

	if (list == 0 || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current;
			if (current->next != NULL)
				current->next->prev = temp->prev;
			current->prev->next = temp->next;

			current = current->prev;
			temp->prev = current->prev;
			temp->next = current;

			if (current->prev != NULL)
				current->prev->next = temp;
			current->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
			current = current->prev;
		}
		current = current->next;
	}
}
