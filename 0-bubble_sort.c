#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a: int
 * @b: int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of the aray
 */
void bubble_sort(int *array, size_t size)
{
	int i, j;
	bool swapped;

	if (array == NULL || size == 0)
		return;

	do {
		swapped = false;
		j = 0;

		for (i = size - 1; j < i; j++)
		{
			if (array[j + 1] < array[j])
			{
				swap(array + j + 1, array + j);
				swapped = true;
				print_array(array, size);
			}
		}
		i--;
	} while (swapped);
}
