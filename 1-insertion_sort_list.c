#include "sort.h"

/**
 * insertion_sort_list - Sort double linked list using insertion sort algorithm
 * @list: pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *front == NULL;
	listint_t *back == NULL;

	front = *list;
	front = front->next;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
<<<<<<< HEAD
=======

	front = (*list)->next;
>>>>>>> 2808655c97da3d129638b39366409b6620870c30
	while (front != NULL)
	{
		while (front->prev != NULL && front->n < front->prev->n)
		{
			back = front;

			if (front->next != NULL)
<<<<<<< HEAD
				front->next->prev = back->prev;
			front->prev->next = back->next;

			front = front->prev;
			back->prev = front->prev;
			back->next = front;
=======
				front->next->prev = front->prev;
			front->next = front->next;
			front->prev = front->next->prev;
			front->next->prev = front;
>>>>>>> 2808655c97da3d129638b39366409b6620870c30

			if (front->prev != NULL)
				front->prev->next = back;
			front->prev = back;

<<<<<<< HEAD
			if (back->prev == NULL)
				*list = back;
=======
			if (front->prev == NULL)
				*list = front;
			else
				front->prev->next = front;
>>>>>>> 2808655c97da3d129638b39366409b6620870c30
			print_list(*list);
			front = front->prev;
		}
		front = front->next;
	}
}
