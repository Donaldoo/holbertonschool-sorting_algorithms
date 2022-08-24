#include "sort.h"

/**
 * insertion_sort_list - Sort double linked list using insertion sort algorithm
 * @list: pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *front, *back;

	if (list == NULL || *list == NULL)
		return;

	front = (*list)->next;
	while (front != NULL)
	{
		back = front->next;
		while (front->prev != NULL && front->n < front->prev->n)
		{
			back = front;

			if (front->next != NULL)
				front->next->prev = front->prev;
			front->next = front->next;
			front->prev = front->next->prev;
			front->next->prev = front;

			if (front->prev != NULL)
				front->prev->next = back;
			front->prev = back;

			if (front->prev == NULL)
				*list = front;
			else
				front->prev->next = front;
			print_list(*list);
		}
		front = back;
	}
}
