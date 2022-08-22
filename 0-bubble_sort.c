#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of the aray
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, tmp;
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
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
				print_array(array, size);
			}
		}
		i--;
	} while (swapped);
}
