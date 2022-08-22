#include "sort.h"

/*
 *
 *
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *front, *back;

	front = *list;
	front = front->next;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
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
