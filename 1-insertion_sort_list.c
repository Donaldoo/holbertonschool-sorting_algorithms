#include "sort.h"

/**
 * insertion_sort_list - Sort double linked list using insertion sort algorithm
 * @list: pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *front, *back;

	front = *list;

	if (list == NULL || *list == NULL || **list == NULL)
		return;
	front = front->next;
	while (front != NULL)
	{
		while (front->prev != NULL && front->n < front->prev->n)
		{
			back = front;
			if (front->next != NULL)
				front->next->prev = back->prev;
			front->prev->next = back->next;
			front = front->prev;
			back->prev = front->prev;
			back->next = front;
			if (front->prev != NULL)
				front->prev->next = back;
			front->prev = back;
			if (back->prev == NULL)
				*list = back;
			print_list(*list);
			front = front->prev;
		}
		front = front->next;
	}
}
