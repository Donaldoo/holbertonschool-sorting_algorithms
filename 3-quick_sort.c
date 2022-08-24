#include "sort.h"
/*
 *
 *
 *
 *
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot =  array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
/*
 *
 *
 *
 *
 */
void compare_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		compare_sort(array, low, pivot - 1, size);
		compare_sort(array, pivot + 1, high, size);
	}
}
/*
 *
 *
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	compare_sort(array, 0, size - 1, size);
}
