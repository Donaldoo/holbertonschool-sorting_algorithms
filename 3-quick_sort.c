#include "sort.h"
/*
 *
 *
 *
 *
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/*
 *
 *
 *
 *
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = (low - 1);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}
/*
 *
 *
 *
 */
void sort_recursion(int *array,size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		sort_recursion(array, size, low, pi - 1);
		sort_recursion(array, size, pi + 1, high);
	}
}

/**
 * 
 *
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_recursion(array, size, 0, size - 1);
}
